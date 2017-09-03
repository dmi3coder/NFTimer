#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TimeHandler.h"
#include "Database.h"

#define TARGET_TIME 1511373003
#define SECONDS_PER_DAY 86400

void printDefaultInfo(){
    printf("Current time: %s", getTimeInString(0));
    printf("Target time: %s", getTimeInString(TARGET_TIME));
    printf("Seconds left: %ld\n", TARGET_TIME-time(NULL));
}

void handleArg(char arg, char* second_arg);

void handleArgs(int argc, char** argv) {
    switch(argc){
        case 1:
            printDefaultInfo();
            break;
	case 2:
	case 3:
            if(argv[1][0] == '-'){
                handleArg(argv[1][1],argv[2]);
            }
            break;       
        default:
            printf("NFTimer don't know how to handle this yet\n");
            
    }
}

void handleArg(char arg, char* second_arg) {
    switch(arg){
	case 'a':{
		time_t targetTime;
		if( second_arg != NULL ) {
	            targetTime = strtol(second_arg, NULL, 10);
		} else {
		    targetTime = time(0);
		}
		targetTime += SECONDS_PER_DAY*90;
	        setTime(targetTime);
		 }
	    break;
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
    start();
    handleArgs(argc, argv);
    return 0;
}
