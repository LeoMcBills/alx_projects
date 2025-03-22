#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t t;
    struct tm *tm_info;

    while (1) {
        time(&t);
        tm_info = localtime(&t);

        printf("\rCurrent Time: %02d:%02d:%02d", 
               tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}

