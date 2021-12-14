#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room
{
    int room_type_id[10];
    int room_type_name[10];
    int room_type_price[10];
};

struct customer
{
    int customer_id[10];
    char customer_name[255];
    int customer_age[10];
    char customer_cause_of_death[255];
    char customer_resting_place[255];
    int customer_died_year[10];
    room p;
};




void add_user(){}
void read_data(){
    
}
void update(){}
void remove(){}
void menu(){
    int ch;

    do{
    printf("Hotel del jojo");
    printf("\n");
    printf("\n1. Add new customer");
    printf("\n2. Read data");
    printf("\n3. Update data");
    printf("\n4. Remove data");
    printf("\n5. Exit");
    printf("\n");

    printf("\nChoice [1-5] >> ");
    scanf("%d", &ch);

    switch(ch){
        case 1:
        add_user();
        break;
        case 2:
        read_data();
        break;
        case 3:
        update();
        break;
        case 4:
        remove();
        break;

    }

    }while(ch != 5);
}
int main(){
    menu();

    return 0;
}