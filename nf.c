#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TimeHandler.h"
#include <sqlite3.h>
#define TARGET_TIME 1509994820
#define SECONDS_PER_DAY 86400

void printDefaultInfo(){
	printf("Current time: %s", getTimeInString(0));
	printf("Target time: %s", getTimeInString(TARGET_TIME));
	printf("Seconds left: %ld\n", TARGET_TIME-time(NULL));
}

void handleArg(char arg);

void handleArgs(int argc, char** argv) {
	switch(argc){
		case 1:
			printDefaultInfo();
			break;
		case 2:
			if(argv[1][0] == '-'){
				handleArg(argv[1][1]);
			}
			break;

		default:
			printf("NFTimer don't know how to handle this yet\n");

	}
}

void handleArg(char arg) {
	switch(arg){
		case 'd':
			printf("Difference: %ld\n", TARGET_TIME-time(NULL));
			break;
		case 'D':
			printf("Difference in days %ld\n", (TARGET_TIME-time(NULL))/SECONDS_PER_DAY);
			break;
		default:
			printf("No such command\n");
	}
}


int main(int argc, char** argv) {
	handleArgs(argc, argv);
	printf("%s\n", sqlite3_libversion()); 
	return 0;
}
