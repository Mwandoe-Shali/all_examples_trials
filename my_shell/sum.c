#include <stdio.h>
#include <unistd.h>

int main ()
{
    int i, j, k, sum;
    i = 45;
    j = 56;
    k = 43;
    
    sum = (i + j + k);

    pid_t pid;

    printf("The sum of the numbers is %d\n", sum);

    pid = getpid();
    printf("The pid is: %u\n", pid);

    return (0);

}

