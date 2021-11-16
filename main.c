//
//  main.c
//  OSProject
//
//  Created by Arnaud Souquiere on 29/10/2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char *argv[])
{
  int choix;
  int cpt_chro=0;
  int cpt_rev=0;
  int cpt_min=0;
  char chrono[10];
  char reveil[10];
  char minuteur[10];
  system("clear"); //pour terminal systeme linux
    printf("\n ---- BIENVENUE DANS VOTRE REVEIL_BERRY ---- \n");
    while(1)
    {
        time_t now;
        time(&now);
        printf("\nl'heure est : %s",ctime(&now));
        printf("1- Réveil  \n");
        printf("2- Chronomètre \n");
        printf("3- Minuteur \n");
        printf("4- Statistiques \n");
        printf("5- Monitoring \n");
        printf("0- Quitter le menu \n");
        printf("\n\nQuel est votre choix? ");
        scanf("%d", &choix);

        printf("\n");
        switch (choix)
            
           {
             case 1:
             		printf("Vous avez choisi le Réveil\n\n");
             		cpt_rev ++;
             		sprintf(reveil, "%d", cpt_rev);
             		argv[1]= reveil;
             		int pid_r = fork(); // creation FilS
		      	if (pid_r==0) 
   			{
        			execl("/usr/bin/x-terminal-emulator", "x-terminal-emulator","-T","Reveil","-e", "./reveil",argv[1],NULL); // utilisation de execl
    			}

                break;
             case 2:
             		printf("Vous avez choisi le Chronomètre \n\n");
             		cpt_chro ++;
             		sprintf(chrono, "%d", cpt_chro);
             		argv[2]= chrono;
             		int pid_c = fork(); // creation FilS
		      	if (pid_c==0) 
   			{
        			execl("/usr/bin/x-terminal-emulator", "x-terminal-emulator","-T","Chronometre","-e", "./chrono",argv[2],NULL); // utilisation de execl
    			}
    			break;
             case 3:
             		printf("Vous avez choisi le Minuteur \n\n");
             		cpt_min ++;
             		sprintf(minuteur, "%d", cpt_min);
             		argv[3]= minuteur;
             		int pid_m = fork(); // creation FilS
		      	if (pid_m==0) 
   			{
        			execl("/usr/bin/x-terminal-emulator", "x-terminal-emulator","-T","Minuteur","-e", "./MinP",argv[3],NULL); // utilisation de execl
    			}
    			break;
               case 4:
                   printf("Vous avez choisi Statistiques\n\n");
                   printf("1- Afficher les statistiques \n");
                   printf("2- Supprimer les statistiques \n");
                   printf("Quel est votre choix? \n\n");
                   int i=0;
                   scanf("%d", &i);
                   switch(i){
                   case 1:
                       printf("\n\nchoix 1 du sous menu Statistiques\n\n");
                       break;
                   case 2:
                       printf("\n\nchoix 2 du sous menu Statistiques\n\n");
                       break;
                   default:
                       printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                       break;
                   }
             break;
               case 5:
                   printf("Vous avez choisi le Monitoring \n\n");
                   printf("1- Afficher la consommation de ressources nécessaires \n");
                   printf("2- Réinitialiser la consommation de ressources nécessaires \n");
                   printf("3- xxxx \n");
                   printf("Quel est votre choix? \n\n");
                   scanf("%d", &i);
                   switch(i){
                   case 1:
                       printf("\n\nchoix 1 du sous menu Monitoring\n\n");
                       break;
                   case 2:
                       printf("\n\nchoix 2 du sous menu Monitoring \n\n");
                       break;
                   case 3:
                       printf("\n\nchoix 3 du sous menu Monitoring \n\n");
                       break;
                   default:
                       printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                       break;
                   }
             break;
               case 0:
                   return 0;
                   break;
             default:
                printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                break;

    }

 
}


  return 0;
}
