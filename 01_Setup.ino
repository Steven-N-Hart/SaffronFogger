void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_wifi();
  Serial.println('*********************************');
  
  setupCloudIoT(); // Creates globals for MQTT
  pinMode(LED_BUILTIN, OUTPUT);

  // Print temperature sensor details (DHT)
  dhttop.begin();
  dhtbot.begin();

  // Define the output pin and set it low initially (so it doesn't corrode as fast)
  pinMode(waterSensorPin, OUTPUT);
  digitalWrite(waterSensorPin, LOW);

  // Do the same for the TDS meter
  pinMode(TdsSensorPin, OUTPUT);
  digitalWrite(TdsSensorPin, LOW);

  // Now the foogger pin
  pinMode(FoggerPin, OUTPUT);
  digitalWrite(FoggerPin, LOW);
  
  // Set Time
  configTime(0, 0, ntp_primary, ntp_secondary);
  Serial.println("Waiting on time sync...");
  while (time(nullptr) < 1629684973)
  {
      delay(10);
  }
}
