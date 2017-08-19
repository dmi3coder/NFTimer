#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TARGET_TIME 1509994820
char *datetime(time_t timeToPrint) {
    char *array = (char*)malloc(sizeof(char)*25);
    time_t result;
    if( timeToPrint != 0 ) {
        result = timeToPrint;
    } else {
	result = time(NULL);
    }
    //long targetTime = TARGET_TIME;
    //result = time(&targetTime);
    //result = TARGET_TIME;
    sprintf(array, "%s", asctime(localtime(&result)));
    array[25] = '\0';
    return array;
}

int main(int argc, char** argv) {
	printf("Current time: %s", datetime(0));
	printf("Target time: %s", datetime(TARGET_TIME));
	printf("Seconds left: %ld\n", TARGET_TIME-time(NULL));
	return 0;
}
