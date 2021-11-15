
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int arg=atoi(argv[1]);
    printf("\nReveil n° %d",arg);
    char c='a';
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
    utm.tm_hour = heure;
    utm.tm_min = minute;
    
    while(c!='q')
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        time_t now;
        time(&now);
        printf("\nReveil n° %d",arg);
        printf("\nl'heure est : %s",ctime(&now));
        sleep(1);
        system("clear");
        if((tm.tm_hour == utm.tm_hour)&&(tm.tm_min == utm.tm_min))
        {
            printf("\n BIP BIP BIP il est %dh%d", heure, minute);
            printf("\n Pour arreter le reveil, taper q\n");
            scanf("%s", &c);
            getchar();
        }

    }
    return 0;
}
