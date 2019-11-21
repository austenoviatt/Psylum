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

using namespace std;

int main() {

  int option = 3;
  Game g;

  cout << "Welcome to Pyslum, a mind-bending text-based adventure!" << endl;

     cout << "What would you like to do?" << endl;
     cout << endl;
     cout << "(1) New Game" << endl;
     cout << "(2) Load Game" << endl;
     cout << "(3) Exit" << endl;
     cout << endl;
     cin >> option;
     cin.ignore();

     switch (option) {
	case 1:
	   //g.getUserInput();
	   g.testLoadGame();
	   break;
	case 2:
	   break;
	case 3:
	   return 0;
	   break;
     }


  return 0;

}
