/********************************************************************************

Name : Nik Patel
Email : n50@umbc.edu
section = 19
Project :Manhunt simulater
         The assignment is to develop a manhunt simulator. The manhunt simulator
         will have two people. The investigator who will be demarked with an “I” and a
         target who will be demarked with a “T”. The target will not be directly visible
         on the map though.
Colloboration : i did not collaborate with anyone
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

// The constant values for various choices and for the height and width
const int wantToOPenAFile = 1;
const int wantToTypeYourOwnParameters = 2;
const int Exit = 3;
const int width = 10;
const int elementOfTheFile = 4;
const int height = 10;

// prototype for exiting the function
void bye();

// prototype of the function which asks user to choose 1 - 3
int options();

// printing the board
void board(char myArray[height][width]);

//asking for direction and using that direction to update the board
void direction(int &x,int &y,char myArray[height][width]);

int main()
{
  cout << " *----------------------------*" << endl;
  cout << " | Wel-Come into Manhunt Game |" << endl;
  cout << " *----------------------------*" << endl;
  int choice = options();
  if (choice == wantToOPenAFile)
    {
      string name;
      cout <<"Enter File Name : ";
      cin >> name;
      ifstream infile(name.c_str());
      int myarray[elementOfTheFile];
      for (int i = 0; i < elementOfTheFile; i++)
	infile >> (myarray[i]);
      int x = myarray[0];
      int y = myarray[1];
      int targetX = myarray[2];
      int targetY = myarray[3];
      cout << "Map loaded" << endl;
      cout << " "<<endl;
      char myArray[height][width];
      for (int i = 0; i < height; i++)
	{
	  for (int j = 0; j < width; j++)
	    {
	      myArray[i][j] = '-';
	    }
	}
      myArray[x][y] = 'I';
      board(myArray);
      while (x != targetX || y != targetY)
	{
	  direction(x, y, myArray);
	}
      cout << "YOU FOUND THE SOLUTION " << endl;
    }

  else if (choice == wantToTypeYourOwnParameters)
    {
      int x, y, targetX, targetY;
      cout << "What is the X axis of the investigator ? :"<<endl;
      cin >> x;
      cout << "What is the Y axis of the investigator ? :"<<endl;
      cin >> y;
      cout << "What is the X axis of the target? :"<<endl;
      cin >> targetX;
      cout << "What is the Y axis of the target? :"<<endl;
      cin >> targetY;

      cout << "Map loaded" << endl;

      //creating 10 * 10 board usig 2D array
      char myArray[height][width];
      for (int i = 0; i < height; i++)
	{
	  for (int j = 0; j < width; j++)
	    {
	      myArray[i][j] = '-';
	    }
	}
      myArray[x][y] = 'I';

      // printing the board
      board(myArray);
      while (x != targetX || y != targetY )
	{
	  direction(x, y, myArray);
	}
      cout << "YOU FOUND THE SOLUTION " << endl;
    }
  else
      bye();
    
  return 0;
}

int options()
{
  int number;
  cout << "What would you like to do ? " << endl;
  cout << "1. Load a simulation from a file." << endl;
  cout << "2. Start a new simulation." << endl;
  cout << "3. Exit" << endl;
  cin >> number;
  return number;
}

void board(char myArray[height][width]) {
  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
	{
	  cout << myArray[i][j] << " ";
	}
      cout << endl;
    }
}

// passing the board and updating the board after choosing each direction  
void direction(int &x, int &y,char myArray[height][width])
{
  int Dir;
  cout << "What would you like  to do? : " << endl;
  cout << "1. Search North" << endl;
  cout << "2. Search East" << endl;
  cout << "3. Search South" << endl;
  cout << "4. Search West" << endl;
  cout << "5. See Map" << endl;
  cout << "6. Exit" << endl;
  cout << "Enter 1-6 : ";
  cin >> Dir;
  switch (Dir)
    {
    case 1:
      if (x > 0)
	{
	  myArray[x][y] = '*';
	  x -= 1;
	  myArray[x][y] = 'I';
	  cout << "Try Searching North " << endl;
	  cout << " " << endl;
	  board(myArray);
	}
      break;
    case 2:
      if (y < height) 
	{
	  myArray[x][y] = '*';
	  y += 1;
	  myArray[x][y] = 'I';
	  cout << "Try Searching East " << endl;
	  cout << " "<<endl;
	  board(myArray);
	}
      break;
    case 3:
      if (x < width) 
	{
	  myArray[x][y] = '*';
	  x += 1;
	  myArray[x][y] = 'I';
	  cout << "Try Searching South " << endl;
          cout << " "<<endl;
	  board(myArray);
	  break;
	}
    case 4:
      if (y > 0)
	{
	  myArray[x][y] = '*';
	  y -= 1;
	  myArray[x][y] = 'I';
	  cout << "Try Searching West " << endl;
          cout << " "<<endl;
	  board(myArray);
	  break;
	}
    case 5:
      board(myArray);
      break;
    case 6:
      bye();
    }
}

void bye()
{
  cout << "Good-Bye" << endl;
  cout << "See you Around " << endl;
  exit(0);
}
