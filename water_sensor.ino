// min72  max 355
float getLiquidLevel()
{
  digitalWrite(waterSensorPin, HIGH);
  delay(10);                              // wait 10 milliseconds
  float val = analogRead(analogPin);      // Read the analog value form sensor
  digitalWrite(waterSensorPin, LOW);
  return val;
}
