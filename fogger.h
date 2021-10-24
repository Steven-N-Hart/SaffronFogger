 
void turnonfog(double hbot, double htop)
{
    double x = min(hbot, htop);

    if ( x < fogger_humid_on )
    {
        Serial.println('Fogger ON!');
        digitalWrite(FoggerPin, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
      int i = 0;
      while (x < fogger_humid_off){
          digitalWrite(LED_BUILTIN, LOW);
          delay(30);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(30); 
          float htop = getTemp("h", 1);
          float hbot = getTemp("h", 2);
          x = min(hbot, htop);
          i++;
          Serial.print("New humiditity measures: ");
          Serial.print(x);
          Serial.print(", ");
          Serial.println(i);   
          if (i > max_fogger_on_ms)
          {
            break;
          }
        }
      
      digitalWrite(FoggerPin, LOW);
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println('Fogger OFF!');
    }
}
