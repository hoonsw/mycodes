#include <stdio.h>
#include <string.h>
#include <mysql.h>
//#include <my_global.h>  // this is not necessary in 8.0

int main(int argc, char* argv[])
{
  MYSQL *conn = mysql_init(NULL);
  if(argc < 2){
    printf("Usage : < sql file >\n");
    return 0;
  }

  if (conn==NULL){
      printf("mysql_init: %s\n", mysql_error(conn));
      exit(1);
  }

  if(mysql_real_connect(conn, "localhost", "bnam", "changethis", "dbbnam", 0, NULL, 0)==NULL){
      printf("mysql_real_connect: %s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  FILE* fp = fopen(argv[1], "r");
  char sqlquery[1000] = {0};
  while(!feof(fp)){
    fgets(sqlquery, sizeof(sqlquery), fp);
    if(mysql_query(conn, sqlquery)){
        printf("mysql_query: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if(result == NULL){
        printf("mysql_store_result: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for(int i=0; i<num_fields; i++){
            printf (" %s ", row[i]? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    memset(sqlquery, 0, sizeof(sqlquery));

  }
  fclose(fp);
  mysql_close(conn);

  return 1;
}
