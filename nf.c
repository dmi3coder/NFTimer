#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TimeHandler.h"
#define TARGET_TIME 1509994820


void printDefaultInfo(){
	printf("Current time: %s", getTimeInString(0));
	printf("Target time: %s", getTimeInString(TARGET_TIME));
	printf("Seconds left: %ld\n", TARGET_TIME-time(NULL));
}

void handleArgs(int argc, char** argv) {
	switch(argc){
		case 1:
			printDefaultInfo();
			break;
		default:
			printf("NFTimer don't know how to handle this yet\n");

	}
}


int main(int argc, char** argv) {
	handleArgs(argc, argv);
	return 0;
}
