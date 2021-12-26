Room *createRoom(char _name[], int _price)
{
  Room *newRoom = (Room *)malloc(sizeof(Room));
  strcpy(newRoom->type_name, _name);
  newRoom->type_price = _price;

  totalRoom += 1;
  newRoom->id = totalRoom;
  return newRoom;
}