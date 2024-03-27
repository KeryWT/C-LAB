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

  int children_num = atoi(argv[1]);              // Number of children
  srand(time(NULL));                             // Seed for random number generator
  int random_value = rand() % atoi(argv[2]) + 1; // Generate random number between 1 and max_number

  key_t key = ftok("hot-potato-msg.c", 65);
  if (key == -1)
  {
    perror("ftok");
    exit(1);
  }

  int msg_id = msgget(key, 0666 | IPC_CREAT);
  if (msg_id == -1)
  {
    perror("msgget");
    exit(1);
  }

  //send first message
  message.msg_type = 1;
  message.msg_value = random_value;
  msgsnd(msg_id, &message, sizeof(message), 0);

  for (int i = 0; i < children_num; i++)
  { // Create children
    pid_t pid = fork();
    if (pid == -1)
    { // Error
      perror("fork");
      exit(1);
    }
    else if (pid == 0)
    { // Child
      while (1)
      {
        alarm(1); // Set alarm to 1 second

        // Receive message
        msgrcv(msg_id, &message, sizeof(message), message.msg_type, 0);

        // Handle the message
        if (message.msg_value == 0)
        { // Child terminates
          printf("Child process terminated: PID %d\n", getpid());
          exit(0);
        }
        else
        { // Send message to next child
          printf("Child process PID %d received message with value %d\n", getpid(), message.msg_value);
          // Change message type to next child or 1 if it is the last child
          message.msg_type = (message.msg_type == children_num) ? 1 : message.msg_type + 1;

          // Randomly decrement message value with 50% probability
          message.msg_value = (rand() % 2 == 0) ? message.msg_value : message.msg_value - 1;

          printf("sent %d\n", message.msg_value);
          msgsnd(msg_id, &message, sizeof(message), 0);
        }
      }
    }
  }
  pid_t child_pid;
  int status;
	/* Wait for the child processes termination */
	while ((child_pid = wait(&status)) != -1) {
		printf("PID= %5d (PARENT): Child with PID=%d terminated with status 0x%04X\n",
		       getpid(), child_pid, status);
	}
	if (errno != ECHILD) {
		fprintf(stderr,"wait returned -1, but NOT ECHILD... Need to be investigated\n");
	}

  // Remove message queue after all children have terminated
  msgctl(msg_id, IPC_RMID, 0);
}
