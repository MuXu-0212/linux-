#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#define SHM_SIZE 1024
int main() {
    int shmid, semid, pid, status;
    char *shm_ptr;
    struct sembuf sembuf;
    // 创建共享内存
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }
    // 创建信号量
    semid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget error");
        exit(1);
    }
    // 初始化信号量
    semctl(semid, 0, SETVAL, 0);
    pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        // 子进程
        shm_ptr = shmat(shmid, NULL, 0);
        if (shm_ptr == (void *)-1) {
            perror("shmat error");
            exit(1);
        }
        // 写入共享内存
        sprintf(shm_ptr, "Hello, world!");
        // 释放共享内存
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt error");
            exit(1);
        }
        // 发送信号量
        sembuf.sem_num = 0;
        sembuf.sem_op = 1;
        sembuf.sem_flg = 0;
        semop(semid, &sembuf, 1);
        exit(0);
    } else {
        // 父进程
        pid = fork();
        if (pid == -1) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            // 子进程
            shm_ptr = shmat(shmid, NULL, 0);
            if (shm_ptr == (void *)-1) {
                perror("shmat error");
                exit(1);
            }
            // 读取共享内存
            printf("Message: %s\n", shm_ptr);
            // 释放共享内存
            if (shmdt(shm_ptr) == -1) {
                perror("shmdt error");
                exit(1);
            }
            // 发送信号量
            sembuf.sem_num = 0;
            sembuf.sem_op = 1;
            sembuf.sem_flg = 0;
            semop(semid, &sembuf, 1);
            exit(0);
        } else {
            // 父进程
            // 等待子进程退出
            waitpid(pid, &status, 0);
            // 删除共享内存
            if (shmctl(shmid, IPC_RMID, NULL) == -1) {
                perror("shmctl error");
                exit(1);
            }
            // 删除信号量
            if (semctl(semid, 0, IPC_RMID, 0) == -1) {
                perror("semctl error");
                exit(1);
            }
            exit(0);
        }
    }
    return 0;
}