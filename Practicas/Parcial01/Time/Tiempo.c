#include <time.h>

int main()
{

    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    printf("Current local time and date: %s\n", asctime(info));
    printf("Time: %i:%i:%i\n", info->tm_hour, info->tm_min, info->tm_sec);
    return (0);
}