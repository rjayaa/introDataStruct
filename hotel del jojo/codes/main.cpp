#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <ctype.h>
#include <cctype>
struct room
{
   char room_type_id[10];
   char room_type_name[10];
   char room_type_price[10];
};

struct Customer
{
    char customer_id[10];
    char customer_name[255];
    int customer_age[10];
    char customer_cause_of_death[255];
    char customer_resting_place[255];
    int customer_died_year[10];
    room p;
};

Customer* create(const char *room_type_id,const char *room_type_name,const char *room_type_price,const char *customer_id, const char *customer_name, const char *customer_cause_of_death, const char *customer_resting_place, int customer_age, int customer_died_year){
    Customer *new_cust =(Customer*)malloc(sizeof(Customer));
    strcpy(new_cust->customer_name,customer_name);
    *new_cust -> customer_age = customer_age;
    strcpy(new_cust->customer_id,customer_id);
    strcpy(new_cust->customer_cause_of_death,customer_cause_of_death);
    strcpy(new_cust->customer_resting_place, customer_resting_place);
    strcpy(new_cust->p.room_type_id,room_type_id);
    return new_cust;
}


 void add_user(){
    Customer *s;
    FILE *fp;
    int n;
    int i = 0;
    s=(Customer*)malloc(sizeof(Customer));
    fp = fopen("data_mur.txt", "w");
    do{
    printf("Name (lowercase letters): ");
    fscanf(fp,"%s\n", s->customer_name);
    }while(s->customer_name[i] != tolower(s->customer_name[i]));
    
    do{
        printf("Age (0 - 100): ");
        fscanf(fp,"%d", &s->customer_age);
    }while(*s->customer_age >= 100);

    printf("Cause of Death (max 255 letters): ");
    fscanf(fp,"%s", s->customer_cause_of_death);
    printf("Resting Place (max 255 letters): ");
    fscanf(fp,"%s", s->customer_resting_place);
    getchar();
        char pantai[101] = {"Pantai"};
        char rooftop[101] = {"Rooftop"};
        char taman[101] = {"Taman"};
        char bar[101] = {"Bar"};
    do{
        printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
        fscanf(fp,"%s", s->p.room_type_name);
    }while(s->p.room_type_name[i] != pantai[i] &&s->p.room_type_name[i] != rooftop[i] && s->p.room_type_name[i] != taman[i]&& s->p.room_type_name[i] != bar[i]);
    fwrite(&s,sizeof(Customer),1,fp);
    fclose(fp);
 }
void read_data(){
    FILE *ff;
    ff = fopen("data_mur.txt", "r");
    char singleLine[300];
    while(!feof(ff)){
        fgets(singleLine,300,ff);
        puts(singleLine);
    }
    fclose(ff);
}
void update(){}
void remove(){}

int main(){
    int ch;

    do{
    printf("Hotel del jojo");
    printf("\n");
    printf("\n1. Add new customer");
    printf("\n2. Read data");
    printf("\n3. Update data");
    printf("\n4. Remove data");
    printf("\n0. Exit");
    printf("\n");

    printf("\nChoice [1-5] >> ");
    scanf("%d", &ch);
    getchar();
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
    }while(ch != 0);

    return 0;
}