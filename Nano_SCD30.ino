#include <SparkFun_SCD30_Arduino_Library.h>
#include <Wire.h>

#define SERIAL_BAUD_RATE 115200

SCD30 airSensor;

uint16_t co2 = 0;

float Ctemp = 0.00,
      humi = Ctemp; // ,
//      Ftemp = humi;

char str[25];

void setup() {

  Serial.begin(SERIAL_BAUD_RATE);

  Wire.begin();

  while (!airSensor.begin()) {

    Serial.println("*");
    delay(1000);

  }

}

void loop() {

  if (airSensor.dataAvailable()) {

    co2 = airSensor.getCO2();
    Ctemp = airSensor.getTemperature();
    humi = airSensor.getHumidity();
    //    Ftemp = (Ctemp * 1.8) + 32.0;   // Fahrenheit

//    sprintf(str, "%d%.2f%.2f", co2, Ctemp, humi);
//
//    Serial.println(str);

    Serial.print(co2);
    Serial.print("*");
    Serial.print(Ctemp);
    Serial.print("*");
    Serial.print(humi);
    Serial.println();
    //    Serial.print("*");
    //    Serial.print(Ftemp);
    //    Serial.println();

  }

}
