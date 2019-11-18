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

 class Events{
 public:
   /**
   * default constructor
   * @param name the name of the event
   * @param stage what stage in the event the player is
   */
   Events(std::string name = "DEFAULT EVENT NAME", std::string eventDescription = "DEFAULT EVENT DESCRIPTION", unsigned int = 0);

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
   unsigned int getEventCounter();

 private:
   std::string name;
   std::string eventDescription;
   unsigned int eventCounter;
 };

 #endif // EVENTS_H
