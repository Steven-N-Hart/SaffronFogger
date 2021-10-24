#include "dht_calc.h" 
#include "fogger.h"

void loop()
{
  
  if (!mqtt->loop())
  {
    mqtt->mqttConnect();
  }
  
  delay(10); // <- fixes some issues with WiFi stability
  if (millis() - lastMillis > updateTime_ms)
  {
    lastMillis = millis();
    
    String c = "{ \"IPAdd\": \"";
    c += WiFi.localIP().toString().c_str();
    
    c += "\", \"Time\": \"";
    
    time_t t = time(nullptr);
    c += year(t);
    c +=":";
    c += month(t); 
    c +=":";
    c += day(t);
    c +=":";
    c += hour(t);
    c +=":";
    c += minute(t);
    c += ":";
    c += second(t);

    sensors.requestTemperatures(); 
    waterTemp = sensors.getTempCByIndex(0);
    
    c += "\", \"WaterTemp\": ";
    c += waterTemp;
    
    delay(100);
    c += ", \"AirTempTop\": ";
    c += getTemp("c", 1);
    c += ", \"AirTempBot\": ";
    c += getTemp("c", 2);
    
    delay(100);
    // Get humidity event and print its value.
    c += ", \"RelHumTop\": ";
    float htop = getTemp("h", 1);
    float hbot = getTemp("h", 2);
    
    c += htop;
    c += ", \"RelHumBot\": ";
    c += hbot;

    // Determine whether or not to turn on fogger
    turnonfog(htop, hbot);
    
    // measure liquidLevel
    c += ", \"LiquidLevel\": ";
    c += getLiquidLevel();
    delay(100);

    // Measure PPM
    c += ", \"PPM\": ";
    c += getPPM();
    delay(100);
    
    c += ", \"updateTime_ms\": ";
    c += updateTime_ms;
    c += ", \"fogger_humid_off\": ";
    c += fogger_humid_off;
    c += ", \"fogger_humid_on\": ";
    c += fogger_humid_on;

    c += ", \"max_fogger_on_ms\": ";
    c += max_fogger_on_ms;
    c += " }";
      
     publishTelemetry(c);
     Serial.println(c);
  }
}
