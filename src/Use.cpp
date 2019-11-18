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
     // die();

    } else if (result[2] == "doctor" && result[2] == player.currentRoom->characters[0].getName()) {
      cout << "You extend the cup of coffee to the doctor. He takes it impatiently and quickly downs the whole cup. You’re not sure how he didn’t burn himself, it was very hot. You also aren’t sure how he didn’t taste all the chemicals you mixed into the coffee. He starts to convulse and begins to bleed profusely from most of his orifices. You look away in horror. Quickly the noises he is making subsides and when you look back, he is dead.";
//      player.inventory.removeItem();//ITEMMAP.NAME)
      player.currentRoom->characters[0].killChara();

    } else
      cout << "You can't use that here." << endl;

  } else if (item == "sedative") {
    if (result[2] == "") {
      cout << "You inject yourself with the sedatives. You have always wondered what it feels like to be drugged. As you slowly lose your grip on consciousness, a doctor comes towards you and picks you up, and you finally slip into oblivion. When you come to a few hours later, you are back in your room, strapped to your bed. There is no way to get out now.";
      //die();
    } else if(result[2] == "annabelle" && result[2] == player.currentRoom->characters[0].getName()) {
    cout << "Annabelle’s screams slowly get quieter. When they finally stop, you sigh with relief, she won’t be causing you problems any time soon.";
//    player.inventory.removeItem();//ITEMMAP.NAME)
    player.currentRoom->characters[0].killChara();
    }
else cout << "You can't use that here." << endl;

    }

  else if (item == "worm") {
    if (result[2] == "bonez" && result[2] == player.currentRoom->characters[0].getName()) {

      cout << "'This is exactly what I need to catch that fish!’ shouts Bonez. You watch as he starts to put the worm on the hook of the fishing rod. He pauses, looking between the toilet and the worm and the hook. After a minute of contemplating, Bonez tosses the fishing rod at you and exclaims ‘Ah! You know, I only wanted to catch that fish so I could have a friend to keep me company. I don’t need to catch him now because you brought me a different friend, and this one is even better because he fits in my pocket! Keep the fishing rod pal, I don’t need it any more!’ You stick the fishing rod into your pocket.";
//      player.inventory.removeItem(worm);
//      player.inventory.addItem(fishingrod);
    }
    else cout << "You can't use that here.";
  }
  else if (item == "coffee") {

  }
  else if (item == "ratpoison") {}
  else if (item == "magnet") {}
  else if (item == "fishingrod") {}
  else if (item == "magnetrod") {}
  else if (item == "coffeemaker") {}
  else if (item == "window") {}
  else if (item == "journal") {}
  else if (item == "roomkey") {}
  else if (item == "button2") {}
  else if (item == "button1") {}
  else if (item == "keycard") {}
  else if (item == "claw") {}
  else if (item == "magicmushroom") {}
  else if (item == "crowbar") {}


}
