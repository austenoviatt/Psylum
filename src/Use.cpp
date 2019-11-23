#include "Use.h"
#include "Player.h"

#include <iostream>

using namespace std;

Use::Use() {}

void Use::use(std::vector<std::string> result, Player player) {
  std::string item = result[1];
  if ( item == "poisoncoffee") {
    if (result[2] == "") {
      cout << "You know you put poison into the coffee. You did it yourself. But you decide to drink the coffee anyways. I guess that’s one way to escape.";
      // game.die();

    } else if (result[2] == "doctor"
               && result[2] == player.currentRoom->characters[0].getName()) {
      cout << "You extend the cup of coffee to the doctor. He takes it impatiently and quickly downs the whole cup. You’re not sure how he didn’t burn himself, it was very hot. You also aren’t sure how he didn’t taste all the chemicals you mixed into the coffee. He starts to convulse and begins to bleed profusely from most of his orifices. You look away in horror. Quickly the noises he is making subsides and when you look back, he is dead.";
//      player.inventory.removeItem();//ITEMMAP.NAME)
      player.currentRoom->characters[0].killChara();

    } else
      cout << "You can't use that here." << endl;

  } else if (item == "sedative") {
    if (result[2] == "") {
      cout << "You inject yourself with the sedatives. You have always wondered what it feels like to be drugged. As you slowly lose your grip on consciousness, a doctor comes towards you and picks you up, and you finally slip into oblivion. When you come to a few hours later, you are back in your room, strapped to your bed. There is no way to get out now.";
      //game.die();
    } else if (result[2] == "annabelle"
               && result[2] == player.currentRoom->characters[0].getName()) {
      cout << "Annabelle’s screams slowly get quieter. When they finally stop, you sigh with relief, she won’t be causing you problems any time soon.";
//    player.inventory.removeItem();//ITEMMAP.NAME)
      player.currentRoom->characters[0].killChara();
    } else
      cout << "You can't use that here." << endl;

  }

  else if (item == "worm") {
    if (result[2] == "bonez"
        && result[2] == player.currentRoom->characters[0].getName()) {

      cout << "'This is exactly what I need to catch that fish!’ shouts Bonez. You watch as he starts to put the worm on the hook of the fishing rod. He pauses, looking between the toilet and the worm and the hook. After a minute of contemplating, Bonez tosses the fishing rod at you and exclaims ‘Ah! You know, I only wanted to catch that fish so I could have a friend to keep me company. I don’t need to catch him now because you brought me a different friend, and this one is even better because he fits in my pocket! Keep the fishing rod pal, I don’t need it any more!’ You stick the fishing rod into your pocket.";
//      player.inventory.removeItem(worm);
//      player.inventory.addItem(fishingrod);
    } else
      cout << "You can't use that here.";
  } else if (item == "coffee") {
    if (result.size() == 2) {
      cout << "You don't want coffee right now." << endl;
      //player.inventory.removeItem(coffee);
    } else if (result[2] == "doctor"
               && result[2] == player.currentRoom->characters[0].getName()) {
      cout << "You extend the cup of coffee to the doctor. He takes it impatiently and quickly downs the whole cup. You’re not sure how he didn’t burn himself, it was very hot. 'Another one!' he barks at you."
           << endl;
      //player.inventory.removeItem(coffee);
    } else if (result[2] == "ratpoison" && player.inventory.hasItem("ratpoison")) {
      cout << "You combine the coffee and rat poison. This doesn’t feel like the healthiest drink."
           << endl;
      //player.inventory.removeItem(coffee);
      //player.inventory.removeItem(ratpoison);
      //player.inventory.addItem(poisoncoffee);
    } else
      cout << "You can't combine those things. " << endl;
  } else if (item == "ratpoison") {
    if (result.size() == 2)
      cout << "You can't do that." << endl;
    else if (result[2] == "ratpoison" && player.inventory.hasItem("coffee")) {
      cout << "You combine the rat poison and coffee. This doesn’t feel like the healthiest drink."
           << endl;
      //player.inventory.removeItem(coffee);
      //player.inventory.removeItem(ratpoison);
      //player.inventory.addItem(poisoncoffee);
    } else
      cout << "You can't combine those things. " << endl;
  } else if (item == "magnet") {
    if (result.size() == 2)
      cout << "You can't do that." << endl;
    else if (result[2] == "fishingrod" && player.inventory.hasItem("fishingrod")) {
      cout << "You stick the magnet onto the paperclip hook. It doesn’t seem like the most durable way to do things, but you don’t have any glue or tape so this will have to do. You now have a magnet rod!"
           << endl;
      //player.inventory.removeItem(magnet);
      //player.inventory.removeItem(fishingrod);
      //player.inventory.addItem(magnetrod);
    } else
      cout << "you can't combine those things." << endl;
    if (result.size() == 2)
      cout << "You can't do that." << endl;
    else if (result[2] == "magnet" && player.inventory.hasItem("magnet")) {
      cout << "You stick the magnet onto the paperclip hook. It doesn’t seem like the most durable way to do things, but you don’t have any glue or tape so this will have to do. You now have a magnet rod!"
           << endl;
      //player.inventory.removeItem(magnet);
      //player.inventory.removeItem(fishingrod);
      //player.inventory.addItem(magnetrod);
    } else
      cout << "you can't combine those things." << endl;
  } else if (item == "magnetrod") {
    if (result.size() == 2)
      cout << "You can't do that." << endl;
    else if (((result[2] == "window")||(result[2] == "keycard"))
             && player.currentRoom->inventory.hasItem("keycard")) {
      std::cout <<
                "You toss the magnet out the window and towards the keycard on the ground. It takes a few tries before you get it close enough that the magnet sticks to the card. You pull the card up to you and as you remove it from the magnet, the whole magnet rod falls apart in your hands. Oh well, you probably wont need it again."
                << std::endl;
      //player.inventory.removeItem(magnetrod);
      //player.inventory.addItem(keycard);
      //player.currentRoom->inventory.removeItem(keycard);
    }
  } else if (item == "coffeemaker") {
    if (result.size() > 2) {
      std::cout << "You can't combine those things." << endl;
    } else if (player.currentRoom->inventory.hasItem("coffeemaker")) {
      if (player.inventory.hasItem("coffee")) {
        std::cout << "You already have a coffee, you don't need another." << endl;
      } else
        std::cout <<
                  "You start the coffee maker and quickly a cup is filled with boiling hot coffee. You pick up the coffee."
                  << endl;
    } else
      std::cout << "You can't use that." << endl;
  } else if (item == "window") {
    std::cout << "You can't do that." << endl;
  } else if (item == "journal") {
    if (!player.currentRoom->inventory.hasItem("journal")) {
      std::cout << "You can't do that." << endl;
    } else if (result.size() > 2)
      std::cout << "You can't combine those things." << endl;
    else {/**********/}
  } else if (item == "roomkey") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "roomkey") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("roomkey");
          std::cout <<
                    "The card slides through the card reader and a red light flickers to green above the patients door. It looks like you can go in there now. None of the other doors on this floor have card readers, so you throw the key card away."
                    << endl;
        }
      }
  } else if (item == "button2") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "button2") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("button2");
          std::cout <<
                    "You press the number 2 button into the spot right below the 3 button on the elevator panel. The metal connections seem to snap right in place and the button lights up. You should be able to visit the second floor now."
                    << endl;
        }
      }
  } else if (item == "button1") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "button1") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("button1");
          std::cout <<
                    "Like with the number 2 button, the number 1 button snaps into place and lights up. You can now visit the first floor."
                    << endl;
        }
      }
  } else if (item == "keycard") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "keycard") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("keycard");
          std::cout <<
                    "The keycard slides smoothly into the card slot. You don’t hear anything happen, but the basement button lights up. You can now visit the basement."
                    << endl;
        }
      }
  } else if (item == "claw") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "claw") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("claw");
          std::cout <<
                    "As you lift the claw towards the slot in the wall, it almost jumps out of your hand and into the wall of its own accord. The designs on the wall start to rotate until they all align and a doorway opens up into the room beyond."
                    << endl;
        }
      }
  } else if (item == "magicmushroom") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "magicmushroom") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("magicmushroom");
          std::cout <<
                    "You pop the mushrooms into you mouth and chew. They have an earthy taste, with a strange lingering heat, like you just ate a habenero pepper. The mushrooms also see to have another lingering effect, and the room starts to swirl around you. You feel like you’re losing touch with reality and feel yourself transform into a dragon, wings, scales, fire breath and all. This is not how you expected your day to go. As you explore the room and your new dragon body, every fiery exhale seems to melt more and more of the ice. And then, as suddenly as it came on, you are back in your own body, and the ice is all melted. You aren’t entirely sure what just happened."
                    << endl;
        }
      }
  } else if (item == "crowbar") {
    for (uint i = 0; i < player.currentRoom->exits.size(); i++)
      if ( player.currentRoom->exits[i]->getKey() == "crowbar") {
        if (result.size() > 2) {
          std::cout << "You can't combine those things." << std::endl;
        } else {
          player.currentRoom->exits[i]->setLock(false);
          player.inventory.removeItem("crowbar");
          std::cout <<
                    "You use the crowbar to pry open the closet door. You can now go into the closet."
                    << endl;
        }
      }
  }
}
