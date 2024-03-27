#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h> // needed on linux, but not on MacOS.
#include <errno.h>

#define MAX_MSG_SIZE 100

struct msg_buffer
{
  long msg_type;
  int msg_value;
} message;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <children_num> <max_value>\n", argv[0]);
    exit(1);
  }

  pid_t child_pid;
  int status, children_num, number;

  if ((children_num = strtol(argv[1], NULL, 10)) <= 0)
  {
    fprintf(stderr, "Unable to read <num_procs> from argv[1]\n");
    exit(1);
  }
  if ((number = strtol(argv[2], NULL, 10)) <= 0)
  {
    fprintf(stderr, "Unable to read <init_range> from argv[2]\n");
    exit(1);
  }

  /* Create message queue */
  int msg_id = msgget(IPC_PRIVATE, 0600);
  if (msg_id == -1)
  {
    perror("msgget");
    exit(1);
  }

  /* Init the sequence */
  srand(getpid());
  message.msg_type = 1;
  message.msg_value = rand() % number + 1;
  msgsnd(msg_id, &message, sizeof(message) - sizeof(long), 0);

  for (int i = 1; i <= children_num; i++)
  { // Create children
    pid_t pid = fork();
    if (pid == -1)
    { // Error
      perror("fork");
      exit(1);
    }
    else if (pid == 0) // Child
    {
      srand(getpid()); /* Initialize a different seed per child */
      while (1)        /* Loop forever: terminated by SIGALRM */
      {
        alarm(1); /* Set alarm to 1 second */

        /* Receive message */
        msgrcv(msg_id, &message, sizeof(message) - sizeof(long), i, 0);

        /* Handle the message */
        if (message.msg_value == 0)
        { /* Child terminates */
          printf("PID=%d (CHILD %d): received 0, TERMINATING\n", getpid(), i);
          exit(i);
        }
        else
        { // Send message to next child
          printf("PID=%d (CHILD %d): received %d, ", getpid(), i, message.msg_value);
          // Change message type to next child or 1 if it is the last child
          message.msg_type = (message.msg_type == children_num) ? 1 : message.msg_type + 1;

          // Randomly decrement message value with 50% probability
          message.msg_value = (rand() % 2 == 0) ? message.msg_value : message.msg_value - 1;

          printf("sent %d\n", message.msg_value);
          msgsnd(msg_id, &message, sizeof(message) - sizeof(long), 0);
        }
      }
    }
  }

  /* Wait for the child processes termination */
  while ((child_pid = wait(&status)) != -1)
  {
    printf("PID= %5d (PARENT): Child with PID=%d terminated with status 0x%04X\n",
           getpid(), child_pid, status);
  }
  if (errno != ECHILD)
  {
    fprintf(stderr, "wait returned -1, but NOT ECHILD... Need to be investigated\n");
  }

  // Remove message queue after all children have terminated
  msgctl(msg_id, IPC_RMID, 0);
}
