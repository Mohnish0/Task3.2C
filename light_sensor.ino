#include "thingProperties.h"
#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
float light_intensity;
  String name;
float lux;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  LightSensor.begin();
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  lux = LightSensor.GetLightIntensity(); 
  light_intensity = lux; 

     Serial.println(light_intensity);


  if(light_intensity > 600)
  {
    name ="Sunlight detected";


    delay(400);
  }
  else
  {
    name = "no sunlight detected";
    Serial.println("LIGHT");
    delay(400);

  }

}


/*
  Since LightIntensity is READ_WRITE variable, onLightIntensityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightIntensityChange()  {
  // Add your code here to act upon LightIntensity change
}

/*
  Since Counter is READ_WRITE variable, onCounterChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onCounterChange()  {
  // Add your code here to act upon Counter change
}
