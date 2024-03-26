#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

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
                    // message.msg_value = (rand() % 2 == 0) ? message.msg_value : message.msg_value - 1;
                    double random_number = (double)rand() / (double)RAND_MAX;
                    if (random_number < 0.5)
                    {
                        message.msg_value--;
                        printf("Child process PID %d decremented message value to %d\n", getpid(), message.msg_value);
                    }
                    else
                    {
                        printf("Child process PID %d decided not to decrement message value\n", getpid());
                    }

                    msgsnd(msg_id, &message, sizeof(message), 0);
                }
                // Check if there are no messages for 1 second
                sleep(1);
            }
        }
    }

    // Wait for all children to terminate
    for (size_t i = 0; i < children_num; i++)
    {
        wait(NULL);
    }

    // Remove message queue after all children have terminated
    msgctl(msg_id, IPC_RMID, NULL);
}
