#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>

void seminfo(int semid) { // print last change, and last operation on semaphore
  struct semid_ds sem_ds;
  union semun arg;
  arg.buf = &sem_ds;
  if (semctl(semid, 0, IPC_STAT, arg) == -1) {
    perror("semctl");
    exit(1);
  };

  printf("Semaphore ID: %d\n", semid);
  printf("Last change time: %ld\n", sem_ds.sem_ctime);
  printf("Last operation time: %ld\n", sem_ds.sem_otime);
  printf("Number of semaphores: %hu\n", sem_ds.sem_nsems);
  for(int semnum = 0; semnum < sem_ds.sem_nsems; semnum++){
      printf("Semaphore Number: %d\n", semnum);
      printf("Semaphore value: %d\n", semctl(semid, semnum, GETVAL));
  }
  printf(
      "Number of semaphores waiting for the semaphore value to increase: %d\n",
      semctl(semid, 0, GETNCNT));
  printf(
      "Number of semaphores waiting for the semaphore value to decrease: %d\n",
      semctl(semid, 0, GETZCNT));
}

int main() {
  int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0600);
  if (semid == -1) {
    perror("semget");
    exit(1);
  }

  struct sembuf sops[1];
  sops[0].sem_num = 0;
  sops[0].sem_op = 1;
  sops[0].sem_flg = 0;

  if(  semop(semid, sops, 1) == -1){
    perror("semop");
    exit(1);
  }

  seminfo(semid);

  semctl(semid, 0, IPC_RMID, 0);
  return 0;
}
