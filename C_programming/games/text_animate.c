#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    printf("Loading: [");
    fflush(stdout);
    
    for (i = 0; i <= 50; i++) {
        printf("#");
        fflush(stdout);
        usleep(100000); // 0.1 seconds
    }

    printf("] Done!\n");
    return 0;
}

