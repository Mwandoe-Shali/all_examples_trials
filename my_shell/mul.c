#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 5;
    int j = 4;
    int mul = (i * j);

    pid_t ppid;
    
    printf("The result of multiplication is %d\n", mul);

    ppid = getppid();
    printf("The ppid for this process is %u\n", ppid);

    return (0);
}

