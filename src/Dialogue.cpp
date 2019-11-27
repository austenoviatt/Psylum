#include "Dialogue.h"

#include <iostream>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;

Dialogue::Dialogue() {
}

void Dialogue::talk(Character *c, Player *P) {
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
          cout << "You followed Annabelle to the elevator. As the elevator dings and the doors open, you see two security guards and a doctor. Annabelle quickly stands back with a nasty smile on her face. You've been tricked!" << endl << endl;
          cout << "Security guards took you back to your room and locked you good this time, you never made it out of that room again......" << endl;
          P->killPlayer();
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
  else if (charaID == "Computer") {

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
            P->currentRoom->exits[3]->exits[2]->exits[3]->setLock(false);
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
    if (P->inventory.hasItem("labcoat")) {
      cout << "Patient: Ahhhhh! A doctor! No doctor! No doctor! Bonez scared of doctor!" << endl;
      converOver = true;
      break;
    }

    if (c->getEventCounter() == 0) {
        cout << "A patient is standing beside a toilet with a fishing rod in hand." << endl << endl;
        cout << "1. Ask him what is he doing" << endl;
        cout << "2. Leave" << endl << endl;

        getline(cin, input);
        cout << endl;

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
        cout << "Patient: I’m trying to catch a fish but it never seems to work!" << endl << endl;
        cout << "Patient: Wait, I know…I’m in need of bait! I’ll tell you what…you get me bait for my fish and i’ll give you an awesome fishing rod. Do we have a deal?" << endl << endl;
        cout << "1. Deal! I’ll see what I can find" << endl;
        cout << "2. No way. Get it yourself. I don’t need a fishing rod" << endl << endl;

        getline(cin, input);
        cout << endl;

        if (input == "1") {
          cout << "Patient: Really? Thank you sooooooo much, I'll be waiting here for the bait then." << endl << endl;
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
    else if (c->getEventCounter() == 3) {
      cout << "Patient: Thanks pal, me and 'Mr wormington the 3rd' have become friends now all thanks to you!" << endl << endl;
      converOver = true;
      break;
    }
  }
  else if (charaID == "evildoctor") {
    if (P->inventory.hasItem("labcoat")) {

      if (c->getEventCounter() == 0) {
        cout << "Doctor: YOU there! I've never seen you around here, are you a new employee here?" << endl << endl;
        cout << "1. No. I woke up in this strange place and have no idea how I got here." << endl;
        cout << "2. Yes. This is my first day on the job. I thought I’d come join my fellow coworkers for a coffee." << endl << endl;

        getline(cin, input);
        cout << endl;

        if (input == "1") {
            cout << "Doctor: Well, well, well…looks like we have an escapee on our hands! Guards! Take this patient back to their room immediately!" << endl << endl;
            cout << "You turn around to make an escape but suddenly, a sharp prick and tingling sensation radiate through your arms and the rest of your body. The doctor has injected you with sedatives!" << endl << endl;
            cout << "Two guards burst through the doors towards. As your eyes begin to close and your body hits the ground…the sound of handcuffs and a deep voice 'Back to the drawing table you go.'" << endl << endl;
            P->killPlayer();
            converOver = true;
            break;
        }
        else if (input == "2") {
            c->increaseEventCounter();
            continue;
        }
      }
      else if (c->getEventCounter() == 1) {
            cout << "Doctor: Ah, nice lab coat. You must be my new assistance." << endl << endl;
            cout << "Doctor: Well, I could use a cup of coffee myself and seeing as your about to go make one, can you make me one too?" << endl << endl;
            cout << "1. Absolutely not. Go make it yourself" << endl;
	       	  cout << "2. The best cup of coffee, coming right up!" << endl << endl;

	       	  getline(cin, input);
            cout << endl;

            if (input == "1") {
              cout << "Doctor: That’s no way to speak to your boss. It makes me wonder, who are you really?" << endl << endl;
              cout << "Doctor: No need to answer that, we’ll find out. Guards! I think it’s time our ‘new assistant’ learns some manners." << endl << endl;
              cout << "You look at the exit and see two security guards walking toward you. You’ve be detained and taken in for questioning! This doctor doesn’t like to play games, this doctor likes to use truth serum!" << endl << endl;
              P->killPlayer();
              converOver = true;
              break;
            }
            else if (input == "2") {
              cout << "You make your way over to the coffee machine. Beside it, a clean chipped coffee mug. Here’s your opportunity to make the best cup of coffee, ever!" << endl << endl;
              c->increaseEventCounter();
              converOver = true;
              break;
            }
      }
      else if (c->getEventCounter() == 2) {
            cout << "Doctor: Where is my coffee?" << endl << endl;
            break;
      }

    }
    else {
      cout << "Doctor: Well, well, well…looks like we have an escapee on our hands! Guards! Take this patient back to their room immediately!" << endl << endl;
      cout << "You turn around to make an escape but suddenly, a sharp prick and tingling sensation radiate through your arms and the rest of your body. The doctor has injected you with sedatives!" << endl << endl;
      cout << "Two guards burst through the doors towards. As your eyes begin to close and your body hits the ground…the sound of handcuffs and a deep voice 'Back to the drawing table you go.'" << endl << endl;
      P->killPlayer();
      converOver = true;
      break;
    }

  }
  else if (charaID == "petowner") {


  }
  else if (charaID == "treespirit") {
      unsigned int riddleCounterIndex;
    //get the index of the riddle counter item
    for (int i = 0; i < P->currentRoom->inventory.getItems().size(); i++) {
      if (P->currentRoom->inventory.items[i].getName() == "forestcounter") {
        riddleCounterIndex = i;
      }
    }

       if (c->getEventCounter() == 0) {
          cout << "Tree Spirit: Good day young Padawan. I am the spirit of the forest. It’s not very often I find people stumble across here. ";
          cout << "My creatures tell me you spirit is strong and that you’re in great danger. ";
          cout << "Know we cannot fix things but we can most certainly help those worthy. Are you worthy Padawan?" << endl << endl;
          cout << "1. Absolutely" << endl;
          cout << "2. On second thought, I gotta get going." << endl << endl;

          getline(cin, input);
          cout << endl;

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
        cout << "Tree Spirit: To prove you are worthy, I'm going to give you 3 riddles, solve any one of those and I'll give you a reward." << endl << endl;
        cout << "Tree Spirit: Here is the first riddle." << endl << endl;
        cout << "Tree Spirit: With marble walls as white as milk, an inner skin as soft as silk, Inside a fountain crystal clear, a golden apple does appear.";
        cout << "There are no doors to this stronghold, yet thieves break in and steal the gold. " << endl;
        cout << "What is it?" << endl << endl;

        getline(cin, input);
        cout << endl << endl;

        if (input == "egg") {
          P->currentRoom->inventory.items[riddleCounterIndex].increaseItemState();
        }
        c->increaseEventCounter();
        continue;

      }
      else if (c->getEventCounter() == 2) {
        cout << "Tree Spirit: Let us continue with the second one." << endl << endl;
        cout << "Tree Spirit: It can not be seen whenever it's there. It fills up a room, it's much like the air. ";
        cout << "It can not be touched, there's nothing to hear. It is quite harmless, there's nothing to fear." << endl;
        cout << "What is it?" << endl << endl;

        getline(cin, input);
        cout << endl << endl;

        if (input == "darkness") {
          P->currentRoom->inventory.items[riddleCounterIndex].increaseItemState();
        }
        c->increaseEventCounter();
        continue;
      }
      else if (c->getEventCounter() == 3) {
        cout << "Tree Spirit: We are almost done, young Padawan. Let's see if you can answer the 3rd riddle." << endl << endl;
        cout << "Tree Spirit: Turn me upside down and I’m right side up. ";
        cout << "Empty my glass and you fill up my cup, I’m always on time and I’m never late, I never go backwards at any rate." << endl;
        cout << "What am I?" << endl << endl;

        getline(cin, input);
        cout << endl << endl;

        if (input == "hourglass") {
          P->currentRoom->inventory.items[riddleCounterIndex].increaseItemState();
        }
        c->increaseEventCounter();
        continue;
      }
      else if (c->getEventCounter() == 4) {
        cout << "Tree Spirit: That's all the riddle I have for you, young Padawan. You have answered ";

        if (P->currentRoom->inventory.items[riddleCounterIndex].getItemState() == 0) {
          cout << "0 riddles";
        }
        else if (P->currentRoom->inventory.items[riddleCounterIndex].getItemState() == 1) {
          cout << "1 riddle";
        }
        else if (P->currentRoom->inventory.items[riddleCounterIndex].getItemState() == 2) {
          cout << "2 riddles";
        }
        else if (P->currentRoom->inventory.items[riddleCounterIndex].getItemState() == 3) {
          cout << "3 riddles";
        }

         cout << " correctly!" << endl << endl;

        if (P->currentRoom->inventory.returnItem("forestcounter").getItemState() > 0) {
          cout << "Tree Spirit: Splendid! You have proven yourself worthy! As promised, I'll give you this ";
          cout << P->currentRoom->inventory.returnItem("claw").getNiceName() << " as a reward. " << endl;
          cout << "Tree Spirit: I'm sure it will come in handy soon. Now, go. Is time for you to be on your path. Take care young Padawan." << endl << endl;
          for (int i = 0; i < P->currentRoom->inventory.getItems().size(); i++) {
            if (P->currentRoom->inventory.getItems()[i].getName() == "claw") {

              string itemName = P->currentRoom->inventory.getItems()[i].getName();
              P->inventory.addItem(P->currentRoom->inventory.getItems()[i]);
              P->currentRoom->inventory.removeItem(P->currentRoom->inventory.getItems()[i]);

              cout << "The tree spirit put a weird looking \e[1m" << itemName << "\e[0m into your pocket." << std::endl << endl;
            }
          }

          c->increaseEventCounter();
          converOver = true;
          break;
        }
        else {
          cout << "Tree Spirit: Unfortunately I can't give you the reward, but it doesn't hurt to give you a second chance.";
          cout << "Tree Spirit: Think about the riddles again and talk to me whenever you are ready." << endl << endl;
          c->decreaseEventCounter();
          c->decreaseEventCounter();
          c->decreaseEventCounter();
          P->currentRoom->inventory.items[riddleCounterIndex].setItemState(0);
          converOver = true;
          break;
        }

      }
      else if (c->getEventCounter() == 5) {
        cout << "The tree spirit fall silent and did not answer your call." << endl << endl;
        converOver = true;
        break;
      }

  }
  return;

  }
}
