#include <Arduino_JSON.h>

void parseMessage(char json[])
{
  Serial.print("Beginning input: ");
  Serial.println(json);
  JSONVar myObject = JSON.parse(json);

  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }
  
  // For each of my global variables, chek to see if they need to be updated
  
  if (myObject.hasOwnProperty("updateTime_ms")) {
    updateTime_ms = myObject["updateTime_ms"];
  }
  if (myObject.hasOwnProperty("fogger_humid_off")) {
    fogger_humid_off = myObject["fogger_humid_off"];
  }
  if (myObject.hasOwnProperty("fogger_humid_on")) {
    fogger_humid_on = myObject["fogger_humid_on"];
  }
  if (myObject.hasOwnProperty("max_fogger_on_cycles")) {
    max_fogger_on_cycles = myObject["max_fogger_on_cycles"];
  }
  if (myObject.hasOwnProperty("fogger_on_time_per_cycle")) {
    max_fogger_on_cycles = myObject["fogger_on_time_per_cycle"];
  }    
}
