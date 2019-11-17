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
   Events(std::string name = "DEFAULT EVENT NAME", std::string eventDescription = "DEFAULT EVENT DESCRIPTION", uint stage = 0);

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
   * returns what point in the event the player is current at
   * @return uint the stage of the event
   */
   uint getStage();

   /**
   * prints the description of the event
   */
   std::string getDesc();

   /**
   * increments stage by 1
   */
   void increaseStageCounter();

 private:
   std::string name;
   std::string eventDescription;
   uint stage;
 };

 #endif // EVENTS_H
