#include "Dialogue.h"

#include <iostream>

using namespace std;

Dialogue::Dialogue() {
}



void Dialogue::talk(std::string chaID) {
  unsigned int input;



  if (input== 0) {
    cout << "It’s not nice to look through people’s stuff….what are you doing here?"
         << endl;
    cout << "1. Sorry I don’t know how I ended up here and am looking for a way out."
         << endl;
    cout << "2. I don’t know who you are but we’re in danger and we have to leave now! I’ve locked someone in my room and I’m sure they will be looking for her."
         << endl;
    cout << "3. Howdy there! What a surprise! This isn’t the bathroom huh? Well how very awkward. I’ll be leaving now. Good talk, bye!"
         << endl;

    cin >> input;

    if (input == 1 || input == 2 || input == 3) {
      //A.addEventCounter();

      talk(chaID);
    }
  } else if (input == 1) {
    cout << "I can help you, if you’d like?" << endl;
    cout << "1. Okay. Follow Annabelle’s lead" << endl;
    cout << "2. Refuse Annabelle’s help" << endl;

    cin >> input;

    if (input == 1 || input == 2) {
      //A.addEventCounter();

      talk(chaID);
    }
  } else if (input== 2) {
    cout << "You reached conversation stage 3!" << endl;
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



