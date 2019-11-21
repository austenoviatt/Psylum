#include "Dialogue.h"

#include <iostream>

using namespace std;

Dialogue::Dialogue() {
}

void Dialogue::talk(Character *c) {
  unsigned int input;

  //find out which character we are talking to
  string charaID = c->getID();
  bool converOver = false;

  while (converOver == false) {
    if (charaID == "snitch") {
      if (c->getEventCounter() == 0) {
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
          cout << "You followed Annabelle." << endl;

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
  }

  }
  return;



  if (input== 0) {


    if (input == 1 || input == 2 || input == 3) {
      //A.addEventCounter();

      talk(c);
    }
  } else if (input == 1) {

    cin >> input;

    if (input == 1 || input == 2) {
      //A.addEventCounter();

      talk(c);
    }
  } else if (input== 2) {

  }
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



