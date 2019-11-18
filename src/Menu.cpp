//Test program for menu and ascii art

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

// system("color 8B");
  int option;
  Game g;
  ifstream infile("logo.txt");
  string line;

  while (infile) {
    getline(infile, line);
    cout << line << endl;
  }
  infile.close();
  cout << "Welcome to Pyslum, a mind-bending text-based adventure!" << endl;
  cout << "What would you like to do?" << endl;
  cout << endl;
  cout << "(1) New Game" << endl;
  cout << "(2) Load Game" << endl;
  cout << "(3) Exit" << endl;
  cout << endl;
  cin >> option;

  switch (option) {
  case 0:
  case 1:
    g.create();
  case 2:
    g.load();
  case 3:
    return -1;
  }

  return 0;

}
