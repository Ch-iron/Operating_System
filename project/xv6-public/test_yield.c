#include "types.h"
#include "stat.h"
#include "user.h"


int main()
{
    int pid;
    pid = fork();
    while(1)
    {
        if(pid == 0)
        {
            write(1, "Child\n", 6);
            yield();
        }
        else if(pid > 0)
        {
            write(1, "Parent\n", 7);
            yield();
        }
        else
        {
            write(1, "Error\n", 6);
            yield();
        }
    }
    return 0;
}

