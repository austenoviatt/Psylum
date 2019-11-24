#include "Dialogue.h"

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

Dialogue::Dialogue() {
}

void Dialogue::talk(Character *c, Player P) {
  unsigned int input;

  //find out which character we are talking to
  string charaID = c->getID();
  bool converOver = false;

  while (converOver == false) {
    if (charaID == "snitch") {
      if (c->getEventCounter() == 0) {
        cout << "The patient was woken up by you, she looks surprised to see you standing over there" << endl;
        cout << "Patient: A fellow patient! As you can see, I'm also a patient here, my name is Annabelle btw. You look a little lost, are you ok?" << endl;
        cout << "1. Sorry I don’t know how I ended up here and am looking for a way out." << endl;
        cout << "2. Exit conversation" << endl;

        cin >> input;
        if (input == 1) {
        cin.ignore();
        c->increaseEventCounter();
        continue;
        }
        else if (input == 2) {
          cin.ignore();
          converOver = true;
          break;
        }
        else {
          cin.ignore();
          converOver = true;
          break;
        }
      }
      else if (c->getEventCounter() == 1) {
        cout << "Patient: I can help you, if you’d like?" << endl;
        cout << "1. Okay. Accept Annabelle’s help" << endl;
        cout << "2. Exit conversation" << endl;

        cin >> input;
        if (input == 1) {
          cin.ignore();
          //bad end, need to change return
          cout << "Patient: Follow me, I know a way that can get you out of here." << endl;
          cout << "You followed Annabelle to the elevator. As the elevator dings and the doors open, you see two security guards and a doctor. Annabelle quickly stands back with a nasty smile on her face. You've been tricked!" << endl;
          cout << "Security guards took you back to your room and locked you good this time, you never made it out of that room again......" << endl;
          P.killPlayer();
          converOver = true;
          break;
        }
        else if (input == 2) {
          cin.ignore();
          converOver = true;
          break;
        }
        else {
          cin.ignore();
          converOver = true;
          break;
        }
      }
  }
  else if (charaID == "computer") {
    cout << "There is nothing on the computer except a text input that takes 8 english characters, it looks like some sort of password" << endl;
    cout << "1. Enter password" << endl;
    cout << "2. Leave" << endl;
    if (c->getEventCounter() == 0) {
        cin >> input;
        if (input == 1) {
          cin.ignore();
          cout << "Enter Password: " << endl;
          string userInput;
          getline(cin, userInput);
          cout << endl;
          transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
          if (userInput == "i love my mom") {
            c->increaseEventCounter();
            cout << "password correct!" << endl;
            //unlock space room
          }
          else {
            converOver = true;
            break;
          }

        }
        else if (input == 2) {
          cin.ignore();
          converOver = true;
          break;
        }
    }
    else if (c->getEventCounter() == 1) {

    }

  }

  }
  return;

  /*
  switch(input) {
    case 1:

        cout << "I can help you, if you’d like?" << endl;
        cout << "1. Okay. Follow Annabelle’s lead" << endl;
        //event = annaSnitches
        cout << "2. Refuse Annabelle’s help but don’t leave lose ends" << endl;
        //event = sedateAnna
        cin >> input;
        switch(input) {
        case 1:
          cout << "Game Over" << endl;
          break;
        case 2:
          cout << "You pulled out the sedative and injected Annabelle, she passed out onto the ground." << endl;
          break;
        }
        break;
    case 2:
      A.addEventCounter();
        cout << "No no no no no! You’ve done something veeeeeery bad. Very bad I tell you! They’ll take me with you! I have to tell them. I have to!" << endl;
        cout << "1. Knock her out." << endl;
        //event = sedateAnna
        cout << "2. Run!" << endl;
        //event = annaSnitches
        cin >> input;
        break;
    case 3:
        cout << "If you’re leaving, you’re taking me with you. I don’t think you’ll make it very far without my help anyway." << endl;
        cout << "1. Accept the negotiation" << endl;
        //event = annaSnitches
        cout << "2. Find a way to leave without her." << endl;
        //event = sedateAnna
        cin >> input;
        break;
  }*/


}



