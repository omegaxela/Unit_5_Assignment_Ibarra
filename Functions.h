/* Giovanni ibarra
   Dr_T's COSC-1437
   4/25/2020
   Program: Funtions header
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Menu_Item.h"
#include <ctime>
#include <unistd.h>



//POPULATE MENU **************************************************
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Agua de Jamaica", "Horchata" , "Tacos De Asada", "Quesadilla", "Torta al Pastor", "Enchilladas", "Menudo"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost((2.00 + i)); //set a random starter cost for each item
    entireMenu[i].setDesc("yum"); //set all default desc to "delicous"
    entireMenu[i].setICount();
  }
  entireMenu[0].setDesc("Hibiscus Tea");
  entireMenu[1].setDesc("Rice based Drink");
  entireMenu[2].setDesc("Corn Tortilla w/ Beef");
  entireMenu[3].setDesc("Flour Tortilla w/ Chicken ");
  entireMenu[4].setDesc("Sandwitch w/ Lamb");
  entireMenu[5].setDesc("Tacos w/ Red Sauce & Beef");
  entireMenu[6].setDesc("Stew w/ Pork & Hominy");

}

//POPULATE THE MENU FOR A NEW CUSTOMER FUNCTION **************************************************
void repopulateMenu(vector<MenuItem> &entireMenu)
{
  const int numItems = 7;

  vector<string> defaultMenuNames = {"Agua de Jamaica", "Horchata" , "Tacos De Asada", "Quesadilla", "Torta al Pastor", "Enchilladas", "Menudo"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost((3.00 + i)); //set a random starter cost for each item
    entireMenu[i].setDesc("yum"); //set all default desc to "delicous"
    entireMenu[i].setICount();
  }
    entireMenu[0].setDesc("Hibiscus Tea");
    entireMenu[1].setDesc("Rice based Drink");
    entireMenu[2].setDesc("Corn Tortilla w/ Beef");
    entireMenu[3].setDesc("Flour Tortilla w/ Chicken ");
    entireMenu[4].setDesc("Sandwitch w/ Lamb");
    entireMenu[5].setDesc("Tacos w/ Red Sauce & Beef");
    entireMenu[6].setDesc("Stew w/ Pork & Hominy");
}

//MENU DRAW ********************************************************
void showMenu(vector<MenuItem> &m)
{
  vector<string> color = {"\x1b[38;5;985m", "\x1b[38;5;998m","\x1b[38;5;985m", "\x1b[38;5;998m","\x1b[38;5;985m", "\x1b[38;5;998m","\x1b[38;5;985m"};
  
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << cUnderL << "\nTaqueria Azteca" << cReset << endl; 
  cout << "ADD  \tNAME \t\t\tCOST  \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << color[i] << m[i].getAddLetter() << ")\t " << setw(17) << left << m[i].getName() 
    << setw(2) << "$" << m[i].getItemCost() << setw(5) << right << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << "\t\t" << setw(10) << left << m[i].getDesc() 
    <<endl; 
  }
  cout << cReset;
}

//RECEIPT ************************************************************
void receipt(vector<MenuItem> &m, double tip, double subtotal)
{
  double total = (subtotal + (subtotal * 0.0825));
 
  
  cout << cClear;
  cout << "\n\tTHANK YOU FOR ORDERING!.\n\n" << endl; 
  cout << "----------------------------------------\n";
  cout << "\t\t" << asctime(localtime(&result))  << "\n";
  cout << "\t\t\t Order Number: " << orderCount << "\n"; 
  cout << "----------------------------------------\n";
  cout << "\t\tTaqueria Azteca #16\n";
  cout << "\t\t4321 7th Street\n";
  cout << "\t\tFort Worth, Texas 76123\n";
  cout << "\t\t(817)-888-1234\n";
  cout << "========================================\n";
  cout << "QTY\t DESC \t      Price \t\tAmount\n";
  cout << "========================================\n";

  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      cout << m[i].getCount() << "\t" <<  setw(14) << left << m[i].getName() << " " << setw(3) 
      << right << m[i].getItemCost() << "\t\t\t " << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl; 
    }
  }
  
  cout << "\n\n--------------------------------------";
  cout <<"\nSub Total\t\t\t\t\t\t " << right << setw(5) << subtotal;
  cout <<"\nSales Tax\t\t\t\t\t\t " << right << setw(5) << (subtotal * .0825);
  cout << "\n--------------------------------------";
  cout <<"\nTotal\t\t\t\t\t\t   \t " << right << setw(5) << total;
  cout <<"\nTip\t\t\t\t\t\t     \t " << right << setw(5) << tip;
  cout <<"\nTotal Due\t\t\t\t\t\t " << right << setw(5) << (total + tip);
}

//Receipt DRAW TO .TXT FUNCTION ******************************************************************
void receiptPrint(vector<MenuItem> &m, double tip, double subtotal)
{
  fstream receipt;
  receipt.open("receipt.txt", ios::out);

  double total = (subtotal + (subtotal * .0825));
  receipt << fixed << setprecision(2);
 
  receipt << "\n\tTHANK YOU FOR ORDERING!!.\n\n" << endl;
  receipt << "----------------------------------------\n";
  receipt << "\t\t" << asctime(localtime(&result))  << "\n";
  receipt << "\t\t\t Order Number: " << orderCount << "\n";
  receipt << "----------------------------------------\n";
  receipt << "\t\tTaqueria Azteca #16\n";
  receipt << "\t\t4321 7th Street\n";
  receipt << "\t\tFort Worth, Texas 76123\n";
  receipt << "\t\t(817)-888-1234\n";
  receipt << "========================================\n";
  receipt << "QTY\t DESC \t\t\t      Price \t\t\t\tAmount\n";
  receipt << "========================================\n";
  
  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      receipt << m[i].getCount() << "\t\t" <<  setw(14) << left << m[i].getName() << " " << setw(5) 
      << right << m[i].getItemCost() << "\t\t\t\t\t " << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl; 
    }
  }
  receipt << "\n\n----------t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
  receipt <<"\nSub Total\t\t\t\t\t\t\t\t\t\t\t\t\t " << right << setw(5) << subtotal;
  receipt <<"\nSales Tax\t\t\t\t\t\t\t\t\t\t\t\t\t " << right << setw(5) << (subtotal * .0825);
  receipt << "\n----------\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
  receipt <<"\nTotal\t\t\t\t\t\t\t\t\t\t\t\t   \t " << right << setw(5) << total;
  receipt <<"\nTip\t\t\t\t\t\t\t\t\t\t\t\t     \t " << right << setw(5) << tip;
  receipt <<"\nTotal Due\t\t\t\t\t\t\t\t\t\t\t\t\t " << right << setw(5) << (total + tip);

  receipt << "\n\n\nThank you for visiting Taqueria Azteca!!!\n";

  receipt.close();
}

//Receipt DRAW TO .HTML FUNCTION ******************************************************************
void receiptPrintHTML(vector<MenuItem> &m, double tip, double subtotal)
{
  fstream receipt;
  receipt.open("receipt.html", ios::out);

  double total = (subtotal + (subtotal * .0825));
  receipt << fixed << setprecision(2);
 
  receipt << "<html><head><title>Cool</title></head>";
  receipt << "<body style=\"background-color:#800000; color:#FFFFFF;\">";
  
  receipt << "<h3>" << "&emsp;&emsp;&emsp;&emsp;&emsp;\n\tTHANK YOU FOR ORDERING!!!.\n\n" << "</h3>";
  receipt << "<h4>" << "Order Number: " << orderCount << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;----------------------------------------\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << asctime(localtime(&result))  << "\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;----------------------------------------\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;----------------------------------------\n" << "</h4>";
  receipt << "<h4>" << "QTY&emsp;&emsp;&emsp;DESC&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Price&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Amount\n" << "</h4>";
  receipt << "<h4>" << "=====================================================\n" << "</h4>";
  
  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      receipt << "<p>&emsp;" << m[i].getCount() << "&emsp;&emsp;&emsp;&nbsp;" <<  setw(30) << left << m[i].getName() << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << setw(3) 
      << right << m[i].getItemCost() << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl << "</p>"; 
    }
  }
  receipt << "<p>" << "\n\n----------&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << "</p>";
  receipt << "<p>" << "\nSub Total&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << subtotal << "</p>";
  receipt << "<p>" << "\nSales Tax&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << (subtotal * .0825) << "</p>";
  receipt << "<p>" <<  "\n----------&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << "</p>";
  receipt << "<p>" << "\nTotal&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << total << "</p>";
  receipt << "<p>" << "\nTip&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << tip << "</p>";
  
  receipt << "<p>" << "\nTotal Due&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << (total + tip) << "</p>";

  receipt << "<p>" "\n\n\nTHANKS FOR ORDERING FROM TAQUERIA AZTECA\n" << "</p>";

  receipt << "</body></html>"; 

  receipt.close();
}

//ORDERING AND RECEIPT ************************************************************
void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 
  double tip = 0.0;
  orderCount++;
  
  do
  {
    cout << cReset;
    cout << "\nPlease enter Item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      int count = 0;
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(1); //increase the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        subtotal += m[i].getItemCost(); //add item cost to the subtotal
        showMenu(m); //updated menu
        cout << "\n +1 " << m[i].getName() << endl;
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if count is less than 0
        {
          m[i].setCount(-1); //count -1
          cout << "\033[2J\033[1;1H"; //clear screen 
          subtotal -= m[i].getItemCost(); 
          showMenu(m); //updated menu
          cout << "\n-1 " << m[i].getName() << endl;
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nError (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 

  double total = (subtotal + (subtotal * .0825));
  receipt(m, tip, subtotal);
  int tinput = 0;
  int minput = 0;
  
  do
  {
    do
    {
      cout << cClear;
      receipt(m, tip, subtotal);
      cout << "\n\n\nWould you like to leave a tip?\n\n";
      cout << "1 - NO TIP\n";
      cout << "2 - 10% - " << subtotal * .1 << "\n";
      cout << "3 - 15% - " << subtotal * .15 << "\n";
      cout << "4 - 20% - (RECOMMENDED)" << subtotal * .2 << "\n";
      cout << "5 - Custom Tip\n\n";

      validateInt(minput);

      if (minput == 1)
      {
        tip = 0;
        receipt(m, tip, subtotal);
      }

      else if (minput == 2)
      {
        tip = subtotal * .1;
        receipt(m, tip, subtotal);
      }

      else if (minput == 3)
      {
        tip = subtotal * .15;
        receipt(m, tip, subtotal);
      }

      else if (minput == 4)
      {
        tip = subtotal * .2;
        receipt(m, tip, subtotal);
      }

      else if (minput == 5)
      {
        double ctip = 0.0;
        cout << "Percentage to tip?\n";
        validateDouble(ctip);
        tip = subtotal * (ctip /100);
        receipt(m, tip, subtotal);
      }
      else
        cout << "Error, try agian.\n";

    }while (minput > 0 && minput > 5);

  cout << "\n\nReview, everything OK? (1 for yes, 0 for no)\n\n";
  validateInt(tinput);

  }while (tinput != 1);

  receiptPrint(m, tip, subtotal);
  receiptPrintHTML(m, tip, subtotal);
  cout << cClear;
  receipt(m, tip, subtotal);

  cout << "\n\nPayment type: \n1 = cash \n2 = credit\n\n";
  validateInt(minput);


  if (minput == 1)
  {
    double payment = 0.0;
    
    do
    {
      cout << cClear;
      receipt(m, tip, subtotal);

      cout << "\n\nHow much money are you paying with?\n\n";
      validateDouble(payment);

      cout << cClear;
      receipt(m, tip, subtotal);

      if((payment + .0075) >= ((subtotal + (subtotal * .0825)) + tip))
      {
        cout << "\n\nChange: " << (payment - ((subtotal + (subtotal * .0825)) + tip));
        cout << "\n\nThanks for Ordering!";
      }

      if((payment + .0075) < ((subtotal + (subtotal * .0825)) + tip))
      {
        cout << "\n\nInsufficient payment";
        cout.flush();
        sleep(2);
      }
    }while ((payment + .0075) < ((subtotal + (subtotal * .0825)) + tip) );
  }

  if (minput == 2)
  {
    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nLoading....";
    cout.flush();
    sleep(1);

    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nThank you for ordering Taqueria Azteca";
  }
}
#endif