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
    sleep(5);
    printf("top\n");
    printf("now=%f\n",now);
    sleep(5);
    //dp=open("pipo",O_WRONLY) ; // Ouverture du pipe en ecriture
    //write(dp, &now ,20);
    //close(dp);
}

void fin(int sig)
{
    printf("Fin du chrono");
    exit(0);
}


int main(int argc,char * argv[]){

    int pidf=getpid();
    printf("PID affchro %d\n",pidf);
    sleep(15);
    signal(SIGUSR1,top); // lancement du top des reception du signal 10
    signal(SIGUSR2,fin); // lancement de la fermeture du programme


boucle:
    while(1)
    {

        printf("\nCa compte des secondes avec une précision de dizieme de seconde: %.2f",now);
    	usleep(100000);
        now=now+0.1;

    	//system("clear"); //pour terminal systeme linux
        // manière pas optimum car au fur et à mesure du temps on en perds à l'execution du code
        // Il faudrait utiliser l'horloge systeme et calculer la diff pour afficher le temps ecouler
    }
printf("avant boucle\n");
sleep(4);
goto boucle;
printf("après boucle\n");
sleep(4);
}

