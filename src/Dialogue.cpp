#include "Dialogue.h"

#include <iostream>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;

Dialogue::Dialogue() {
}

void Dialogue::talk(Character *c, Player P) {
  string input;

  //find out which character we are talking to
  string charaID = c->getID();
  bool converOver = false;

  while (converOver == false) {
    if (charaID == "snitch") {
      if (c->getEventCounter() == 0) {
        cout << "The patient was woken up by you, she looks surprised to see you standing over there" << endl << endl;
        cout << "Patient: A fellow patient! As you can see, I'm also a patient here, my name is Annabelle btw. You look a little lost, are you ok?" << endl << endl;
        cout << "1. Sorry I don’t know how I ended up here and am looking for a way out." << endl;
        cout << "2. Exit conversation" << endl;

        getline(cin, input);
        std::cout << std::endl;
        if (input == "1") {
        c->increaseEventCounter();
          continue;
        }
        else if (input == "2") {
          converOver = true;
          break;
        }
        else {
          converOver = true;
          break;
        }
      }
      else if (c->getEventCounter() == 1) {
        cout << "Patient: I can help you, if you’d like?" << endl << endl;
        cout << "1. Okay. Accept Annabelle’s help" << endl;
        cout << "2. Exit conversation" << endl;

        getline(cin, input);
        std::cout << std::endl;

        if (input == "1") {
          //bad end, need to change return
          cout << "Patient: Follow me, I know a way that can get you out of here." << endl << endl;
          cout << "You followed Annabelle to the elevator. As the elevator dings and the doors open, you see two security guards and a doctor. Annabelle quickly stands back with a nasty smile on her face. You've been tricked!" << endl;
          cout << "Security guards took you back to your room and locked you good this time, you never made it out of that room again......" << endl;
          P.killPlayer();
          converOver = true;
          break;
        }
        else if (input == "2") {
          converOver = true;
          break;
        }
        else {
          converOver = true;
          break;
        }
      }
  }
  else if (charaID == "computer") {

    if (c->getEventCounter() == 0) {
        cout << "There is nothing on the computer except a text input that takes 8 english characters, it looks like some sort of password" << endl << endl;
        cout << "1. Enter password" << endl;
        cout << "2. Leave" << endl;

        getline(cin, input);
        std::cout << std::endl;

        if (input == "1") {
          cout << "Enter Password: " << endl;
          string userInput;
          getline(cin, userInput);
          cout << endl;
          transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
          if (userInput == "i love my mom") {
            c->increaseEventCounter();
            cout << "Password correct! You have been granted access to the control room." << endl << endl;
            //unlock space room
            P.currentRoom->exits[3]->exits[2]->exits[3]->setLock(false);
            c->increaseEventCounter();
            converOver = true;
            break;
          }
          else {
            std::cout << "Password incorrect. Please try again." << endl << endl;
            converOver = true;
            break;
          }

        }
        else if (input == "2") {
          converOver = true;
          break;
        }
    }
    else if (c->getEventCounter() == 1) {
      cout << "Password correct! You have been granted access to the control room." << endl;
      converOver = true;
      break;
    }

  }
  else if (charaID == "bonez") {
    if (c->getEventCounter() == 0) {
        cout << "A patient is standing beside a toilet with a fishing rod in hand." << endl << endl;
        cout << "1. Ask him what is he doing" << endl;
        cout << "2. Leave" << endl << endl;

        getline(cin, input);
        std::cout << std::endl;

        if (input == "1") {
          c->increaseEventCounter();
          continue;
        }
        else if (input == "2") {
          converOver = true;
          break;
        }
  }
  else if (c->getEventCounter() == 1) {
        cout << "Patient: I’m trying to catch a fish but it never seems to work!" << endl;
        cout << "Patient: Wait, I know…I’m in need of bait! I’ll tell you what…you get me bait for my fish and i’ll give you an awesome fishing rod. Do we have a deal?" << endl << endl;
        cout << "1. Deal! I’ll see what I can find" << endl;
        cout << "2. No way. Get it yourself. I don’t need a fishing rod" << endl << endl;

        getline(cin, input);
        std::cout << std::endl;

        if (input == "1") {
          cout << "Patient: Really? Thank you sooooooo much, I'll be waiting here for the bait then" << endl << endl;
          c->increaseEventCounter();
          converOver = true;
          break;
        }
        else if (input == "2") {
          converOver = true;
          break;
        }

    }
    else if (c->getEventCounter() == 2) {
      cout << "Patient: Do you have me bait yet?" << endl << endl;
      converOver = true;
      break;
    }
  }
  else if (charaID == "evildoctor") {


  }



  return;



  }
}



