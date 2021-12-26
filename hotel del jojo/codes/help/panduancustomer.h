
Costumer *create(char _name[], int _age, char _cod[], char _rp[], int _diedyear, int _roomid)
{
  Costumer *newCostumer = (Costumer *)malloc(sizeof(Costumer));
  strcpy(newCostumer->name, _name);
  newCostumer->age = _age;
  strcpy(newCostumer->cause_of_death, _cod);
  strcpy(newCostumer->resting_place, _rp);
  newCostumer->died_year = _diedyear;
  newCostumer->room_id = _roomid;

  totalCustomer += 1;
  newCostumer->id = totalCustomer;
  
  return newCostumer;
}

void read(Costumer *s)
{
  printf("==================\n");
  printf("ID : C%03d\n", s->id);
  printf("Name : %s\n", s->name);
  printf("Age : %d\n", s->age);
  printf("Cause of death : %s\n", s->cause_of_death);
  printf("Resting Place : %s\n", s->resting_place);
  printf("Died year : %d\n", s->died_year);
  printf("Room Type ID : R%03d\n", s->room_id);
  printf("==================\n");
}

void remove(Costumer *s)
{
  free(s);
  s = NULL;
}

void update(Costumer *s, int _roomId)
{
  s->room_id = _roomId;
}

void readAll()
{
  printf("| %-3s | %-5s | %-10s | %-5s | %-10s |\n", "", "ID", "Name", "Age", "Room");
  printf("| %-3s | %-5s | %-10s | %-5s | %-10s |\n", "---", "-----", "----------", "-----", "----------");

  for (int i = 0; i < totalCustomer; i++)
  {

    printf("| %-3d | C%03d  | %-10s | %-5d | %-10s |\n", i + 1,
           costumerList[i]->id, costumerList[i]->name,
           costumerList[i]->age,
           roomList[costumerList[i]->room_id - 1]->type_name);
  }
}