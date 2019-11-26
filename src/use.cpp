#include "Use.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "Inventory.h"

#include <iostream>

using namespace std;

Use::Use() {}

void Use::use(std::vector<std::string> result, Player* player) {

  bool roomFound = false;

  std::string item = result[1];
  if ( item == "poisoncoffee") {
      if (player->inventory.hasItem("poisoncoffee") == true) {
    if (result.size() > 2) {
      cout << "You know you put poison into the coffee. You did it yourself. But you decide to drink the coffee anyways. I guess that’s one way to escape." << std::endl;
      player->killPlayer();
    } else if (result[2] == "doctor"
               && result[2] == player->currentRoom->characters[0].getName()) {
      cout << "You extend the cup of coffee to the doctor. He takes it impatiently and quickly downs the whole cup. You’re not sure how he didn’t burn himself, it was very hot. You also aren’t sure how he didn’t taste all the chemicals you mixed into the coffee. He starts to convulse and begins to bleed profusely from most of his orifices. You look away in horror. Quickly the noises he is making subsides and when you look back, he is dead." << std::endl;
      player->inventory.removeItem("poisoncoffee");
      player->currentRoom->characters[0].killChara();
    } else
      cout << "You can't use that here." << endl << endl;
  }
  else std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "sedative") {
    if (player->inventory.hasItem("sedative") == true) {

      if (result.size() == 2) {
        cout << "You inject yourself with the sedatives. You have always wondered what it feels like to be drugged. As you slowly lose your grip on consciousness, a doctor comes towards you and picks you up, and you finally slip into oblivion. When you come to a few hours later, you are back in your room, strapped to your bed. There is no way to get out now."
             << std::endl << endl;
        player->killPlayer();
      } else if ((player->currentRoom->characters[0].getName()== "patient") && ((result[2] == "patient") || (result[2] == "annabelle") || (result[2] == "girl") || result[2] == "person")) {
        cout << "Annabelle’s screams slowly get quieter. When they finally stop, you sigh with relief, she won’t be causing you problems any time soon.";
        player->inventory.removeItem("sedative");
        player->currentRoom->characters[0].killChara();
      } else
        cout << "You can't use the sedative like that." << endl << endl;
    } else
      std::cout << "inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "worm") {
      if (player->inventory.hasItem("worm") == true){
          if (result.size() == 2){
            std::cout << "You can't use the worm like that." << std::endl << endl;
          }
    else if (result[2] == "bonez"
        && result[2] == player->currentRoom->characters[0].getName()) {

      cout << "'This is exactly what I need to catch that fish!’ shouts Bonez. You watch as he starts to put the worm on the hook of the fishing rod. He pauses, looking between the toilet and the worm and the hook. After a minute of contemplating, Bonez tosses the fishing rod at you and exclaims ‘Ah! You know, I only wanted to catch that fish so I could have a friend to keep me company. I don’t need to catch him now because you brought me a different friend, and this one is even better because he fits in my pocket! Keep the fishing rod pal, I don’t need it any more!’ You stick the fishing rod into your pocket." << endl << endl;
      player->inventory.removeItem("worm");
      player->inventory.addItem(player->allInv.returnItem("fishingrod"));

    } else
      cout << "You can't use that here." << endl << endl;
  }
  else std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "coffee") {
    if (player->inventory.hasItem("coffee") == true){
    if (result.size() == 2) {
      cout << "You drink the coffee. It is warm and comforting, but you can't help feeling like you should have done something else with it." << endl << endl;
      player->inventory.removeItem("coffee");
    } else if (result[2] == "doctor"
               && result[2] == player->currentRoom->characters[0].getName()) {
      cout << "You extend the cup of coffee to the doctor. He takes it impatiently and quickly downs the whole cup. You’re not sure how he didn’t burn himself, it was very hot. 'Another one!' he barks at you."
           << endl << endl;
      player->inventory.removeItem("coffee");
    } else if ((result[2] == "ratpoison") && (player->inventory.hasItem("ratpoison") == true)) {
      cout << "You combine the coffee and rat poison. This doesn’t feel like the healthiest drink."
           << endl << endl;
      player->inventory.removeItem("coffee");
      player->inventory.removeItem("ratpoison");
      player->inventory.addItem(player->allInv.returnItem("poisoncoffee"));
    } else
      cout << "You can't use the coffee like that. " << endl << endl;
  }
  else
    std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "ratpoison") {
      if (player->inventory.hasItem("ratpoison") == true){
    if (result.size() == 2)
      cout << "You can't use the rat poison like that." << endl << endl;
    else if (result[2] == "ratpoison" && player->inventory.hasItem("coffee")) {
      cout << "You combine the rat poison and coffee. This doesn’t feel like the healthiest drink."
           << endl << endl;
      player->inventory.removeItem("coffee");
      player->inventory.removeItem("ratpoison");
      player->inventory.addItem(player->allInv.returnItem("poisoncoffee"));
    } else
      cout << "You can't use the rat poison like that. " << endl << endl;
  }
  else
    std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "magnet") {
    if (player->inventory.hasItem("magnet") == true) {
      if (result.size() == 2)
        cout << "You can't use the magnet like that." << endl << endl;
      else if (result[2] == "fishingrod" && player->inventory.hasItem("fishingrod")) {
        cout << "You stick the magnet onto the paperclip hook. It doesn’t seem like the most durable way to do things, but you don’t have any glue or tape so this will have to do. You now have a magnet rod!"
             << endl << endl;
        player->inventory.removeItem("magnet");
        player->inventory.removeItem("fishingrod");
        player->inventory.addItem(player->allInv.returnItem("magnetrod"));

      } else
        cout << "You can't combine those things." << endl << endl;
    } else
      std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "fishingrod") {
    if (player->inventory.hasItem("fishingrod") == true) {
      if (result.size() == 2)
        cout << "You can't use the fishing rod like that." << endl << endl;
      else if (result[2] == "magnet" && player->inventory.hasItem("magnet")) {
        cout << "You stick the magnet onto the paperclip hook. It doesn’t seem like the most durable way to do things, but you don’t have any glue or tape so this will have to do. You now have a magnet rod!"
             << endl << endl;
        player->inventory.removeItem("magnet");
        player->inventory.removeItem("fishingrod");
        player->inventory.addItem(player->allInv.returnItem("magnetrod"));

      } else
        cout << "you can't combine those things." << endl << endl;
    } else
    std::cout << "Inventory does not contain this item." << endl << endl;
  }
  else if (item == "magnetrod") {
    if (player->inventory.hasItem("magnetrod") == true) {
      if (result.size() == 2)
        cout << "You can't use the magnet rod that." << endl << endl;
      else if (((result[2] == "window")||(result[2] == "keycard"))
               && player->currentRoom->inventory.hasItem("keycard")) {
        std::cout <<
                  "You toss the magnet out the window and towards the keycard on the ground. It takes a few tries before you get it close enough that the magnet sticks to the card. You pull the card up to you and as you remove it from the magnet, the whole magnet rod falls apart in your hands. Oh well, you probably wont need it again."
                  << std::endl << endl;
        player->inventory.removeItem("magnetrod");
        player->inventory.addItem(player->allInv.returnItem("keycard"));
        player->currentRoom->inventory.removeItem("keycard");
      }
    } else
      std::cout << "Inventory does not contain that item." << std::endl << endl;
  }
  else if (item == "coffeemaker") {
    if (player->currentRoom->inventory.hasItem("coffeemaker")){
      if (result.size() > 2) {
      std::cout << "You can't use the coffee maker like that." << endl << endl;
    } else if (player->inventory.hasItem("coffee")) {
        std::cout << "You already have a coffee, you don't need another." << endl << endl;
      } else
        std::cout <<
                  "You start the coffee maker and quickly a cup is filled with boiling hot coffee. You pick up the coffee."
                  << endl << endl;
    } else
      std::cout << "You can't use that." << endl << endl;
  }
  else if (item == "window") {
    std::cout << "You can't do that." << endl << endl;
  }
  else if (item == "journal") {
    if (player->currentRoom->inventory.hasItem("journal") == false) {
      std::cout << "You can't do that." << endl << endl;
    } else if (result.size() > 2)
      std::cout << "You can't use the journal like that." << endl << endl;
    else {
        std::cout << "They call it a hospital, but I know better. The pills and the needles keep coming, as does the cold and boring food. There is no rest from the screams of others but at least it keeps me company. Sometimes in my dreams, I hear whispers telling me there's light at the end of the tunnel. Is that where my friends have gone? The doctors and nurses promise they will fix me if I cooperate. HAHAHA! I will show them, I don't need fixing...." << std::endl << endl;
    }
  }
  else if (item == "roomkey") {
    if (player->inventory.hasItem("roomkey") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use the room key like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "roomkey") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("roomkey");
          roomFound = true;
          std::cout <<
                    "The card slides through the card reader and a red light flickers to green above the patients door. It looks like you can go in there now. None of the other doors on this floor have card readers, so you throw the key card away."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "button2") {
    if (player->inventory.hasItem("button2") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use button 2 like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "button2") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("button2");
          roomFound = true;
          std::cout <<
                    "You press the number 2 button into the spot right below the 3 button on the elevator panel. The metal connections seem to snap right in place and the button lights up. You should be able to visit the second floor now."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "button1") {
    if (player->inventory.hasItem("button1") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use button 1 like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "button1") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("button1");
          roomFound = true;
          std::cout <<
                    "Like with the number 2 button, the number 1 button snaps into place and lights up. You can now visit the first floor."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "keycard") {
    if (player->inventory.hasItem("keycard") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use the key card like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "keycard") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("keycard");
          roomFound = true;
          std::cout <<
                    "The keycard slides smoothly into the card slot. You don’t hear anything happen, but the basement button lights up. You can now visit the basement."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "claw") {
    if (player->inventory.hasItem("claw") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use the claw like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "claw") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("claw");
          roomFound = true;
          std::cout <<
                    "As you lift the claw towards the slot in the wall, it almost jumps out of your hand and into the wall of its own accord. The designs on the wall start to rotate until they all align and a doorway opens up into the room beyond."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "magicmushroom") {
    if (player->inventory.hasItem("magicmushroom") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use the magic mushroom like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "magicmushroom") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("magicmushroom");
          roomFound = true;
          std::cout <<
                    "You pop the mushrooms into you mouth and chew. They have an earthy taste, with a strange lingering heat, like you just ate a habenero pepper. The mushrooms also seems to have another lingering effect, and the room starts to swirl around you. You feel like you’re losing touch with reality and feel yourself transform into a dragon, wings, scales, fire breath and all. This is not how you expected your day to go. As you explore the room and your new dragon body, every fiery exhale seems to melt more and more of the ice. And then, as suddenly as it came on, you are back in your own body, and the ice is all melted. You aren’t entirely sure what just happened."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "crowbar") {
    if (player->inventory.hasItem("crowbar") == true) {
      if (result.size() > 2) {
        std::cout << "You can't use the crowbar like that." << std::endl << endl;
      }
      for (uint i = 0; i < player->currentRoom->exits.size(); i++) {
        if ( player->currentRoom->exits[i]->getKey() == "crowbar") {
          player->currentRoom->exits[i]->setLock(false);
          player->inventory.removeItem("crowbar");
          roomFound = true;
          std::cout <<
                    "You use the crowbar to pry open the door to the doctors office. You can now go into the doctors office."
                    << endl << endl;
        }
      }
      if (roomFound == false)
        std::cout << "You can't use that here." << std::endl << endl;
    } else
      std::cout << "Inventory does not contain this item." << std::endl << endl;
  }
  else if (item == "boat") {
      std::vector<string> pets;
      uint wolfIndex;
      uint goatIndex;
      uint cabbageIndex;
      uint boatIndex;
      uint numOfPets = 0;
      std::string input;
      //get the index of 3 pets in AllInv and boat
      for (int i = 0; i < player->allInv.getItems().size(); i++) {
        if (player->allInv.getItems()[i].getName() == "wolf") {
          wolfIndex = i;
        }
        else if (player->allInv.getItems()[i].getName() == "goat") {
          goatIndex = i;
        }
        else if (player->allInv.getItems()[i].getName() == "cabbage") {
          cabbageIndex = i;
        }
        else if (player->allInv.getItems()[i].getName() == "boat") {
          boatIndex = i;
        }
      }

      //check how many pets are in player inventory
      for (int i = 0; i < player->inventory.getItems().size(); i++) {
        if (player->inventory.getItems()[i].getName() == "wolf" || player->inventory.getItems()[i].getName() == "goat" || player->inventory.getItems()[i].getName() == "cabbage") {
          numOfPets++;
        }
      }
      if (numOfPets > 1) {
        std::cout << "You can only carry 1 pet onto the boat at a time, try dropping off a pet by using the \e[1mDrop\e[0m command." << std::endl;
        return;
      }

      //numOfPets ok, count the pets that's going to be left on the platform.
      if ((player->allInv.getItems()[wolfIndex].getItemState() == player->allInv.getItems()[boatIndex].getItemState()) && (player->inventory.hasItem("wolf") == false)) {
        std::cout << "You will be leaving \e[1mWolf\e[0m on the platform unattended" << std::endl;
        //cout << "state of wolf is " << player->allInv.getItems()[wolfIndex].getItemState() << endl;
        pets.push_back("wolf");
      }
      if ((player->allInv.getItems()[goatIndex].getItemState() == player->allInv.getItems()[boatIndex].getItemState()) && (player->inventory.hasItem("goat") == false)) {
        std::cout << "You will be leaving \e[1mGoat\e[0m on the platform unattended" << std::endl;
        //cout << "state of goat is " << player->allInv.getItems()[goatIndex].getItemState() << endl;
        pets.push_back("goat");
      }
      if ((player->allInv.getItems()[cabbageIndex].getItemState() == player->allInv.getItems()[boatIndex].getItemState()) && (player->inventory.hasItem("cabbage") == false)) {
        std::cout << "You will be leaving \e[1mCabbage\e[0m on the platform unattended" << std::endl;
        //cout << "state of cabbage is " << player->allInv.getItems()[cabbageIndex].getItemState() << endl;
        pets.push_back("cabbage");
      }
      //cout << "state of boat is " << player->allInv.getItems()[boatIndex].getItemState() << endl;
      std::cout << std::endl;
      std::cout << "Everything ok and travel to the other side of the platform?" << std::endl << endl;
      std::cout << "1. Yes, I'm ready to go" << endl;
      std::cout << "2. No, I have to make some changes" << endl << endl;

      getline(cin, input);
      cout << endl;

      if (input == "1") {
        //player decided to cross the platform, check the animals on the platform are ok or not
        for (auto x : pets) {
          if (x == "wolf") {
            for (auto y : pets) {
              if (y == "goat") {
                std::cout << "As you made your way to the other side of the platform, due to being unattended, the \e[1mWolf\e[0m ate the \e[1mGoat\e[0m" << std::endl << endl;
                std::cout << "The pet owner let out a horrifying scream, he couldn't handle the loss of his beloved \e[1mGoat\e[0m. He jumped into the dark, murky sewage water and drowned." << std::endl << endl;
                std::cout << "You never figured out the password for the iron door and died in the sewage....." << std::endl << endl;
                player->killPlayer();
                return;
              }
            }
          }
          else if (x == "goat") {
            for (auto y : pets) {
              if (y == "cabbage") {
                std::cout << "As you made your way to the other side of the platform, due to being unattended, the \e[1mGoat\e[0m ate the \e[1mCabbage\e[0m" << std::endl << endl;
                std::cout << "The pet owner let out a horrifying scream, he couldn't handle the loss of his beloved \e[1mCabbage\e[0m. He jumped into the dark, murky sewage water and drowned." << std::endl << endl;
                std::cout << "You never figured out the password for the iron door and died in the sewage....." << std::endl << endl;
                player->killPlayer();
                return;
              }
            }
          }
        }
        pets.clear();

        //pets on the platform are all ok, change the item state for boat, and the pets in the inventory
        if (player->allInv.getItems()[boatIndex].getItemState() == 0) {
          player->allInv.items[boatIndex].increaseItemState();   //increase for boat
          //increase for pet
          if (player->inventory.hasItem("wolf") == true) {
            player->allInv.items[wolfIndex].increaseItemState();
          }
          else if (player->inventory.hasItem("goat") == true) {
            player->allInv.items[goatIndex].increaseItemState();
          }
          else if (player->inventory.hasItem("cabbage") == true) {
            player->allInv.items[cabbageIndex].increaseItemState();
          }
        }
        else if (player->allInv.getItems()[boatIndex].getItemState() == 1) {
          player->allInv.items[boatIndex].decreaseItemState();   //decrease for boat
          //decrease for pet
          if (player->inventory.hasItem("wolf") == true) {
            player->allInv.items[wolfIndex].decreaseItemState();
          }
          else if (player->inventory.hasItem("goat") == true) {
            player->allInv.items[goatIndex].decreaseItemState();
          }
          else if (player->inventory.hasItem("cabbage") == true) {
            player->allInv.items[cabbageIndex].decreaseItemState();
          }
        }
        //puzzle solving condition check
        if (player->allInv.getItems()[wolfIndex].getItemState() == 1 && player->allInv.getItems()[goatIndex].getItemState() == 1 && player->allInv.getItems()[cabbageIndex].getItemState() == 1) {
          std::cout << "You finally moved all 3 pets to the other side of the platform. The pet owner is sooooooo happy he swam across the sewage water and unlocked the iron door for you." << std::endl << endl;
          player->currentRoom->exits[0]->setLock(false);
          std::cout << "The iron door is now open" << endl << endl;
          return;
        }
        std::cout << "You made it to other side of the platform" << std::endl;
      }
      else {
        return;
      }

  }
  else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    use(result, player);
  }
}
