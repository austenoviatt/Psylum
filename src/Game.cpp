/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Game.h"
#include "Use.h"
#include "Look.h"
#include "Take.h"
#include "Dialogue.h"
#include "mainMenu.h"
#include "Bold.h"
#include<bits/stdc++.h>

Game::Game() {
}
/**
* creates a new game at starting point
*/
void create() {

}

/**
 * Saves game at current state and location
 * @param fileName the name of the file the save game is saved to
 */
void saveGame(string fileName) {

}

/**
 * Loads game from a save file
 * @param fileName the name of the save file being loaded
 */
void loadGame(string fileName) {

}

void Game::getUserInput(Player P) {
  std::string userInput;
  std::cout << "enter: ";
  getline(cin, userInput);
  std::cout << std::endl;
  processCommand(userInput, P);
}

void Game::testLoadGame() {
    Item i1("ratpoison",
          "Half a bag of extremely poisonous substances! Ingredients include arsenic, barium, and thallium.",
          "Rat Poison", false, 0);
  Item i2("journal",
          "A journal, looks like there is a lot of private information written in it.",
          "Journal", true, 0);
  Item i3("sedative", "An injectable drug to knock out patients.", "Sedative",
          false, 0);
  Item i4("crowbar",
          "A metal bar with a single curve end and flattened points with a small fissure for removing nails on the other.",
          "Crowbar", false, 0);
  Item i5("magicmushroom",
          "These mushrooms contain hallucinogens such as psilocybin and psilocin and an extra special ingredient to spice things up.",
          "Magic Mushroom", false, 0);
  Item i6("worm",
          "A soft, slender and tube-like insect with no limbs or eyes. Yum!", "Worm",
          false, 0);
  Item i7("labcoat",
          "A loose-fitting white coat worn by doctors in a laboratory or medical facility.",
          "Lab Coat", false, 0);
  Item i8("window",
          "A small barbed window at the end of the hallway. You can see a metal key card on the ground outside!|A small barbed window at the end of the hallway.",
          "Window", true, 0);
  Item i9("magnet",
          "A small refrigerator magnet which attracts iron and some other materials.",
          "Magnet", false, 0);
  Item i10("fishingrod",
           "A makeshift fishing rod, seemingly made out of part of the bed frame, a thread from someone's clothing, and a paper clip.",
           "Fishing Rod", false, 0);
  Item i11("magnetrod",
           "A make shit fishing rod with a fridge magnet in place of the hook",
           "Magnet Rod", false, 0);
  Item i12("coffeemaker", "An old, barely functioning instant coffee maker",
           "Coffee Maker", true, 0);
  Item i13("coffee", "A piping hot cup of coffee. Mmmmm!", "Coffee", false, 0);
  Item i14("poisoncoffee", "A cup of poison coffee. Better not drink this!",
           "Poison Coffee", false, 0);
  Item i15("roomkey",
           "An employee key card. This looks like it could get you into some secured rooms.",
           "Room Key", false, 0);
  Item i16("button2",
           "A button with the number 2 on it. There are some exposed metal connections on the back.",
           "Button 2", false, 0);
  Item i17("button",
           "A button with the number 1 on it. There are some exposed metal connections on the back.",
           "Button", false, 0);
  Item i18("keycard",
           "A key card with the word 'CLASSIFIED' plastered on the back. I wonder what this will open?",
           "Key Card", true, 0);
  Item i19("claw",
           "There are three animals on the claw, a wolf, a goat and? a cabbage?. It looks like it might fit in somewhere.",
           "Claw", false, 0);
  Item i20("box", "a box that contain a single syringe that says " + boldText(i3.getNiceName()) + " on the label|the box is empty", "Box", true, 0);
  Item i21("cart", "a standard hospital cart with a " + boldText(i20.getNiceName()) + " on the top, with a " + boldText(i15.getNiceName()) + " hanging on the edge", "Cart", true, 0);
  Item i22("chair", "a cheap looking plastic chair", "Chair", true, 0);
  Item i23("boat", "an old boat that's barely floating, it look's like is going to sink anytime, better not put too much weight on it", "Boat", true, 0);
  Item i24("wolf", "the wolf looks back at you with puppy eyes", "Wolf", false, 0);
  Item i25("cabbage", "a huge cabbage, other than that, nothing special", "Huge Cabbage", false, 0);
  Item i26("goat", "the goat just can't keep it's eyes off of the huge cabbage", "Goat", false, 0);
  Item i27("machine", "the machine has hundreds of buttons on it|the machine has hundreds of buttons on it, the first button is missing", "Machine", true, 0);
  Item i28("fridge", "noisy humming fridge looks like it came out of a classic film. A " + boldText(i9.getNiceName()) + " is attached to the fridge door.|noisy humming fridge looks like it came out of a classic film.", "Fridge", true, 0);
  Item i29("bag", "you opened the bag to see what's in there, there is a round metal object that says " + boldText(i16.getNiceName()) + " on it|the bag is empty", "Bag", true, 0);
  Item i30("shelf", "spider webs almost entirely covered the shelf, there is a bag of " + boldText(i1.getNiceName()) + " placed on top of the shelf|spider webs almost entirely covered the shelf", "Shelf", true, 0);
  Item i31("forestcounter", "", "", true, 0);

  Inventory allItems;
  allItems.addItem(i1);
  allItems.addItem(i2);
  allItems.addItem(i3);
  allItems.addItem(i4);
  allItems.addItem(i5);
  allItems.addItem(i6);
  allItems.addItem(i7);
  allItems.addItem(i8);
  allItems.addItem(i9);
  allItems.addItem(i10);
  allItems.addItem(i11);
  allItems.addItem(i12);
  allItems.addItem(i13);
  allItems.addItem(i14);
  allItems.addItem(i15);
  allItems.addItem(i16);
  allItems.addItem(i17);
  allItems.addItem(i18);
  allItems.addItem(i19);
  allItems.addItem(i20);
  allItems.addItem(i21);
  allItems.addItem(i22);
  allItems.addItem(i23);
  allItems.addItem(i24);
  allItems.addItem(i25);
  allItems.addItem(i26);
  allItems.addItem(i27);
  allItems.addItem(i28);
  allItems.addItem(i29);
  allItems.addItem(i30);
  allItems.addItem(i31);


    Character snitch("snitch", "patient", "sketchy looking patient who looks like she want's to help you", true, 0, " ");
    Character evildoctor("evildoctor", "doctor", "he is reading a newspaper, and he is too busy to care about you", true, 0, " ");
    Character bonez("bonez", "patient", "he is standing beside a toilet, fishing rod in hand, it looks like he wants to fish something from the toilet|he is sitting on the mattress, playing with his new friend 'Mr wormington the 3rd'", true, 0, " ");
    Character computer("Computer", "computer", "old, bulky looking computers that's still functional", true, 0, " ");
    Character petowner("petowner", "patient", "desperate pet owner who are stuck with his 3 pets, it looks like he want's you to help him get out of there", true, 0 ," ");
    Character treespirit("treespirit", "treespirit", "the tree spirit takes the form of a tree, it looks like is possible to communicate with him", true, 0, " ");


  std::string startDesc =
    "There's no windows or natural light. You noticed a rolling tray beside your bed, a " + boldText(i22.getNiceName()) + " in the corner, a crack of light coming from the hallway and something written on the wall beside the door...'Type Help'";
  std::string l3Hall1Desc =
    "You enter a long concrete hallway, there is a " + boldText(i21.getNiceName()) + " in front of you, a " + boldText(i20.getNiceName()) +
    " is placed on the top and a pair of " + boldText(i15.getNiceName()) + " is hanging on the edge.|You enter a long concrete hallway, there is a " +
    boldText(i21.getNiceName()) + " in front of you, a " + boldText(i20.getNiceName()) + " is placed on the top.";
  std::string annabelleDesc = std::string(
    "White pale walls covered in harsh lines of overlapping words and pictures. You see a patient, curled up on the edge of the bed, sleeping. ") +
    "There is a " + boldText(i2.getNiceName()) + " on the bedside table.";
  std::string closetDesc =
    "You're in a linens closet. You look around in the closet and find a small " + boldText(i29.getNiceName()) + " hidden under one of the shelves.";
  std::string l3Hall2Desc =
    "You're down the hallway. There's an elevator straight ahead.";
  std::string storageDesc =
    "You've inside a storage room! There is a " + boldText(i4.getNiceName()) + " laying next to the door." +
    "You looked farther into the storage room and noticed there is a wooden " + boldText(i30.getNiceName()) + " in the corner of the room" +
    "|You've inside a storage room! " + "You looked farther into the storage room and noticed there is a wooden " + boldText(i30.getNiceName()) +
    " in the corner of the room";
  std::string elevatorDesc = std::string(
    "You've entered the elevator, there is a floor panel beside you. ") +
    "There are four floors: 3, 2, 1 and 0. The \e[1mbuttons\e[0m are missing for 2 and 1 and a \e[1mkey\e[0m is required for 0.\n" + "Enter " +
    boldText("Go 3") + " to go back to floor 3.|You've entered the elevator, there is a floor panel beside you. " +
    "There are four floors: 3, 2, 1 and 0. The \e[1mbutton\e[0m is missing for 1 and a \e[1mkey\e[0m is required for 0.\n" + "Enter " +
    boldText("Go <number>") + " to go to the corresponding floor.|You've entered the elevator, there is a floor panel beside you. " +
    "There are four floors: 3, 2, 1 and 0. A \e[1mkey\e[0m is required for 0.\n" + "Enter " +
    boldText("Go <number>") + " to go to the corresponding floor.|You've entered the elevator, there is a floor panel beside you. " +
    "There are four floors: 3, 2, 1 and 0.\n" + "Enter " + boldText("Go <number>") + " to go to the corresponding floor.";


  Room R;
  Room startRoom ("Patient Room", startDesc, "black", false, {}, "", {}, 0, {});
// ldesc = "You have woken up in an unusual place, eyes slowly coming to focus on the naked bulb above you. Your body feels heavy and your head is throbbing. Your nostrils fill with a stagnant smell. As you begin to slowly move yours eyes around the room, you notice something strange...there's no windows or natural light. You pull yourself up and notice a small metal rolling tray beside your bed, a chair in the corner, a crack of light coming from the hallway and something written on the wall beside the door...'GET OUT'".

  Room l3Hall1 ("Hallway 1", l3Hall1Desc, "hallway", false, {}, "", {}, 0, {});
// ldesc = "You enter a long concrete hallway. There's a door to your left with a key card slot, a door to your right, another door further down the hallway and an elevator at the end. As you're observing the situation, you hear voices from the elevator getting closer and closer. Suddenly a scream and DING! The elevator is about to open."

  Room patient2("Annabelle's Room", annabelleDesc, "red", true, {/*journal*/},
                "roomkey", {}, 0, {snitch});
// lsdesc = "You enter a room, no more than ten feet in any dimension. White pale walls covered in harsh lines of overlapping words and pictures. You see a little girl, curled up on the edge of the bed, sleeping and a journal on a small metal beside table."

  Room closet("Closet", closetDesc, "purple", false, {/*ratPoison*/}, "", {}, 0, {});
// lsdesc = "You quickly get in and shut the door behind you. You're in a linens closet. The elevator opens and the screaming stops. The voices reach the door across from you. Swish, click, BEEP. "Thank you for your help, but I'll take it from here." says a female voice. The door slams shut and the footsteps begin to fade. You look around in the closet and find a small bag hidden under one of the shelves.

  Room l3Hall2("Hallway", l3Hall2Desc, "hallway", false, {}, "", {}, 0, {});
// lsdesc = "You're down the hallway. There's a door to your right and an elevator straight ahead. "

  Room storage("Storage Room", storageDesc, "white", false, {/*crowBar, button2*/},
               "", {}, 0, {});
// lsdesc = "You've found a storage room! You could make use of some these items. Would you like to look around or go back?"

  Room elevator("Elevator", elevatorDesc, "elevator", false, {}, "", {}, 0, {});
// ldesc = "You've entered the elevator and the doors shut behind you. There are four floors: 3, 2, 1 and 0. The buttons are missing for 2 and 1 and a key is required for 0. What do you want to do?"

  std::vector<Room*> startExits{&R, &R, &l3Hall1, &R};
  std::vector<Room*> l3Hall1Exits{&startRoom, &patient2, &l3Hall2, &closet};
  std::vector<Room*> patient2Exits{&R, &R, &R, &l3Hall1};
  std::vector<Room*> closetExits{&R, &l3Hall1, &R, &R};
  std::vector<Room*> l3Hall2Exits{&l3Hall1, &R, &elevator, &storage};
  std::vector<Room*> storageExits{&R, &l3Hall2, &R, &R};
  std::vector<Room*> rExits{&R, &R, &R, &R};

  startRoom.setExit(startExits);
  l3Hall1.setExit(l3Hall1Exits);
  l3Hall2.setExit(l3Hall2Exits);
  closet.setExit(closetExits);
  storage.setExit(storageExits);
  patient2.setExit(patient2Exits);

  R.setExit(rExits);

//***********************************************************
// Floor 2
//***********************************************************

  std::string l2Hall1Desc =
    "You're on the second floor.";
  std::string spaceshipDesc =
    "Hundreds of flickering lights, buttons, levers, switches and geometric angles. This room looks like the inside of a spaceship! There is a futuristic looking " + boldText(i27.getNiceName()) + " in the middle of the room";
  std::string forestDesc =
    "You feel a light breeze and mist on your face when you walk in. You begin to feel your bare feet sinking into dirt...Dirt?! Ew! Theres a " +
    boldText(i6.getNiceName()) + " between your toes! You look up to find yourself in a fractal forest like none ever before. " +
    "Vivid colours bursting in a kaleidoscope and in the middle, a very large tree. " +
    "The tree has a face, and he introduced himself as the \e[1mtree spirit\e[0m.|You look up to find yourself in a fractal forest like none ever before. " +
    "Vivid colours bursting in a kaleidoscope and in the middle, a very large tree. The tree has a face, and he introduced himself as the \e[1mtree spirit\e[0m.";
  std::string l2Hall2Desc =
    "You're down the hallway.";
  std::string doctorDesc =
    "You've successfully broken in! A grey painted office with no window and book shelves surrounding it. On the mahogany desk sat a "
    + boldText(computer.getID()) + ", a stack of papers and a pen, and behind it, a swivel leather chair and bookshelves bursting with olds books. " +
    "In the corner, a " + boldText(i7.getNiceName()) + " hanging on a coat rack.|A grey painted office with no window and book shelves surrounding it. " +
    "On the mahogany desk sat a " + boldText(computer.getID()) + ", a stack of papers and a pen, and behind it, " +
    "a swivel leather chair and bookshelves bursting with olds books.";
  std::string loungeDesc = std::string(
    "The smell of a medicine cabinet and coffee comes wafting from what looks like an employees lounge. ") +
    "An old TV sitting on top of empty shelves. In the back, there is a " + boldText(i12.getNiceName()) +
    " on a small corner kitchen and a few round tables filled with loud chatter. You noticed a " + boldText(evildoctor.getName()) +
    " sitting on a sofa, busy reading his newspaper.";


  Room l2Hall1("Floor 2 Hallway", l2Hall1Desc, "hallway", true, {}, "button2", {}, {/*unlock2*/}, {});
// ldesc = "You're on the second floor. There's a long hallway with a door to your left, a door to your right and two more doors down the hall."

  Room spaceship("Spaceship Room", spaceshipDesc, "rainbow", true, {/*button1*/},
                 "", {}, {}, {});
// ldesc = "Hundreds of flickering lights, buttons, levers, switches and geometric angles. This room looks like the inside of a spaceship!"

  Room forest("Fractal Forest", forestDesc, "yellow", false, {/*mushrooms, worm, claw*/},
              "", {}, {/*treeRiddle*/}, {treespirit});
// ldesc = "You feel a light breeze and mist on your face when you walk in. You begin to feel your bare feet sinking into dirt...Dirt?! Ew! Theres a worm between your toes! You look up to find yourself in a fractal forest like none ever before. Vivid colours bursting in a kaleidoscope and in the middle, a very large tree. Then suddenly...CLICK, CLICK, CLICK, CLICK, CLICK. Hundreds of tiny white faceless creatures with heads that click side to side like mini ticking clocks, begin crawling out from under ground. They're moving away from you! Should you follow or turn back?"

  Room l2Hall2("Hallway", l2Hall2Desc, "hallway", false, {}, "", {}, {}, {});
// ldesc = "You're down the hallway. There's sliding doors to your left and a door to your right labeled "Doctor's Office."

  Room doctors("Doctor's Office", doctorDesc, "green", true, {/*labCoat*/},
               "crowbar", {}, {/*unlockOffice, getSpaceCode*/}, {computer});
// ldesc = "You've successfully broken in! A grey painted office with only one window and book shelves surrounding it. On the mahogany desk sat a computer, a stack of papers and a pen, and behind it, a swivel leather chair and bookshelves bursting with olds books. In the corner, a lab coat hanging on a coat rack."

  Room lounge("Employee's Lounge", loungeDesc, "pink", false, {}, "", {}, {/*coffeePuzzle, killDoctor*/}, {evildoctor});
// ldesc = "As the doors open, the smell of a medicine cabinet and coffee comes wafting from what looks like an employees lounge. Brown cracked leather couches pushed against the undecorated walls. An old TV sitting on top of empty shelves. In the back, a small corner kitchen and a few round tables filled with loud chatter. All the employees are wearing nurse uniforms, except for one...the doctor."

//Room elevator("Elevator", "ldesc", "elevator", false, {}, "", {}, {}, {});
// ldesc = "You've entered the elevator and the doors shut behind you. There are four floors: 3, 2, 1 and 0. The button is missing for 2 and a key is required for 0. Where do you want to go?"

  std::vector<Room*> l2Hall1Exits{&l2Hall2, &forest, &elevator, &spaceship};
  std::vector<Room*> spaceshipExits{&R, &l2Hall1, &R, &R};
  std::vector<Room*> forestExits{&R, &R, &R, &l2Hall1};
  std::vector<Room*> l2Hall2Exits{&R, &doctors, &l2Hall1, &lounge};
  std::vector<Room*> doctorsExits{&R, &R, &R, &l2Hall2};
  std::vector<Room*> loungeExits{&R, &l2Hall2, &R, &R};

  l2Hall1.setExit(l2Hall1Exits);
  spaceship.setExit(spaceshipExits);
  forest.setExit(forestExits);
  l2Hall2.setExit(l2Hall2Exits);
  doctors.setExit(doctorsExits);
  lounge.setExit(loungeExits);

//***********************************************************
// Floor 1
//***********************************************************
  std::string l1Hall1Desc =
    "You're on the first floor. You can see a barbed " + boldText(i8.getNiceName()) + " at the very end of the hallway.";
  std::string patient3Desc =
    "Another room with white pale walls, a single flickering light bulb hanging from the ceiling, a small mattress on the floor and a " +
    boldText(bonez.getName()) + " crouched over the toilet with a " + boldText(i10.getNiceName()) + " in his hand.|" +
    "Another room with white pale walls, a single flickering light bulb hanging from the ceiling, a small mattress on the floor and a " +
    boldText(bonez.getName()) + " is sitting on the mattress playing with his new friend 'Mr wormington the 3rd'.";
  std::string kitchenDesc =
    "A dull beige kitchen with aromas of bleach, tea and coffee stained counters, chipped cabinets, large ancient appliances and for sound, a noisy humming " + boldText(i28.getNiceName()) + ".";
  std::string l1Hall2Desc =
    "You're down the hall on the first floor. There's a barbed " + boldText(i8.getNiceName()) + " in front of you.";
  std::string lobbyDesc =
    "You're in the main lobby of the building. There's exit doors in the distance but you've been spotted by security! 'That's the patient who was last seen with the doctor! They run over to question you.'";
  std::string iceDesc = std::string(
    "You walk into a dark, bitterly cold room and the door shuts behind you. ") +
    "You turn on the light switch to find walls of metal sheets covered with growing ice crystals over an inch in length. " +
    "It's not just a room with an ice machine, the entire room itself is an ice machine! " +
    "You attempt to open the door but your palms stick to the icy handle. It's locked! You hear a low rumble...the coolers have turned on. " +
    "If you don't get out soon, you'll freeze to death!";


  Room l1Hall1("Floor 1 Hallway", l1Hall1Desc, "hallway", true, {}, "button", {}, {/*unlock1*/}, {});
// ldesc = "You're on the first floor. There's a long hallway with a door to your left, a door to your right, two more doors down the hall and a window at the end."

  Room patient3("Bonez's Room", patient3Desc, "cyan", false, {/*fishingRod*/},
                "", {}, {/*goFishing*/}, {bonez});
// ldesc = "Another room with white pale walls, a single flickering light bulb hanging from the ceiling, a small mattress on the floor and a young boy crouched over the toilet with a fishing rod."

  Room kitchen("Kitchen", kitchenDesc, "blue", false, {/*magnet*/}, "", {}, {}, {});
// ldesc = "A dull beige kitchen with aromas of bleach, tea and coffee stained counters, chipped cabinets, large ancient appliances and for sound, a noisy humming refrigerator. "

  Room l1Hall2("Hallway", l1Hall2Desc, "hallway", false, {/*keycard*/}, "", {}, {}, {/*getKeyCard*/});
// ldesc = "You're down the hall on the first floor. There's a main lobby to your left, a door labeled ice room to your right and a window cracked open in front of you."

  Room lobby("Main Lobby", lobbyDesc, "magenta", false, {}, "", {}, {/*getCaughtBySecurity*/}, {});
// ldesc = "You're in the main lobby of the building. There's exit doors in the distance but you've been spotted by security! "That's the patient who was last seen with the doctor! They run over to question you."

  Room iceRoom("Ice Room", iceDesc, "orange", false, {}, "", {}, {/*lockl1Hall2, escapeIceRoom*/}, {});
// ldesc = "You walk into a dark, bitterly cold room and the door shuts behind you. You turn on the light switch to find walls of metal sheets covered with growing ice crystals over an inch in length. It's not just a room with an ice machine, the entire room itself is an ice machine! You attempt to open the door but your palms stick to the icy handle. It's locked! You hear a low rumble...the coolers have turned on. If you don't get out soon, you'll freeze to death!"

//Room elevator("Elevator", "ldesc", "elevator", false, {}, "", {}, {}, {});
// ldesc = "You've entered the elevator and the doors shut behind you. There are four floors: 3, 2, 1 and 0. A key is required for 0. Where do you want to go?"

  std::vector<Room*> l1Hall1Exits{&l1Hall2, &kitchen, &elevator, &patient3};
  std::vector<Room*> patient3Exits{&R, &l1Hall1, &R, &R};
  std::vector<Room*> kitchenExits{&R, &R, &R, &l1Hall1};
  std::vector<Room*> l1Hall2Exits{&R, &iceRoom, &l1Hall1, &lobby};
  std::vector<Room*> lobbyExits{&R, &l1Hall2, &R, &R};
  std::vector<Room*> iceRoomExits{&R, &R, &R, &l1Hall2};

  l1Hall1.setExit(l1Hall1Exits);
  patient3.setExit(patient3Exits);
  kitchen.setExit(kitchenExits);
  l1Hall2.setExit(l1Hall2Exits);
  lobby.setExit(lobbyExits);
  iceRoom.setExit(iceRoomExits);

//***********************************************************
// Floor 0 (Basement)
//***********************************************************
  std::string skyrimDesc = std::string(
    "You step out of the elevator and into a basement. There's two flickering lights at the end of a dark tunnel. ")
    + "You walk towards the lights and find an unusual large iron door surrounded with stone walls and skeletons on the ground."
    + "The door is made with ancient designs and carvings and in the middle is what appears to be a space for a " + boldText(i19.getNiceName());
  std::string sewerDesc = std::string(
    "The air around you smells of rotten eggs! You step out into filthy sludge and noticed you are standing on a metal platform. ") +
    "There is another platform on the far end of the tunnel, but is separated from you by the sewage water. A " + boldText(i23.getNiceName()) +
    " lies on the edge of your side of the platform. There is a " + boldText(petowner.getName()) + " standing beside the boat. " +
    "You looked beside the " + boldText(petowner.getName()) + " and saw a " + boldText(i24.getNiceName()) + ", a " + boldText(i26.getNiceName()) +
    " and a " + boldText(i25.getNiceName()) + ". The iron door shuts behind you, there is no way to go back now.";
  std::string endDesc =
    "Congratulations! You've have escaped the asylum! Now go and enjoy the fresh air and smell of freedom before you get 'drugged' back in!";


  Room skyrim("Basement", skyrimDesc, "green", true, {}, "keycard", {}, {/*unlockSkyrim*/}, {});
// ldesc = "You step out of the elevator and into a basement. There's two flickering lights at the end of a dark tunnel. You walk towards the lights and find an unusual large iron door surrounded with stone walls and skeletons on the ground. The door is made with ancient designs and carvings and in the middle is what appears to be a space for a claw."

  Room sewer("Sewer", sewerDesc, "white", true, {}, "claw", {}, {/*unlockSewer*/}, {petowner});
// ldesc = "The air around you smells of rotten eggs! You step out into filthy sludge. You're in a sewer but there's sunlight at the end of the tunnel!"

  Room endRoom("End of Game!", endDesc, "iron", true, {}, "", {}, {/*completeGame*/}, {});
// ldesc = "Congratulations! You've have escaped the asylum! Now go and enjoy the fresh air and smell of freedom before you get 'drugged' back in!"

  std::vector<Room*> skyrimExits{&sewer, &R, &elevator, &R};
  std::vector<Room*> sewerExits{&endRoom, &R, &skyrim, &R};
  std::vector<Room*> endRoomExits{&R, &R, &sewer, &R};
  std::vector<Room*> elevatorExits{&l3Hall2, &l2Hall1, &l1Hall1, &skyrim};

  skyrim.setExit(skyrimExits);
  sewer.setExit(sewerExits);
  endRoom.setExit(endRoomExits);
  elevator.setExit(elevatorExits);

  Inventory playerInventory;
  //playerInventory.addItem(i19);
  playerInventory.addItem(i18);
  playerInventory.addItem(i17);
  playerInventory.addItem(i15);
  playerInventory.addItem(i4);
  playerInventory.addItem(i5);
  playerInventory.addItem(i16);
  playerInventory.addItem(i9);
  playerInventory.addItem(i10);
  playerInventory.addItem(i14);
  //playerInventory.addItem(i13);
  playerInventory.addItem(i7);
  playerInventory.addItem(i6);

  startRoom.inventory.addItem(i22);

  patient2.inventory.addItem(i2);

  l3Hall1.inventory.addItem(i3);
  l3Hall1.inventory.addItem(i15);
  l3Hall1.inventory.addItem(i20);
  l3Hall1.inventory.addItem(i21);

  storage.inventory.addItem(i4);
  storage.inventory.addItem(i30);
  storage.inventory.addItem(i1);

  forest.inventory.addItem(i5);
  forest.inventory.addItem(i6);
  forest.inventory.addItem(i31);

  doctors.inventory.addItem(i7);

  l1Hall1.inventory.addItem(i8);
  l1Hall1.inventory.addItem(i18);

  kitchen.inventory.addItem(i9);
  kitchen.inventory.addItem(i28);

  lounge.inventory.addItem(i12);

  closet.inventory.addItem(i16);
  closet.inventory.addItem(i29);

  spaceship.inventory.addItem(i17);
  spaceship.inventory.addItem(i27);

  sewer.inventory.addItem(i23);
  sewer.inventory.addItem(i24);
  sewer.inventory.addItem(i25);
  sewer.inventory.addItem(i26);

  Player P(&patient3, playerInventory, 0, true, allItems);

  std::cout << "You have woken up in an unusual place, eyes slowly coming to focus on the naked bulb above you. Your body feels heavy and your"
            << "head is throbbing. As you begin to slowly move yours eyes around the room, you notice something strange...\n"
            << "There's no windows or natural light. You noticed a rolling tray beside your bed, a " + boldText(i22.getNiceName()) +
            " in the corner, a crack of light coming from the hallway and something written on the wall beside the door...'" + boldText("Type Help") + "'"
            << std::endl << endl;

  getUserInput(P);
  //so far so good

}
/**
* Processes user input into game commands
* @return string of command the program can understand
*/
string Game::processCommand(string userInput, Player P) {
  if (userInput == "") {
    getUserInput(P);
  }
//  std::string returnStatement;
  string input = userInput;
  //convert userInput into lowercase letters
  transform(input.begin(), input.end(), input.begin(), ::tolower);

  //separate the input by space and store into vector
  std::istringstream ss(input);

  std::string token;
  vector<string> result;

  while (std::getline(ss, token, ' ')) {
    result.push_back(token);
  }

  std::string firstWord = result[0];
  //clean up unnecessary word
  uint counter = 0;
  while (counter < result.size()) {
    if (result[counter] == "with" || result[counter] == "to"
        || result[counter] == "at" || result[counter] == "the"
        || result[counter] == "on" || result[counter] == "door") {
      result.erase(result.begin() + counter);
    } else {
      counter++;
    }
  }
  counter = 0;

  //compare the verb with verb vector
  for (uint i = 0; i < command.size(); i++) {
    for (uint j = 0; j < command[i].size(); j++) {
      if (firstWord == command[i][j]) {
        //found the command, return value of set of command
        switch (i) {
        case 0:
          //std::cout << "gooooo!!!!" << std::endl;
          go(result, P);
          break;
        case 1:
          //std::cout << "look!!!!!!!!" << std::endl;
          look(result, P);
          break;
        case 2:
          //std::cout << "take!!!!!!!!!" << std::endl;
          take(result, P);
          break;
        case 3:
          //std::cout << "useeeeeeeeee!!!!" << std::endl;
          use(result, P);
          break;
        case 4:
          //std::cout << "talk!!!!!!!!!" << std::endl;
          talk(result, P);
          break;
        case 5:
          //std::cout << "help!!!!!!!!!" << std::endl;
          help(result, P);
          break;
        case 6:
          //std::cout << "inventory!!!!!!" << std::endl;
          inventory(P);
          break;
        case 7:
          drop(result, P);
          break;
        }
      }
    }
  }
  //did not find the corresponding command
  std::cout << "Input Invalid" << std::endl << endl;
  getUserInput(P);

}

/**
 * removes an item from an inventory
 * @return a string explaining what happened
 */
void Game::drop(vector<string> result, Player P) {
  if (result.size() == 2) {
    if (result[1] == "labcoat" || result[1] == "wolf" || result[1] == "cabbage" || result[1] == "goat") {
      //drop the item
      //std::cout << "reached heerrrrrrr" << std::endl;
      for (uint i = 0; i < P.inventory.getItems().size(); i++) {
        if (result[1] == P.inventory.getItems()[i].getName()) {
            std::string droppedItem = P.inventory.getItems()[i].getNiceName();
          P.currentRoom->inventory.addItem(P.inventory.getItems()[i]);
          P.inventory.removeItem(P.inventory.getItems()[i]);
          std::cout << "You dropped " << boldText(droppedItem) << " on the ground" << std::endl << endl;
          getUserInput(P);
        }
      }
      std::cout << "You don't have this item in your inventory" << std::endl << endl;
      getUserInput(P);
    }
    else {
      //the item is undroppable
      std::cout << "You can't drop this item" << std::endl << endl;
      getUserInput(P);
    }

  } else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    drop(result, P);
  }
  else {
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
}

/**
 * moves player to specified room
 * @return a string explaining what happened
 */
void Game::go(vector<string> result, Player P) {

  if (result.size() == 2) {
      if (P.currentRoom->getName() == "Elevator") {
          if ((result[1] == "floor3") || (result[1] == "floorthree") || (result[1] == "thirdfloor") || (result[1] == "3")){
            P.moveToRoom(P.currentRoom->exits[0]);
              if(P.currentRoom->getName() == "End of Game!")
                P.win();

            std::cout << P.currentRoom->displayRoomDesc() << std::endl;
            std::cout << P.currentRoom->getExit() << std::endl;
            getUserInput(P);
          }
          else if ((result[1] == "floor2") || (result[1] == "floortwo") || (result[1] == "secondfloor") || (result[1] == "2")){
            if (P.currentRoom->exits[1]->getLocked() == true){
              cout << "That \e[1mbutton\e[0m for that floor is missing!" << endl << endl;
              getUserInput(P);
            }
            else{
            P.moveToRoom(P.currentRoom->exits[1]);

            std::cout << P.currentRoom->displayRoomDesc() << std::endl;
            std::cout << P.currentRoom->getExit() << std::endl;
            getUserInput(P);
            }
          }
          else if ((result[1] == "floor1") || (result[1] == "floorone") || (result[1] == "firstfloor") || (result[1] == "1")){
                          if (P.currentRoom->exits[2]->getLocked() == true){
              cout << "That \e[1mbutton\e[0m for that floor is missing!" << endl << endl;
              getUserInput(P);
                          }
                          else{
            P.moveToRoom(P.currentRoom->exits[2]);

            std::cout << P.currentRoom->displayRoomDesc() << std::endl;
            std::cout << P.currentRoom->getExit() << std::endl;
            getUserInput(P);
                          }
          }
          else if ((result[1] == "basement") || (result[1] == "floor0") || (result[1] == "basementfloor") || (result[1] == "floorzero") || (result[1] == "0")){
                          if (P.currentRoom->exits[3]->getLocked() == true){
              cout << "It looks like access to the basement requires some sort of \e[1mkey card\e[0m." << endl << endl;
              getUserInput(P);
                          }
                          else{
            P.moveToRoom(P.currentRoom->exits[3]);

            std::cout << P.currentRoom->displayRoomDesc() << std::endl;
            std::cout << P.currentRoom->getExit() << std::endl;
            getUserInput(P);
                          }
          }
          else {
            std::cout << "Input Invalid" << std::endl << endl;
            getUserInput(P);
          }
      }
    //travel using door name
    for (uint i = 0; i < P.currentRoom->exits.size(); i++) {


      if (P.currentRoom->exits[i]->getDoorDesc() == result[1]) {

        if (P.currentRoom->exits[i]->getLocked() == false) {
          P.moveToRoom(P.currentRoom->exits[i]);
          if(P.currentRoom->getName() == "End of Game!")
              P.win();

          std::cout << P.currentRoom->displayRoomDesc() << std::endl;
          std::cout << P.currentRoom->getExit() << std::endl;
          getUserInput(P);

        } else if (P.currentRoom->exits[i]->getLocked() == true) {
          std::cout << "the room is locked" << std::endl << endl;
          getUserInput(P);
        }
      }
    }
    if ((result[1] == "forward" || result[1] == "front" )
        && (P.currentRoom->exits[0]->getName() != "a wall")) {
      if (P.currentRoom->exits[0]->getLocked() == false) {
        P.moveToRoom(P.currentRoom->exits[0]);
        if(P.currentRoom->getName() == "End of Game!")
              P.win();

        std::cout << P.currentRoom->displayRoomDesc() << std::endl;
        std::cout << P.currentRoom->getExit() << std::endl;
        getUserInput(P);

      } else if (P.currentRoom->exits[0]->getLocked() == true) {
        std::cout << "the room is locked" << std::endl << endl;
        getUserInput(P);
      }
    } else if ((result[1] == "right")
               && (P.currentRoom->exits[1]->getName() != "a wall")) {
      if (P.currentRoom->exits[1]->getLocked() == false) {
        P.moveToRoom(P.currentRoom->exits[1]);
        if(P.currentRoom->getName() == "End of Game!")
              P.win();

        std::cout << P.currentRoom->displayRoomDesc() << std::endl;
        std::cout << P.currentRoom->getExit() << std::endl;
        getUserInput(P);

      } else if (P.currentRoom->exits[1]->getLocked() == true) {
        std::cout << "the room is locked" << std::endl << endl;
        getUserInput(P);
      }

    } else if ((result[1] == "backward" || result[1] == "back"
                || result[1] == "behind") && (P.currentRoom->exits[2]->getName() != "a wall")) {
      if (P.currentRoom->exits[2]->getLocked() == false) {
        P.moveToRoom(P.currentRoom->exits[2]);
        if(P.currentRoom->getName() == "End of Game!")
              P.win();

        std::cout << P.currentRoom->displayRoomDesc() << std::endl;
        std::cout << P.currentRoom->getExit() << std::endl;
        getUserInput(P);

      } else if (P.currentRoom->exits[2]->getLocked() == true) {
        std::cout << "the room is locked" << std::endl << endl;
        getUserInput(P);
      }
    } else if ((result[1] == "left")
               && (P.currentRoom->exits[3]->getName() != "a wall")) {
      if (P.currentRoom->exits[3]->getLocked() == false) {
        P.moveToRoom(P.currentRoom->exits[3]);
        if(P.currentRoom->getName() == "End of Game!")
              P.win();

        std::cout << P.currentRoom->displayRoomDesc() << std::endl;
        std::cout << P.currentRoom->getExit() << std::endl;

        getUserInput(P);

      } else if (P.currentRoom->exits[3]->getLocked() == true) {
        std::cout << "the room is locked" << std::endl << endl;
        getUserInput(P);
      } else {
        std::cout << "you can't go that way" << std::endl << endl;
        getUserInput(P);
      }
    } else {
      std::cout << "Input Invalid" << std::endl << endl;
      getUserInput(P);
    }

  } else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    go(result, P);
  }
  else {
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
  std::cout << "Input Invalid" << std::endl << endl;
  getUserInput(P);
}
/**
 * prints the list of actions in case the player gets stuck
 * @return a string explaining what happened
 */
void Game::help(vector<string> result, Player P) {
  int inputSize = result.size();
  std::string returnStatement;
  if (inputSize == 1) {
    displayHelp();
    getUserInput(P);
  } else if (inputSize == 2) {
    if (result[1] == "me") {
      displayHelp();
      getUserInput(P);
    } else {
      std::cout << "Input Invalid" << std::endl << endl;
      getUserInput(P);
    }
  } else {
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
  std::cout << "Input Invalid" << std::endl << endl;
  getUserInput(P);
}

/**
 * prints all items in players inventory
 * or else prints that players inventory is empty. a string explaining what happened
 */
void Game::inventory(Player P) {
  if (P.inventory.getItems().size() != 0) {
    std::cout << "In your inventory you have: " << std::endl;
    for (uint i = 0; i < P.inventory.getItems().size(); i++) {
      std::cout<< P.inventory.getItems()[i].getNiceName();
      if ((i + 1) != P.inventory.getItems().size()) {
        std::cout << ", ";
      }
    }
    std::cout << endl << endl;
    getUserInput(P);
  } else {
    std::cout << "Your inventory is empty." << std::endl << endl;
    getUserInput(P);
  }
}

/**
 * prints out description of a room or item or NPC
 * @return a string explaining what happened
 */
void Game::look(vector<string> result, Player P) {
  int inputSize = result.size();

  if (inputSize == 1) {
    std::cout << P.currentRoom->displayRoomDesc() << std::endl << endl;
    getUserInput(P);
  } else if (inputSize == 2) {
    //index 1 is important here
    if (result[1] == "around" || result[1] == "room") {
      std::cout << P.currentRoom->displayRoomDesc() << std::endl << endl;
      getUserInput(P);
    } else if (result[1] == "inventory"|| result[1] == "i" || result[1] == "inv") {
      inventory(P);
    }

    //looping through item on player
    for (uint i = 0; i < P.inventory.getItems().size(); i++) {
      if (result[1] == P.inventory.getItems()[i].getName()) {
        //std::cout << P.inventory.getItems()[i].getItemDesc() << std::endl << endl;
        Look k;
        k.look(P.inventory.getItems()[i], P);
        getUserInput(P);
      }
    }

    //looping through item in room
    for (unsigned int i = 0; i < P.currentRoom->inventory.getItems().size(); i++) {
      if (result[1] == P.currentRoom->inventory.getItems()[i].getName()) {
        //std::cout << P.currentRoom->inventory.getItems()[i].getItemDesc() << std::endl << endl;
        Look k;
        k.look(P.currentRoom->inventory.getItems()[i], P);
        getUserInput(P);
      }
    }

    //looping through the npc in the room
    for (unsigned int i = 0; i < P.currentRoom->characters.size(); i++) {
      if (result[1] == P.currentRoom->characters[i].getName()) {
        if (P.currentRoom->characters[i].isAlive == false) {
          std::cout << boldText(P.currentRoom->characters[i].getName()) <<
                    " past out on the ground." << std::endl << endl;
          getUserInput(P);
        } else {

          //break character description into vectors
          std::istringstream ss(P.currentRoom->characters[i].getDescription());

          std::string token;
          std::vector<std::string> desVector;

          while (std::getline(ss, token, '|')) {
            desVector.push_back(token);
          }

          std::cout << desVector[P.currentRoom->characters[i].getEventCounter()] << std::endl << endl;

          getUserInput(P);
        }
      }
    }
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
  //concat two item name and see if there is a match
  else if (inputSize == 3) {
    result[1] = result[1] + result[2];
    //std::cout << result[1] << std::endl;
    //erase the second item name
    result.erase(result.begin() + 2);
    look(result, P);
  } else {
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
}

/**
 * add an item to players inventory
 * @return a string explaining what happened
 */
void Game::take(vector<string> result, Player P) {
  //int inputSize = result.size();
  //grab player's current location
  if (result.size() == 2) {
    for (uint i = 0; i < P.currentRoom->inventory.items.size(); i++) {
      if (result[1] == P.currentRoom->inventory.items[i].getName()) {
          //check whether player is on the same platform as the pet they want to take
          if (result[1] == "wolf" && (P.allInv.returnItem("wolf").getItemState() != P.allInv.returnItem("boat").getItemState())) {
            std::cout << "You can't take stuff on the other side of the platform!" << std::endl << endl;
            getUserInput(P);
          }
          else if (result[1] == "goat" && (P.allInv.returnItem("goat").getItemState() != P.allInv.returnItem("boat").getItemState())) {
            std::cout << "You can't take stuff on the other side of the platform!" << std::endl << endl;
            getUserInput(P);
          }
          else if (result[1] == "cabbage" && (P.allInv.returnItem("cabbage").getItemState() != P.allInv.returnItem("boat").getItemState())) {
            std::cout << "You can't take stuff on the other side of the platform!" << std::endl << endl;
            getUserInput(P);
          }

        if (!P.currentRoom->inventory.items[i].getFixed()) {
          //item found, pickup item, remove item from room inventory and add it to player inventory
          string itemName = P.currentRoom->inventory.items[i].getNiceName();
          Item item = P.currentRoom->inventory.items[i];

          P.inventory.addItem(P.currentRoom->inventory.items[i]);
          P.currentRoom->inventory.removeItem(P.currentRoom->inventory.items[i]);

          std::cout << "You picked up " << boldText(itemName) << " and put it into your pocket." << std::endl << endl;
          // check if item is related to an event
          Take t;
          t.take(item, &P);

          getUserInput(P);

        } else
          std::cout << "You can't pick " <<
                    boldText(P.currentRoom->inventory.items[i].getNiceName()) << " up." << std::endl << endl;
        getUserInput(P);
      }
    }
  }
  //concat two item name and see if there is a match
  else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    take(result, P);
  }
  std::cout << "Input Invalid" << std::endl << endl;
  getUserInput(P);

}

/**
 * initiate dialogue options with an NPC
 * @return a string explaining what happened
 */
void Game::talk(vector<string> result, Player P) {
  if (result.size() == 2) {
    for (int i = 0; i < P.currentRoom->charaNum(); i++) {
      if (result[1] == P.currentRoom->characters[i].getName()) {
        //npc found, pass the charaID to the talk function under character class
        Character chara = P.currentRoom->characters[i];
        Dialogue d;

        //check whether the character is alive or not
        if (chara.isAlive == false) {
          std::cout << boldText(chara.getName()) << " past out on the ground." << std::endl << endl;
          getUserInput(P);
        } else { //character is alive, decide which character are we talking to
          d.talk(&P.currentRoom->characters[i], &P);
          getUserInput(P);
        }
      }
    }
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
  else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    talk(result, P);
  }
  else {
    std::cout << "Input Invalid" << std::endl << endl;
    getUserInput(P);
  }
}

/**
* use an item inside the inventory
* @return a string explaining what happened
*/
void Game::use(vector<string> result, Player P) {
  Use u;
  u.use(result, &P);
  //std::cout << "Came back fine " << std::endl;
  getUserInput(P);
}

void Game::displayHelp() {
  std::stringstream ss;
  ss << "HELP PAGE" << "\n" << "\n"
     << "Available Commands:" << "\n"
     << "Move around: go forward, go right, go left, go back OR go red door, go blue door……"
     << "\n\n"
     << "Look around: look, look <npc>" << "\n\n"
     << "Items: look <Item>, take <Item>, give <Item>, use <Item>, use <Item1> with <Item2>, use <Item> on <npc>, add <Item1> to <Item2>." "\n\n"
     <<  "Be aware, sometimes the order that you combine items in affects how they are used!"
     << "\n\n"
     << "Talk to npc: talk <npc>" << "\n\n"
     << "Inventory: inventory, inv, i" << "\n";

  std::cout << ss.str() << std::endl << endl;

}

std::string Game::boldText(std::string s) {
  return "\e[1m" + s +"\e[0m";
}
