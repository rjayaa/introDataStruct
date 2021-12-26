struct Room
{
  int id;
  char type_name[255];
  int type_price;
};

struct Costumer
{
  int id;
  char name[255];
  int age;
  char cause_of_death[255];
  char resting_place[255];
  int died_year;
  int room_id;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int totalCustomer = 0;
int totalRoom = 0;
Costumer *costumerList[255];
Room *roomList[255];

#include "panduancustomer.h"
#include "panduanroom.h"

void Menu();
void ReadData();
int getId(char str[]);
void AddNewCostumer();
int Validation(char str[]);
void UpdateData();
void RemoveData();
int NameValidation(char str[]);
void Exit();

void LoadCostumer()
{
  FILE *pfile = fopen(".//hotel del jojo//costumer//costumer_data.txt", "r");
  while (!feof(pfile))
  {
    char id[5];
    char name[255];
    int age;
    char cause_of_death[255];
    char resting_place[255];
    int died_year;
    char room_id[5];

    int idConverted, roomIdConverted;
    fscanf(pfile, "%[^,],%[^,],%d,%[^,],%[^,],%d,%[^\n]\n", id,
           name, &age, cause_of_death, resting_place, &died_year, room_id);

    roomIdConverted = getId(room_id);
    Costumer *newCostumer;
    newCostumer = create(name, age, cause_of_death, resting_place, died_year, roomIdConverted);
    costumerList[totalCustomer - 1] = newCostumer;
  }
  fclose(pfile);
}

void LoadRoom()
{
  FILE *pfile = fopen(".//hotel del jojo/room/room.txt", "r");
  while (!feof(pfile))
  {
    char temp[255];
    char name[255];
    int price;

    fscanf(pfile, "%[^,],%[^,],%d\n", temp, name, &price);
    Room *newRoom;
    newRoom = createRoom(name, price);
    roomList[totalRoom - 1] = newRoom;
  }
}

int main()
{
  LoadCostumer();
  LoadRoom();
  Menu();
}

void Menu()
{
  system("clear");
  int option;
  printf("Hotel del Jojo\n");
  printf("1. Add new costumer\n");
  printf("2. Read data\n");
  printf("3. Update data\n");
  printf("4. Remove data\n");
  printf("5. Exit\n");

  printf("\nChoice [1-5] ");

  do
  {
    printf(">> ");
    scanf("%d", &option);
    getchar();
  } while (option < 1 || option > 5);
  switch (option)
  {
  case 1:
    AddNewCostumer();
    break;
  case 2:
    ReadData();
    break;
  case 3:
    UpdateData();
    break;
  case 4:
    RemoveData();
    break;
  case 5:
    Exit();
    break;
  }
}

void Exit()
{
  system("clear");
  printf("\n\n\n");
  char logo[255];
  FILE *gambar = fopen("./img/exit.txt", "r");
  while (fscanf(gambar, "%[^\n]\n", logo) != EOF)
  {
    printf("\t%s\n", logo);
  }
  FILE fclose(*gambar);
  printf("\n\n\n");
}

void RemoveData()
{
  char tempRoomType[20];
  int optionid;
  system("clear");
  readAll();

  int validation = -1;

  do
  {
    char temp[10];
    printf("\nEnter ID: ");
    scanf("%s", temp);
    getchar();
    optionid = getId(temp);
  } while (optionid < 1 || optionid > totalRoom);

  remove(costumerList[optionid - 1]);

  printf("Remove Succed! [press enter]");
  getchar();
  Menu();
}

void UpdateData()
{

  char tempRoomType[20];
  int optionid;
  system("clear");
  readAll();

  int validation = -1;

  do
  {
    char temp[10];
    printf("\nEnter ID: ");
    scanf("%s", temp);
    getchar();
    optionid = getId(temp);
  } while (optionid < 1 || optionid > totalRoom);
  do
  {
    printf("Insert New Room (Pantai, Rooftop, Taman, Bar): ");
    scanf("%s", tempRoomType);
    getchar();
    validation = Validation(tempRoomType);
  } while (validation == -1);

  update(costumerList[optionid - 1], validation);

  printf("Update Succed! [press enter]");
  getchar();
  Menu();
}

void AddNewCostumer()
{
  system("clear");
  char tempName[255];
  int tempAge;
  char tempCauseOfDeath[1000];
  char tempRestPlace[1000];
  char tempRoomType[1000];
  int tempDiedYear;

  int validationFlag = -1;
  int tempLength = 0;
  int validationName = -1;

  do
  {
    printf("Name (lowercase letters): ");
    scanf("%[^\n]", tempName);
    getchar();
    validationName = NameValidation(tempName);
  } while (validationName == -1);

  do
  {
    printf("Age (0 - 100): ");
    scanf("%d", &tempAge);
    getchar();
  } while (tempAge < 0 || tempAge > 100);

  do
  {
    printf("Cause of Death (max 255 letters): ");
    scanf("%[^\n]", tempCauseOfDeath);
    getchar();
    tempLength = strlen(tempCauseOfDeath);
  } while (tempLength < 0 || tempLength > 255);

  tempLength = 0;

  do
  {
    printf("Resting Place (max 255 letters): ");
    scanf("%[^\n]", tempRestPlace);
    getchar();
    tempLength = strlen(tempRestPlace);
  } while (tempLength < 0 || tempLength > 255);
  tempLength = 0;
  do
  {
    printf("Died year : ");
    scanf("%d", &tempDiedYear);
    getchar();
  } while (tempDiedYear < 0 || tempDiedYear > 2021);

  do
  {
    printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
    scanf("%s", tempRoomType);
    getchar();
    validationFlag = Validation(tempRoomType);
  } while (validationFlag == -1);
  printf("\nWelcome to Hotel del Jojo! [press enter]");
  getchar();

  Costumer *newCostumer;
  newCostumer = create(tempName, tempAge, tempCauseOfDeath, tempRestPlace, tempDiedYear, validationFlag);
  costumerList[totalCustomer - 1] = newCostumer;

  Menu();
}

int NameValidation(char str[])
{
  int length = strlen(str);
  for (int i = 0; i < length; i++)
  {
    if (str[i] < 97 || str[i] > 122)
    {
      return -1;
    }
  }
  return 1;
}

int Validation(char str[])
{
  for (int i = 0; i < totalRoom; i++)
  {
    if (strcmp(str, roomList[i]->type_name) == 0)
    {
      return i + 1;
    }
  }
  return -1;
}

void ReadData()
{
  system("clear");

  readAll();
  printf("\nBack to menu ? [press enter]");
  getchar();
  Menu();
}

int getId(char str[])
{

  if (str[1] == '0')
  {
    if (str[2] == '0')
    {
      return (int)str[3] - '0';
    }
    else
    {
      int hasil = 0;
      int temp;
      temp = str[2] - '0';
      hasil += temp;
      temp = 10 * (str[3] - '0');
      hasil += temp;
      return hasil;
    }
  }
  else
  {
    int hasil = 0;
    int temp;
    temp = str[1] - '0';
    temp = 10 * (str[2] - '0');
    hasil += temp;
    hasil += temp;
    temp = 100 * (str[3] - '0');
    hasil += temp;
    return hasil;
  }
}