/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include "../../include/Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

int main() {

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
    g.loadGame("testSave.csv");
  case 3:
    return -1;
  }

  return 0;

}
