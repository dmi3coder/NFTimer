#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *getTimeInString(time_t timeToPrint) {
	    char *array = (char*)malloc(sizeof(char)*25);
	        time_t result;
		if( timeToPrint != 0 ) {
	        	result = timeToPrint;
		} else {
			result = time(NULL);
		}
		sprintf(array, "%s", asctime(localtime(&result)));
                array[25] = '\0';
		return array;
}

int getDaysDiff(time_t startTime, time_t targetTime){
	return 0;
}
