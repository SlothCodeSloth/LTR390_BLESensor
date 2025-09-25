/*************************************************** 
  This is an example for the LTR390 UV Sensor

  Designed specifically to work with the LTR390 UV sensor from Adafruit
  ----> https://www.adafruit.com

  These sensors use I2C to communicate, 2 pins are required to  
  interface
 ****************************************************/
 
#include <ArduinoBLE.h>
#include "Adafruit_LTR390.h"

// Define a custom service UUID
BLEService uvService("19B10000-E8F2-537E-4F6C-D104768A1214");
// Define a custom characteristic UUID
BLEByteCharacteristic uvCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

const int ledPin = LED_BUILTIN; // pin to use for the LED

/// Adafruit_LTR390 ltr = Adafruit_LTR390();

void setup() {
  randomSeed(analogRead(0));

  Serial.begin(115200);
  while (!Serial); 

  pinMode(ledPin, OUTPUT);

  /*
  Serial.println("Adafruit LTR-390 test");

  if ( ! ltr.begin() ) {
    Serial.println("Couldn't find LTR sensor!");
    while (1) delay(10);
  }
  Serial.println("Found LTR sensor!");

  ltr.setMode(LTR390_MODE_UVS);
  if (ltr.getMode() == LTR390_MODE_ALS) {
    Serial.println("In ALS mode");
  } else {
    Serial.println("In UVS mode");
  }

  ltr.setGain(LTR390_GAIN_1);
  Serial.print("Gain : ");
  switch (ltr.getGain()) {
    case LTR390_GAIN_1: Serial.println(1); break;
    case LTR390_GAIN_3: Serial.println(3); break;
    case LTR390_GAIN_6: Serial.println(6); break;
    case LTR390_GAIN_9: Serial.println(9); break;
    case LTR390_GAIN_18: Serial.println(18); break;
  }

  ltr.setResolution(LTR390_RESOLUTION_16BIT);
  Serial.print("Resolution : ");
  switch (ltr.getResolution()) {
    case LTR390_RESOLUTION_13BIT: Serial.println(13); break;
    case LTR390_RESOLUTION_16BIT: Serial.println(16); break;
    case LTR390_RESOLUTION_17BIT: Serial.println(17); break;
    case LTR390_RESOLUTION_18BIT: Serial.println(18); break;
    case LTR390_RESOLUTION_19BIT: Serial.println(19); break;
    case LTR390_RESOLUTION_20BIT: Serial.println(20); break;
  }

  ltr.setThresholds(100, 1000);
  ltr.configInterrupt(true, LTR390_MODE_UVS);
  */

  //Initialize BLE
  if (!BLE.begin()) {
    Serial.println("Starting BLE Failed"); 
    while (1); 
  }

  // Set the local name that the peripheral advertises
  BLE.setLocalName("UVSensor"); 
  // Add Service
  BLE.setAdvertisedService(uvService); 

  // Add the characteristic to the service 
  uvService.addCharacteristic(uvCharacteristic); 
  // Add Service 
  BLE.addService(uvService); 

  // Set the Initial Value for the characteristic 
  uvCharacteristic.writeValue(0); 
  // Advertise Service 
  BLE.advertise(); 
  Serial.println("BLE initialized.");
  Serial.println("Awaiting connection.");


  // Power Saving
  //digitalWrite(PIN_ENABLE_SENSORS_3V3, LOW);
  //digitalWrite(LED_PWR, LOW);
}

void loop() {
  /*
  ltr.enable(true);
  if (ltr.newDataAvailable()) {
      Serial.print("UV data: "); 
      Serial.println(ltr.readUVS());
  } 
  delay(100);

  Serial.println("Entering Sleep"); 
  ltr.enable(false);
  delay(179900);
  */

  // Wait for BLE central to connect
  BLEDevice central = BLE.central(); 

  //If central device is connected to the peripheral; 
  if (central) {
    Serial.print("Connected to central: "); 
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      Serial.println("Sent Number");
        int value = random(10); 
        uvCharacteristic.writeValue(value); 
        delay(10000);

    }

    /*
    //While the central is still connected
    while (!uvCharacteristic.written()) {}
    Serial.println("Received Connection"); 
    while (central.connected()) {
        // Update characteristic value
        int value = random(10); 
        uvCharacteristic.writeValue(value); 

        // Wait for Acknowledgement from Central Device 
        while (!uvCharacteristic.written());

        if (uvCharacteristic.value()) {
          value = uvCharacteristic.value(); 
          Serial.print("Sleeping for: "); 
          Serial.print(value); 
          Serial.println(" seconds."); 
          delay(10000 * value);
        }
        else {
          Serial.println("Not sleeping"); 
        }
    }
    */

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
