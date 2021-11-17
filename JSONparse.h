#include <Arduino_JSON.h>

void parseMessage(char json[])
{
  Serial.print("Beginning input: ");
  Serial.println(json);
  JSONVar myObject = JSON.parse(json);
  Serial.println(myObject);
  
  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
    Serial.println(myObject);
    //return;
  }
  
  // For each of my global variables, chek to see if they need to be updated
  if (myObject.hasOwnProperty("updateTime_ms")) {
    fogger_humid_off = myObject["updateTime_ms"];
    Serial.print("Updated updateTime_ms: ");
    Serial.println(updateTime_ms);
  }
  if (myObject.hasOwnProperty("fogger_humid_off")) {
    fogger_humid_off = myObject["fogger_humid_off"];
    Serial.print("Updated fogger_humid_off: ");
    Serial.println(fogger_humid_off);
  }
  if (myObject.hasOwnProperty("fogger_humid_on")) {
    fogger_humid_on = myObject["fogger_humid_on"];
    Serial.print("Updated fogger_humid_on: ");
    Serial.println(fogger_humid_on);
  }
  if (myObject.hasOwnProperty("max_fogger_on_cycles")) {
    max_fogger_on_cycles = myObject["max_fogger_on_cycles"];
    Serial.print("Updated max_fogger_on_cycles: ");
    Serial.println(max_fogger_on_cycles);
  }
  if (myObject.hasOwnProperty("fogger_on_time_per_cycle")) {
    max_fogger_on_cycles = myObject["fogger_on_time_per_cycle"];
    Serial.print("Updated fogger_on_time_per_cycle: ");
    Serial.println(fogger_on_time_per_cycle);
  }    
}
