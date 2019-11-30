/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

#include "Game.h"
#include "mainMenu.h"

using namespace std;
mainMenu::mainMenu() {
}

int mainMenu::showMenu() {

  string option;
  Game g;
  ifstream infile;
  string line;
  infile.open("logo.txt");

  while (infile) {
     getline(infile, line);
     cout << line << endl;
  }
  infile.close();
cin.ignore();
  cout << "Welcome to Pyslum, a mind-bending text-based adventure!" << endl;
  bool choosedOption = false;
  while (choosedOption == false){
     cout << "What would you like to do?" << endl;
     cout << endl;
     cout << "(1) New Game" << endl;
     cout << "(2) Load Game" << endl;
     cout << "(3) Exit" << endl;
     cout << endl;

     getline(cin, option);
      cout << endl;

     if (option == "1") {
        choosedOption = true;
        g.testLoadGame();
        getline(cin, option);
     }
     else if (option == "2") {
       choosedOption = true;
       getline(cin, option);
        //g.loadGame("testSave.csv");
     }
     else if (option == "3") {
       choosedOption = true;

     }

  }

return 0;
}
