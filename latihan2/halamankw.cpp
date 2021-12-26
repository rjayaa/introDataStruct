// C program to Open a File,
// Write in it, And Close the File
 
# include <stdio.h>
# include <string.h>
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
 void import_data_from_file(){
     FILE * fp;
     fp  = fopen("")
 }
int main( )
{
 

    return 0;       
}