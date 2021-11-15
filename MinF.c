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
int numero=0;
int dp;

void end()
{
    dp=open("pipm",O_WRONLY) ; // Ouverture du pipe en ecriture
    write(dp, &delai ,4);
    close(dp);
    exit(0);
}

int main(int argc, char* argv[])
{
    int pidf=getpid();
    dp=open("pipm",O_WRONLY) ; // Ouverture du pipe en ecriture
    write(dp, &pidf ,4);
    close(dp);
    numero=atoi(argv[1]);
    printf("\n     Debut du minuteur N° %d\n",numero);
    delai=atoi(argv[2]);
    signal(SIGINT, SIG_IGN);
    signal(SIGUSR1,end);
    while (delai > 0)
    {
        printf("\nMinuteur N° %d\n",numero);
        printf(" Temps Restant : %d\n", delai);
        sleep(1);
        system("clear");
        delai--;
    }
    return 0;
}

