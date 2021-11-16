#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void temps();
void quit(int);
int cnt=1;
int nb=0;

int main(int argc,char * argv[]){

    int arg=atoi(argv[1]);
    char c='a';
    float temps1=0,temps2=0,temps3=0,tempsend=0;
    
    int dp,statut;
    
    int pid_c;

    unlink("pipo"); // fermeture au cas ou
    mkfifo("pipo",0750); // création du pipe 


    int pid = fork(); // creation Fille

    if (pid==0) 
    {
        execl("/usr/bin/xterm","xterm","-T","Affichage Chronometre","-e","./affchro",argv[1],NULL); // utilisation de execl
    }

    
    sleep(1);
    dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
    nb=read(dp,&pid_c,4);
    close(dp);
    
    while(c!='q')
    {
        system("clear");
        printf("\nChronomètre n° %d",arg);
        printf("\nAppuyer sur 't' pour enregistrer un temps intermediaire ");
        printf("\n'q' pour quitter ");
        printf("\n\n\nTemps intermediaire 1 : %.2f\n",temps1);
        printf("\nTemps intermediaire 2 : %.2f\n",temps2);
        printf("\nTemps intermediaire 3 : %.2f\n",temps3);
        printf("\nTemps final : %f\n",tempsend);

        scanf("%s",&c);
        

        if (c=='q')
            {
                printf("Fermeture du chronometre\n");
                kill(pid_c,SIGUSR2); // envoie a la fille le signal 12 
                wait(&statut);
                exit(0);
            }

        if (c=='t')
        {
            
            printf("Boucle intermediaire\n");
            kill(pid_c,SIGUSR1); // Envoi à la fille le signal 10
            
            switch (cnt)
            {
                case 1:
                    dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    nb=read(dp,&temps1,4);
                    cnt++;
                    close(dp);
                break;
                case 2:
                    dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    nb=read(dp,&temps2,4);
                    cnt++;
                    close(dp);
                break;
                case 3:
                    dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    nb=read(dp,&temps3,4);
                    cnt++;
                     close(dp);
                break;
                case 4:
                    dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    nb=read(dp,&tempsend,4);
                    cnt++;

                    close(dp);
                    kill(pid_c,SIGUSR2); // envoie a la fille le signal 12 
                break;

                default: printf("Linux for ever\n");
            }
        }        
        getchar();
    }
    unlink("pipo");
    kill(pid_c,SIGUSR2); // envoie a la fille le signal 12 

}
