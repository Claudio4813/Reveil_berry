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


int main(int argc,char * argv[]){

    char c='a';
    char temps1[20]="";
    char temps2[20]="";
    char temps3[20]="";
    
    int nb=0;
    int dp;
    
    int pid_c;

    unlink("pipo"); // fermeture au cas ou
    mkfifo("pipo",0750); // création du pipe 


    int pid = fork(); // creation Fille

    /*
        if (pid==0) system("gnome-terminal -e ./affchro");  //utilisation de system pas bien et pas vu en cours
        execv pas reussi a bien utiliser pour lancer l'executable dans un nouveau terminal
        de plus cela ne permet plus de bien gerer le PID du FILS 
    */


    if (pid==0) 
    {
        pid_c=getpid();
        printf("pidc=%d\n",pid_c);
        execl("/usr/bin/xterm","xterm","-e","./affchro",NULL); // utilisation de execl
    }

    
    while(c!='q')
    {
        //system("clear");
        printf("\nAppuyer sur 't' pour enregistrer un temps intermediaire ");
        printf("\n'q' pour quitter ");
        printf("\n\n\nTemps intermediaire 1 : %s",temps1);
        printf("\nTemps intermediaire 2 : %s",temps2);
        printf("\nTemps intermediaire 3 : %s\n",temps3);

        printf("cnt = :%d\n",cnt);
        printf("pid fils = :%d\n",pid_c);
        printf("pid fils vu du pere = :%d\n",pid);
        scanf("%s",&c);
        

        if (c=='q')
            {
                printf("Fermeture du chronometre\n");
                sleep(3);
                kill(pid,SIGUSR2); // envoie a la fille le signal 12 
                exit(0);
            }

        if (c=='t')
        {
            
            printf("Boucle intermediaire\n");
            sleep(3);
            kill(pid,SIGUSR1); // Envoi à la fille le signal 10
            
            switch (cnt)
            {
                case 1:
                    //dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    //nb=read(dp,temps1,20);
                    temps1[nb]='\0';
                    cnt++;
                    printf("\n\n\nTemps intermediaire 1 : %s",temps1);
                    //close(dp);
                break;
                case 2:
                    //dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    //nb=read(dp,temps2,20);
                    temps2[nb]='\0';
                    cnt++;
                    printf("\nTemps intermediaire 2 : %s",temps2);
                    //close(dp);
                break;
                case 3:
                    //dp=open("pipo",O_RDONLY) ; // ouverture du fichier pipe en READ pour le père
                    //nb=read(dp,temps3,20);
                    temps3[nb]='\0';
                    cnt++;
                    printf("\nTemps intermediaire 3 : %s",temps3);
                    //close(dp);
                break;
                default: printf("Linux for ever\n");
            }
        }        
        getchar();
    }
    unlink("pipo");
    kill(pid,SIGUSR2); // envoie a la fille le signal 12 
    //exit(0);
}
