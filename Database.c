#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <dirent.h>
#include <sys/stat.h>
#include "Database.h"
#include <string.h>
#define TARGET_TIME 1511373003
#define TARGET_TIME_STRING "1511373003"
char *CREATE_TABLE = "DROP TABLE IF EXISTS nf_time;"
"CREATE TABLE nf_time( id INTEGER PRIMARY KEY, name TEXT, time INTEGER);";

struct db_holder db_create(DIR *dir);

struct db_holder {
    sqlite3* db;
    char* error_msg;
};
static struct db_holder holder;

void start() {
    DIR* dir = opendir("/usr/local/share/nf");
    if(!dir){
        printf("No database, creating\n");
        mkdir("/usr/local/share/nf", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        holder = db_create(dir);
    }
}

struct db_holder db_create(DIR *dir) {
    struct db_holder holder;
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc = sqlite3_open("/usr/local/share/nf/nf.db", &db);
    holder.db = db;
    
    
    if(rc == SQLITE_OK) {
        printf("DATABASE OPEN\n");
    }
    holder.error_msg = 0;
    rc = sqlite3_exec(db, CREATE_TABLE, 0, 0, &(holder.error_msg));
    if( rc == SQLITE_OK) {
        printf("Database created\n");
    }
    
    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
    rc = sqlite3_step(res);
    printf("%s\n", sqlite3_column_text(res,0));
    return holder;
}

bool setTime(time_t time){
    int rc = 0;
    char sqlPrefix[80];
    strcpy(sqlPrefix, "INSERT INTO nf_time VALUES(0,\"test\",");
    char execString[100];
    sprintf(execString," %s %ld);",sqlPrefix, time);
    char** error_msg;
    rc = sqlite3_exec(holder.db, execString, 0, 0, error_msg);
    if( rc != SQLITE_OK){
        printf("error: %s",error_msg[0]);
	return false;
    }
    return true;
    
}
