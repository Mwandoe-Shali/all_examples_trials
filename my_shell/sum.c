#include <stdio.h>
#include <unistd.h>

int main ()
{
    int i, j, k, sum;
    pid_t pid;
    i = 45;
    j = 56;
    k = 43;
    
    sum = (i + j + k);
    
    printf("The sum of the numbers is %d\n", sum);

    pid = getpid();
    printf("The pid is: %u\n", pid);

    return (0);

}

