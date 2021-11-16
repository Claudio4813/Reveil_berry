#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

float now=0;
int dp;

void top(int sig)
{

    dp=open("pipo",O_WRONLY) ; // Ouverture du pipe en ecriture
    write(dp, &now ,4);
    close(dp);
}

void fin(int sig)
{
    printf("Fin du chrono %d\n",sig);
    exit(0);
}


int main(int argc,char * argv[]){

    int pidf=getpid();
    int arg=atoi(argv[1]);
    dp=open("pipo",O_WRONLY) ; // Ouverture du pipe en ecriture
    write(dp, &pidf ,4);
    close(dp);

    signal(SIGUSR1,top); // lancement du top des reception du signal 10
    signal(SIGUSR2,fin); // lancement de la fermeture du programme

    while(1)
    {
        printf("\nCa compte des secondes avec une précision de dizieme de seconde: %.2f",now);
        printf("\nAffichage du chronomètre n° %d",arg);
    	usleep(100000);
        now=now+0.1;
    	system("clear"); //pour terminal systeme linux
        // manière pas optimum car au fur et à mesure du temps on en perds à l'execution du code
        // Il faudrait utiliser l'horloge systeme et calculer la diff pour afficher le temps ecouler
    }
}

