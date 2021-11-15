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
    
    printf("\n ---- BIENVENUE DANS VOTRE REVEIL ---- \n");
    while(1)
    {
        time_t now;
        time(&now);
        printf("\nl'heure est : %s",ctime(&now));
        sleep(1);
       // system("clear"); //pour terminal systeme linux
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
                   printf("1- Créer une alarme \n");
                   printf("2- Supprimer une alarme \n");
                   printf("3- Afficher les alarmes \n");
                int i = 0;
                 printf("Quel est votre choix? \n\n");
                 scanf("%d", &i);
                switch(i){
                 case 1:
                     printf("\n\nchoix 1 du sous menu Réveil \n\n");
                       execv("/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/reveil",NULL);
                        //execl("/Users/bin/xterm", "xterm", "-e", "/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/reveil", NULL);
                     break;
                 case 2:
                     printf("\n\nchoix 2 du sous menu Réveil \n\n");
                     break;
                 case 3:
                     printf("\n\nchoix 3 du sous menu Réveil \n\n");
                     break;
                 default:
                     printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                     break;
                }
                break;
             case 2:
                 printf("Vous avez choisi le Chronomètre \n\n");
                   printf("1- Lancer le chronomètre \n");
                   printf("2- Arrêter le chronomètre \n");
                   printf("3- Mettre en pause le chronomètre \n");
                 printf("Quel est votre choix? \n\n");
                 scanf("%d", &i);
                switch(i){
                 case 1:
                     printf("\n\nchoix 1 du sous menu Chronomètre \n\n");
                     break;
                 case 2:
                     printf("\n\nchoix 2 du sous menu Chronomètre \n\n");
                     break;
                 case 3:
                     printf("\n\nchoix 3 du sous menu Chronomètre \n\n");
                     break;
                 default:
                     printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                     break;
                }
                break;
             case 3:
                 printf("Vous avez choisi le Minuteur \n\n");
                   printf("1- Lancer le minuteur \n");
                   printf("2- Parametrer le minuteur \n");
                   printf("3- Mettre en pause le minuteur \n");
                 printf("Quel est votre choix? \n\n");
                 scanf("%d", &i);
                 switch(i){
                 case 1:
                         
                     printf("\n\nchoix 1 du sous menu Minuteur \n\n");
//                         int x=0;
//                         char temps[10];
//                         scanf("%d", &x);
//                         char *argv[3];
//                         sprintf(temps, "%d", x);
//                         argv[0]= "exo1M";
//                         argv[1]= temps;
//                         argv[2]= NULL;
                     
                        // system("xterm -e ./Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/exo1M");
                       //  execl("/usr/bin/gnome-terminal","gnome-terminal","--","./affchro",NULL); IL FAUT RAJOUTER LE BON FICHIER ET LE BON TERMINAL
                         execv("/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/MinP", NULL);
                    break;
                 case 2:
                     printf("\n\nchoix 2 du sous menu Minuteur \n\n");
                     break;
                 case 3:
                     printf("\n\nchoix 3 du sous menu Minuteur \n\n");
                     break;
                 default:
                     printf("Vous n'avez pas rentre un chiffre correct.\n\n");
                     break;
                 }
             break;
               case 4:
                   printf("Vous avez choisi Statistiques\n\n");
                   printf("1- Afficher les statistiques \n");
                   printf("2- Supprimer les statistiques \n");
                   printf("Quel est votre choix? \n\n");
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
