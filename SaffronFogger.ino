// Globals
int updateTime_ms = 600000;
// e.g. 70 = 70% Relative humidity
double fogger_humid_on = 70; 
double fogger_humid_off = 80;
int max_fogger_on_cycles = 5;
int fogger_on_time_per_cycle = 30000;
// Time
#include <TimeLib.h>
#include <time.h>
// Configuration for NTP
const char* ntp_primary = "time.google.com";
const char* ntp_secondary = "pool.ntp.org";
static unsigned long lastMillis = 0;

// Water level sensor
// GPIO14, D5
int waterSensorPin = 14;

//DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
// GPIO5, D1
#define ONE_WIRE_BUS 5
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
float waterTemp = 0.0;


//DHT11_Top
#include <Adafruit_Sensor.h>
#include <DHT.h>
// GPIO12, D6
#define DHTPIN_TOP 12
#define DHTTYPE    DHT11
DHT dhttop(DHTPIN_TOP, DHTTYPE);

//DHT11_BOTTOM
// GPIO0, D3
#define DHTPIN_BOT 0
DHT dhtbot(DHTPIN_BOT, DHTTYPE);


// TDS Meter
// GPIO13, D7
#define TdsSensorPin 13
#define VREF 5.0      // analog reference voltage(Volt) of the ADC
#define SCOUNT  30    // sum of sample point
int analogBuffer[SCOUNT];    // store the analog value in the array, read from ADC
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,tdsValue = 0;


// Fogger
// GPIO4, D2
int FoggerPin = 4;

// Analog read
// A0
int analogPin = A0;

// Wifi
#include "esp8266_mqtt.h";
