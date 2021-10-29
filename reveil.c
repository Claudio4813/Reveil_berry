#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


//void reveil(int);

int main(int argc,char * argv[]){


    
    /*int alarme1,alarme2,alarme3;
    alarme1=atoi(argv[1]);
    alarme2=atoi(argv[2]);
    alarme3=atoi(argv[3]);
    signal(SIGALRM,reveil);
    alarm(alarme1);
    alarm(alarme2);
    alarm(alarme3);
    */
    printf("\nAttente de l'alarme\n");	
    while(1)
    {
    	time_t now; //
		time(&now);
    	printf("\nl'heure est : %s",ctime(&now));
    	sleep(1);
    	system("clear"); //pour terminal systeme linux
    }

    
}

/*
void reveil(int sig) {
    printf("\nALARME !! ca sonne !! C'est l'heure !!\n");
    // Commande d'alarme RASPBERRY

    //
    kill(getppid(),SIGUSR1);
    exit(0);
}*/