#include <stdio.h>
#include <stdlib.h>
int main(){

    FILE * testing;
    testing = fopen("customer_data.txt", "r");
    char singleLine[150];
    while(!feof(testing)){
        fgets(singleLine, 150, testing);
        puts(singleLine);
    }

    fclose(testing);




    return 0;
}