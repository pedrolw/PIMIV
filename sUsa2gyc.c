#include <stdio.h>  
#include <time.h>  

// struct tm {
//    int tm_sec;         /* seconds,  range 0 to 59          */
//    int tm_min;         /* minutes, range 0 to 59           */
//    int tm_hour;        /* hours, range 0 to 23             */
//    int tm_mday;        /* day of the month, range 1 to 31  */
//    int tm_mon;         /* month, range 0 to 11             */
//    int tm_year;        /* The number of years since 1900   */
//    int tm_wday;        /* day of the week, range 0 to 6    */
//    int tm_yday;        /* day in the year, range 0 to 365  */
//    int tm_isdst;       /* daylight saving time             */	
// };

int main() 
{  
    time_t retirada;
    struct tm info_entrega;

    // data hoje com gmt -2 (horario de verao)
    retirada = time(NULL) - (2 * 60 * 60);
    
    info_entrega = *localtime(&retirada);
    
    // 25/11/2017
    info_entrega.tm_yday = 2017;
    info_entrega.tm_mon = 11 - 1;
    info_entrega.tm_mday = 25;
    info_entrega.tm_hour = 13;
    info_entrega.tm_min = 50;

    double segundos = difftime(mktime(&info_entrega),retirada);


    printf("Dias = %f\n", (segundos/(60 * 60 * 24)));
    printf("Horas = %f\n", (segundos/(60 * 60)));

    return 0;  
}