
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
int nb=0;
int pid_m;
int x=0;

void catchCtrlC()
{
    kill(pid_m,SIGUSR1);

}

int main(int argc,char * argv[])
{
    int arg=atoi(argv[1]);
    int dp;
    printf("\nMinuteur n° %d\n",arg);
    int Heure, Minute, Seconde;
    printf("\nEntrez heure ? ");
    scanf("%d", &Heure);
    printf("\nEntrez Minute ? ");
    scanf("%d", &Minute);
    printf("\nEntrez Seconde ? ");
    scanf("%d", &Seconde);
    x = conversion(Heure,Minute,Seconde);//Heure/3600 + Minute/60 + Seconde
    char temps[10];
    printf("\n   Minuteur crée pour : %d secondes\n",x);
    sprintf(temps,"%d",x);
    pid = fork();
    unlink("pipm"); // fermeture au cas ou
    mkfifo("pipm",0750); // création du pipe 
    signal(SIGINT, catchCtrlC);

    if(pid == 0)
    {
        char *args[] = {"MinF", argv[1],temps , NULL};
        execl("/usr/bin/xterm","xterm","-T","Affichage Minuteur","-e","./MinF",args[1],args[2],NULL);
    }
        
    sleep(1);
    dp=open("pipm",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
    nb=read(dp,&pid_m,4);
    close(dp);

    printf("   Appuyer sur ctrl C pour arreter le minuteur\n");
    getchar();
    
    signal(SIGINT, SIG_DFL);

    dp=open("pipm",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père et att temps restant au fils
    nb=read(dp,&x,4);
    close(dp);
    
    printf("   BIP ! BIP ! BIP ! Il restait %d secondes\n",x);
    system("play pan.wav");
    printf("   Appuyer sur ctrl C pour fermer le minuteur ou fermeture auto apres 1 minute\n");
    sleep(60);
    return 0;
   
}

int conversion( int h, int m, int s)
{
    int res, a=h , b=m , c=s;
    a=a*3600;
    b=b*60;
    res = a+b+c;
    return res;
    
}
