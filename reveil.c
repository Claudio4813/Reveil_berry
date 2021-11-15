//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <time.h>
//
//int main(void)
//{
//    time_t secondes;
//       struct tm instant;
//
//        time(&secondes);
//        instant=*localtime(&secondes);
//
//    char hour[3], min[3], sec[3];
//    sprintf(hour, "%d",instant.tm_hour);
//    sprintf(min, "%d",instant.tm_min);
//      sprintf(sec, "%d",instant.tm_sec);
//
//    char *argv[8];
//    argv[0] = "reveil_alarm";
//    argv[1] = hour;
//    argv[2] = min;
//    argv[3] = sec;
//    argv[7] = NULL;
//
//    printf("\n\n==== Bienvenue sur dans le reveil ====\n\n");
//
//    printf("Il est %s:%d:%d\n\n ", hour, instant.tm_min, instant.tm_sec);
//
//    printf("Saisir une heure de réveil :\n ");
//    printf("Saisir l\'heure : ");
//    scanf("%s", hour);
//    printf("Saisir la minute  : ");
//    scanf("%s", min);
//    printf("Saisir la seconde : ");
//    scanf("%s", sec);
//
//    argv[4] = hour;
//    argv[5] = min;
//    argv[6] = sec;
//    printf("%s\n", argv[1]);
//    printf("%s\n", argv[4]);
//
//    int E, A;
//
//    A = fork();
//
//    if(A == 0)
//    {
//        E = fork();
//        if(E == 0)
//        {
//            execv("/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/reveil_alarm", argv);
//        }
//        else
//        {
//            execv("/Users/arnaud/Documents/ITII/ITII 2022/OS/Projet/reveil_entr", NULL);
//        }
//    }
//    wait(NULL);
//    return 0;
//}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now;
    time(&now);
    printf("\nl'heure est : %s",ctime(&now));
    time_t ut = time(NULL);
    struct tm utm = *localtime(&ut);
    int heure, minute;
    printf("------Reveil------\n\n");
    printf("\nentrez une heure : ");
    scanf("%d", &heure);
    printf("\nentrez la minute : ");
    scanf("%d", &minute);
    getchar();
    utm.tm_hour = heure;
    utm.tm_min = minute;
    
    while(1)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if((tm.tm_hour == utm.tm_hour)&&(tm.tm_min == utm.tm_min))
        {
            printf("BIP BIP BIP il est %d : %d", heure, minute);
            return 0;
        }

    }
    return 0;
}
