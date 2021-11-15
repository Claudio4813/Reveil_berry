
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

int pid;
int conversion(int h, int m, int s);

void catchCtrlC()
{
    kill(pid,SIGUSR1);
}

int main(int argc,char * argv[])
{
    int Heure, Minute, Seconde, x;
    printf("Entrez heure ? ");
    scanf("%d", &Heure);
    printf("Entrez Minute ? ");
    scanf("%d", &Minute);
    printf("Entrez Seconde ? ");
    scanf("%d", &Seconde);
    x = conversion(Heure,Minute,Seconde);//Heure/3600 + Minute/60 + Seconde
    char temps[10];
    printf("\n   Minuteur créer pour : %d secondes",x);
    printf("\n   Envoie du compteur");
    printf("\n   Lancement de ma fille\n");
    sprintf(temps,"%d",x);
    pid = fork();
    if(pid == 0)
    {
        char *args[] = {"MinF", temps , NULL};
        execv("/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/MinF",args);
    }
        sleep(1);
        signal(SIGINT, catchCtrlC);
       wait(&x); // Att que la tache fille se termine proprement et renvoi les secondes restantes
       printf("   BIP ! BIP ! BIP ! Il restait %d secondes\n", x>>8);
    

    
}

int conversion( int h, int m, int s)
{
    int res, a=h , b=m , c=s;
    a=a*3600;
    b=b*60;
    res = a+b+c;
    return res;
    
}
