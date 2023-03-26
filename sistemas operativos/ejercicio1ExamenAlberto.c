#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    pid_t child_pid, wpid;
    int status;

    for (int i = 0; i < 2; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        { /* fork() failed */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        { /* This is the child */
            /* Child does some work and then terminates */
            if (i == 0)
            {
                printf("Soy el [HIJO 1] con pid %ld y mi padre tiene pid %ld\n", (long int)getpid(), (long int)getppid());
                exit(EXIT_SUCCESS);

            }

            if (i == 1)
            {
                child_pid = fork();
                if (child_pid == -1)
                { /* fork() failed */
                    perror("fork");
                    exit(EXIT_FAILURE);
                }

                if (child_pid == 0)
                {
                    printf("Soy el [NIETO] con pid %ld y mi padre tiene pid %ld\n", (long int)getpid(), (long int)getppid());
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    printf("Soy el [HIJO 2] con pid %ld y mi padre tiene pid %ld\n", (long int)getpid(), (long int)getppid());
                    do
                    {
                        wpid = waitpid(child_pid, &status, WUNTRACED
#ifdef WCONTINUED /* Not all implementations support this */
                                                               | WCONTINUED
#endif
                        );
                        if (wpid == -1)
                        {
                            perror("waitpid");
                            exit(EXIT_FAILURE);
                        }

                        if (WIFEXITED(status))
                        {
                            printf("child exited con pid %ld, status=%d\n", (long int) getpid(),WEXITSTATUS(status));
                        }
                        else if (WIFSIGNALED(status))
                        {
                            printf("child killed (signal %d)\n", WTERMSIG(status));
                        }
                        else if (WIFSTOPPED(status))
                        {
                            printf("child stopped (signal %d)\n", WSTOPSIG(status));

#ifdef WIFCONTINUED /* Not all implementations support this */
                        }
                        else if (WIFCONTINUED(status))
                        {
                            printf("child continued\n");
#endif
                        }
                        else
                        { /* Non-standard case -- may never happen */
                            printf("Unexpected status (0x%x)\n", status);
                        }
                    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
                }
                exit(EXIT_SUCCESS);

            }
        }
        else
        {
            do
            {
                wpid = waitpid(child_pid, &status, WUNTRACED
#ifdef WCONTINUED /* Not all implementations support this */
                                                       | WCONTINUED
#endif
                );
                if (wpid == -1)
                {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                }

                if (WIFEXITED(status))
                {
                    printf("child exited con pid %ld, status=%d\n", (long int) getpid(),WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status))
                {
                    printf("child killed (signal %d)\n", WTERMSIG(status));
                }
                else if (WIFSTOPPED(status))
                {
                    printf("child stopped (signal %d)\n", WSTOPSIG(status));

#ifdef WIFCONTINUED /* Not all implementations support this */
                }
                else if (WIFCONTINUED(status))
                {
                    printf("child continued\n");
#endif
                }
                else
                { /* Non-standard case -- may never happen */
                    printf("Unexpected status (0x%x)\n", status);
                }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    printf("Soy el [PADRE] con pid %ld\n", (long int)getpid());
    printf("Me muero...\n");
    exit(EXIT_SUCCESS);
}