/*
 * getTemp(String req, int dhtCount)
 * returns the temprature related parameters
 * req is string request
 dhtCount is 1 or 2 or 3 as you wish
 * This code can display temprature in:
 * getTemp("c", 1) is used to get Celsius for first DHT
 * getTemp("f", 2) is used to get fahrenheit for 2nd DHT
 * getTemp("k"m 1) is used for Kelvin for first DHT
 * getTemp("hif", 1) is used to get fahrenheit for first DHT
 * getTemp("hic", 2) is used to get Celsius for 2nd DHT
 * getTemp("f", 2) is used to get humidity for 2nd DHT
 */
float getTemp(String req, int dhtCount)
{

if(dhtCount ==1){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h1 = dhttop.readHumidity();
  // Read temperature as Celsius (the default)
  float t1 = dhttop.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f1 = dhttop.readTemperature(true);

  // Compute heat index in Fahrenheit (the default)
  float hif1 = dhttop.computeHeatIndex(f1, h1);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic1 = dhttop.computeHeatIndex(t1, h1, false);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println("Failed to read from DHT sensor1!");
    return 0.000;
  }
  

  // Compute heat index in Kelvin 
  float k1 = t1 + 273.15;
  if(req =="c"){
    return t1;//return Cilsus
  }else if(req =="f"){
    return f1;// return Fahrenheit
  }else if(req =="h"){
    return h1;// return humidity
  }else if(req =="hif"){
    return hif1;// return heat index in Fahrenheit
  }else if(req =="hic"){
    return hic1;// return heat index in Cilsus
  }else if(req =="k"){
    return k1;// return temprature in Kelvin
  }else{
    return 0.000;// if no reqest found, retun 0.000
  }
}// dhttop end


if(dhtCount ==2){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h2 = dhtbot.readHumidity();
  // Read temperature as Celsius (the default)
  float t2 = dhtbot.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f2 = dhtbot.readTemperature(true);

  // Compute heat index in Fahrenheit (the default)
  float hif2 = dhtbot.computeHeatIndex(f2, h2);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic2 = dhtbot.computeHeatIndex(t2, h2, false);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println("Failed to read from DHT sensor2!");
    return 0.000;
  }
  

  // Compute heat index in Kelvin 
  float k2 = t2 + 273.15;
  if(req =="c"){
    return t2;//return Cilsus
  }else if(req =="f"){
    return f2;// return Fahrenheit
  }else if(req =="h"){
    return h2;// return humidity
  }else if(req =="hif"){
    return hif2;// return heat index in Fahrenheit
  }else if(req =="hic"){
    return hic2;// return heat index in Cilsus
  }else if(req =="k"){
    return k2;// return temprature in Kelvin
  }else{
    return 0.000;// if no reqest found, retun 0.000
  }
}// dhtbot end

}//getTemp end
