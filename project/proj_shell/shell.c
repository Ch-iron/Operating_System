#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_SIZE 99

int main(int argc, char* argv[])
{
        FILE* fp = NULL;
        char buf1[MAX_SIZE];
        char* buf2[MAX_SIZE];
        char* buf3[MAX_SIZE];
        char* token;
        int i, j, k, a, mode;
        int cnt[MAX_SIZE];
        pid_t chpid[MAX_SIZE], pid;
        //mode decide
        if(argc > 1)
        {
                mode = 0;
                fp = fopen(argv[1],"r");
        }
        else
        {
                mode = 1;
                fp = stdin;
        }
        while(1)
        {
                int proccnt = 0;
                if(mode == 1)
                {
                        printf("prompt> ");
                }
                if(fgets(buf1, MAX_SIZE, fp) == NULL)
                        break;
                if(strncmp(buf1, "quit\n", 5) == 0)
                {
                        break;
                }
                buf1[strlen(buf1) - 1] = '\0';
                if(mode == 0)
                        printf("%s\n", buf1);
                //first tokenizing
                token = strtok(buf1,";");
                i = 0;
                while(token != NULL)
                {
                        buf2[i] = token;
                        proccnt++;
                        token = strtok(NULL, ";");
                        i++;
                }
                //second tokenizing
                buf2[i] = NULL;
                k = 0;
                for(j = 0 ; buf2[j] != NULL ; j++)
                {
                        token = strtok(buf2[j]," ");
                        while(token != NULL)
                        {
                                buf3[k] = token;
                                token = strtok(NULL, " ");
                                k++;
                        }
                        buf3[k] = NULL;
                        cnt[0] = 0;
                        cnt[j + 1] = k + 1;
                        k++;
                }
                //fork
                for(a = 0 ; a < proccnt ; a++)
                {
                        pid = fork();
                        if(pid < 0)
                        {
                                printf("error fork\n");
                        }
                        else if(pid > 0)
                        {
                                chpid[a] = pid;
                        }
                        else if(pid == 0)
                        {
                                execvp(buf3[cnt[a]], &buf3[cnt[a]]);
                                printf("error command\n");
                                exit(0);
                        }
                }
                for(a = 0 ; a < proccnt ; a++)
                {
                        waitpid(chpid[a], NULL, 0);
                }

        }
        if(mode == 0)
        {
                fclose(fp);
        }
        return 0;
}
