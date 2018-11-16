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
    time_t now;
    struct tm *info;

    // data hoje com gmt -2 (horario de verao)
    now = time(NULL) - (2 * 60 * 60);

    info = gmtime(&now);
    printf("%2d/%2d/%2d - Hora = %2d Minutos = %2d\n", (info->tm_mday),(info->tm_mon),(info->tm_year),(info->tm_hour),(info->tm_min));

    // data daqui 5 dias - 24 horas - 60 minutos - 60 segundos
    now = now + (5 * 24 * 60 * 60);
    info = gmtime(&now);
    printf("Dia entrega = %2d", (info->tm_mday));

    return 0;  
}
