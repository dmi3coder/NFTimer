#include <stdio.h>
#include <stdint.h>
#include <sqlite3.h>
#include <sys/stat.h>
#include "Database.h"
#define TARGET_TIME 1511115356
#define TARGET_TIME_STRING "1511115356"
char *CREATE_TABLE = 	"DROP TABLE IF EXISTS nf_time;"
"CREATE TABLE nf_time(id INTEGER PRIMARY KEY, name TEXT, time INT);";


void start() {
    printf("%s\n", sqlite3_libversion());
    sqlite3 *db;
    sqlite3_stmt *res;
    mkdir("/usr/local/share/nf", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    int rc = sqlite3_open("/usr/local/share/nf/nf.db", &db);
    if(rc == SQLITE_OK) {
        printf("DATABASE OPEN\n");
    }
    char* error_msg = 0;
    rc = sqlite3_exec(db, CREATE_TABLE, 0, 0, &error_msg);
    if( rc == SQLITE_OK) {
        printf("Database created\n");
    }
    
    rc = sqlite3_exec(db, "INSERT INTO nf_time(name,time) VALUES('main', "TARGET_TIME_STRING");",0,0,&error_msg);
    if( rc != SQLITE_OK){
        printf("error: %s",error_msg);
    }
    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
    rc = sqlite3_step(res);
    printf("%s\n", sqlite3_column_text(res,0));
}


