/* Giovanni ibarra
   Dr_T's COSC-1437
   4/25/2020
   Program: Menu Items header
*/

#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include "Input_Validation_Extended.h"
#include <vector>
#include <fstream>

int orderCount = 0; 
time_t result = time(&result);

class MenuItem
{
  private:
    string name;
    double itemCost;
    string desc;
    char addLetter;
    char removeLetter;
    int count;
  public:
    MenuItem()
    {
      count = 0;
    }
    void setName(string n) {name = n;}
    void setItemCost(double ic) {itemCost = ic;}
    void setDesc(string d) {desc = d;}
    void setAddLetter(char al) {addLetter = al;}
    void setRemoveLetter(char rl) {removeLetter = rl;}
    void setICount (){count = 0;}
    void setCount(int c) {count += c;}

    string getName() const {return name;}
    double getItemCost() const {return itemCost;}
    string getDesc() const {return desc;}
    char getAddLetter() const {return addLetter;}
    char getRemoveLetter() const {return removeLetter;}
    int getCount() const {return count;}
};
#endif