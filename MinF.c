#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

int nbSec;
int delai=0;

void end()
{
    //printf("Renvoi %d\n", delai);
    exit(delai);
}

int main(int argc, char* argv[])
{
    printf("\n     Debut du minuteur \n");
    delai=atoi(argv[1]);
    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1,end);
    while (delai > 0)
    {
        printf(" Temps Restant : %d\n", delai);
        sleep(1);
        delai--;
    }
    return 0;
}

