/**
 * Castor, 2019
 * @author Austen Oviatt
 * @date November 15, 2019
 */

 #ifndef EVENTS_H
 #define EVENTS_H

 /**
 * This class is for room events
 */

 #include <string>
 #include <vector>

 class Events{
 public:
   /**
   * default constructor
   * @param name the name of the event
   * @param stage what stage in the event the player is
   */
   Events(std::string name = "DEFAULT EVENT NAME", std::string eventDescription = "DEFAULT EVENT DESCRIPTION", int eventCounter = 0);

   /**
   * Default destructor
   */
   ~Events();

   /**
   * returns name of the event
   * @return string name of event
   */
   std::string getName();

   /**
   * prints the description of the event
   */
   std::string getDesc();

   /**
   * returns status of the event
   * @return event status of event
   */
   int getEventCounter();

   /**
   * increase eventCounter by 1
   */
    void addEventCounter();

 private:
   std::string name;
   std::string eventDescription;
   int eventCounter;
 };

 #endif // EVENTS_H
