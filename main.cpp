//Giovanni Ibarra
//4/25/2020
//DR_T's COSC-1437
//Unit 5 Assignment
//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019 -> converted to class objects

#include "Functions.h"

int main() 
{
  vector<MenuItem> objectMenu;
  char input = '\0';
  
  populateMenu(objectMenu);

  do
  {
    repopulateMenu(objectMenu);
    cout << cClear;
    showMenu(objectMenu);
    acceptOrder(objectMenu);
    cout << "\n\n\nPress any key to begin new order (press X or x to exit)\n";
    validateChar(input);
  }while (input != 'x' && input !='X');

  cout << cClear << "\n\nBye!";
  return 0;
}