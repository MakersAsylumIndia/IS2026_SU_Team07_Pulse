#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include "DFRobot_BloodOxygen_S.h"

const char* ssid = "WIFI_NAME";
const char* password = "WIFI_PASSWORD";
String wledAddress = "http://192.168.1.100/json/state";

DFRobot_BloodOxygen_S_I2C MAX30102;

#define EMG_PIN 34

float spo2 = 0;

float heartRate = 0;

float temperatureC = 0;

int emgRaw = 0;

int emgValue = 0;


float styleMultiplier = 1.0;

int r1 = 255;
int g1 = 0;
int b1 = 0;

int r2 = 0;
int g2 = 255;
int b2 = 0;

int r3 = 0;
int g3 = 0;
int b3 = 255;

int effectID = 0;

int effectSpeed = 100;
void setup()
{
    Serial.begin(115200);

    Wire.begin(2, 4);

    pinMode(34, INPUT);

    WiFi.begin(ssid, password);

    Serial.println("Connecting WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi Connected");

    if (!MAX30102.begin())
    {
        Serial.println("MAX30102 FAILED");

        while (1);
    }

    Serial.println("MAX30102 SUCCESS");

    MAX30102.sensorStartCollect();

    Serial.println("System Started");
}

// ======================================================
//                        LOOP
// ======================================================

void loop()
{
    // ==================================================
    //                  SENSOR READINGS
    // ==================================================

    MAX30102.getHeartbeatSPO2();

    spo2 = MAX30102._sHeartbeatSPO2.SPO2;

    heartRate = MAX30102._sHeartbeatSPO2.Heartbeat;

    temperatureC = MAX30102.getTemperature_C();

    emgRaw = analogRead(EMG_PIN);

    emgValue = map(emgRaw, 0, 4095, 60, 100);

    // ==================================================
    //                 SERIAL MONITOR
    // ==================================================

    Serial.println("================================");

    Serial.print("SPO2: ");
    Serial.print(spo2);
    Serial.println("%");

    Serial.print("Heart Rate: ");
    Serial.print(heartRate);
    Serial.println(" BPM");

    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");

    Serial.print("EMG Raw: ");
    Serial.println(emgRaw);

    Serial.print("EMG Value: ");
    Serial.println(emgValue);

    Serial.println("================================");

}
void applyTempratureStyle(){

  if (temperatureC >= 27 && temperatureC < 28)
{
    // TEMP STYLE LOOP 1
    styleMultiplier = 0.52;
}

else if (temperatureC >= 28 && temperatureC < 29)
{
    // TEMP STYLE LOOP 2
    styleMultiplier = 0.64;
}

else if (temperatureC >= 29 && temperatureC < 30)
{
    // TEMP STYLE LOOP 3
    styleMultiplier = 0.76;
}

else if (temperatureC >= 30 && temperatureC < 31)
{
    // TEMP STYLE LOOP 4
    styleMultiplier = 0.88;
}

else if (temperatureC >= 31 && temperatureC < 32)
{
    // TEMP STYLE LOOP 5
    styleMultiplier = 1.0;
}

else if (temperatureC >= 32 && temperatureC < 33)
{
    // TEMP STYLE LOOP 6
    styleMultiplier = 1.12;
}

else if (temperatureC >= 33 && temperatureC < 34)
{
    // TEMP STYLE LOOP 7
    styleMultiplier = 1.24;
}

else if (temperatureC >= 34 && temperatureC < 35)
{
    // TEMP STYLE LOOP 8
    styleMultiplier = 1.36;
}

else if (temperatureC >= 35 && temperatureC < 36)
{
    // TEMP STYLE LOOP 9
    styleMultiplier = 1.48;
}

else if (temperatureC >= 36 && temperatureC < 37)
{
    // TEMP STYLE LOOP 10
    styleMultiplier = 1.6;
}

else if (temperatureC >= 37 && temperatureC < 38)
{
    // TEMP STYLE LOOP 11
    styleMultiplier = 1.72;
}

else if (temperatureC >= 38 && temperatureC < 39)
{
    // TEMP STYLE LOOP 12
    styleMultiplier = 1.84;
}}
void setColourCondition(){

   if (spo2 < 93 && heartRate < 70)
{
    // COLOUR LOOP 1
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 70 && heartRate < 75)
{
    // COLOUR LOOP 2
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 75 && heartRate < 80)
{
    // COLOUR LOOP 3
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 80 && heartRate < 85)
{
    // COLOUR LOOP 4
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 85 && heartRate < 90)
{
    // COLOUR LOOP 5
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 90 && heartRate < 95)
{
    // COLOUR LOOP 6
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 95 && heartRate < 100)
{
    // COLOUR LOOP 7
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 < 93 && heartRate >= 100 && heartRate < 105)
{
    // COLOUR LOOP 8
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate < 70)
{
    // COLOUR LOOP 9
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 70 && heartRate < 75)
{
    // COLOUR LOOP 10
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 75 && heartRate < 80)
{
    // COLOUR LOOP 11
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 80 && heartRate < 85)
{
    // COLOUR LOOP 12
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 85 && heartRate < 90)
{
    // COLOUR LOOP 13
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 90 && heartRate < 95)
{
    // COLOUR LOOP 14
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 95 && heartRate < 100)
{
    // COLOUR LOOP 15
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 93 && spo2 < 95 && heartRate >= 100 && heartRate < 105)
{
    // COLOUR LOOP 16
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate < 70)
{
    // COLOUR LOOP 17
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 70 && heartRate < 75)
{
    // COLOUR LOOP 18
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 75 && heartRate < 80)
{
    // COLOUR LOOP 19
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 80 && heartRate < 85)
{
    // COLOUR LOOP 20
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 85 && heartRate < 90)
{
    // COLOUR LOOP 21
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 90 && heartRate < 95)
{
    // COLOUR LOOP 22
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 95 && heartRate < 100)
{
    // COLOUR LOOP 23
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 95 && spo2 < 97 && heartRate >= 100 && heartRate < 105)
{
    // COLOUR LOOP 24
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate < 70)
{
    // COLOUR LOOP 25
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 70 && heartRate < 75)
{
    // COLOUR LOOP 26
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 75 && heartRate < 80)
{
    // COLOUR LOOP 27
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 80 && heartRate < 85)
{
    // COLOUR LOOP 28
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 85 && heartRate < 90)
{
    // COLOUR LOOP 29
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 90 && heartRate < 95)
{
    // COLOUR LOOP 30
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 95 && heartRate < 100)
{
    // COLOUR LOOP 31
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 >= 97 && spo2 < 99 && heartRate >= 100 && heartRate < 105)
{
    // COLOUR LOOP 32
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate < 70)
{
    // COLOUR LOOP 33
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 70 && heartRate < 75)
{
    // COLOUR LOOP 34
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 75 && heartRate < 80)
{
    // COLOUR LOOP 35
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 80 && heartRate < 85)
{
    // COLOUR LOOP 36
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 85 && heartRate < 90)
{
    // COLOUR LOOP 37
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 90 && heartRate < 95)
{
    // COLOUR LOOP 38
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 95 && heartRate < 100)
{
    // COLOUR LOOP 39
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}

else if (spo2 > 99 && heartRate >= 100 && heartRate < 105)
{
    // COLOUR LOOP 40
    r1 = 255; g1 = 0;   b1 = 0;
    r2 = 0;   g2 = 255; b2 = 0;
    r3 = 0;   g3 = 0;   b3 = 255;
}}
    void setPattercondition(){

if (heartRate < 70 && emgValue < 70)
{
    // PATTERN LOOP 1
    effectID = 1;
    effectSpeed = 41;
}

else if (heartRate < 70 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 2
    effectID = 2;
    effectSpeed = 42;
}

else if (heartRate < 70 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 3
    effectID = 3;
    effectSpeed = 43;
}

else if (heartRate < 70 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 4
    effectID = 4;
    effectSpeed = 44;
}

else if (heartRate < 70 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 5
    effectID = 5;
    effectSpeed = 45;
}

else if (heartRate < 70 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 6
    effectID = 6;
    effectSpeed = 46;
}

else if (heartRate < 70 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 7
    effectID = 7;
    effectSpeed = 47;
}

else if (heartRate < 70 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 8
    effectID = 8;
    effectSpeed = 48;
}

else if (heartRate < 70 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 9
    effectID = 9;
    effectSpeed = 49;
}

else if (heartRate < 70 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 10
    effectID = 10;
    effectSpeed = 50;
}

else if (heartRate < 70 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 11
    effectID = 11;
    effectSpeed = 51;
}

else if (heartRate < 70 && emgValue > 90)
{
    // PATTERN LOOP 12
    effectID = 12;
    effectSpeed = 52;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue < 70)
{
    // PATTERN LOOP 13
    effectID = 13;
    effectSpeed = 53;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 14
    effectID = 14;
    effectSpeed = 54;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 15
    effectID = 15;
    effectSpeed = 55;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 16
    effectID = 16;
    effectSpeed = 56;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 17
    effectID = 17;
    effectSpeed = 57;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 18
    effectID = 18;
    effectSpeed = 58;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 19
    effectID = 19;
    effectSpeed = 59;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 20
    effectID = 20;
    effectSpeed = 60;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 21
    effectID = 21;
    effectSpeed = 61;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 22
    effectID = 22;
    effectSpeed = 62;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 23
    effectID = 23;
    effectSpeed = 63;
}

else if (heartRate >= 70 && heartRate < 75 && emgValue > 90)
{
    // PATTERN LOOP 24
    effectID = 24;
    effectSpeed = 64;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue < 70)
{
    // PATTERN LOOP 25
    effectID = 25;
    effectSpeed = 65;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 26
    effectID = 26;
    effectSpeed = 66;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 27
    effectID = 27;
    effectSpeed = 67;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 28
    effectID = 28;
    effectSpeed = 68;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 29
    effectID = 29;
    effectSpeed = 69;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 30
    effectID = 30;
    effectSpeed = 70;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 31
    effectID = 31;
    effectSpeed = 71;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 32
    effectID = 32;
    effectSpeed = 72;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 33
    effectID = 33;
    effectSpeed = 73;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 34
    effectID = 34;
    effectSpeed = 74;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 35
    effectID = 35;
    effectSpeed = 75;
}

else if (heartRate >= 75 && heartRate < 80 && emgValue > 90)
{
    // PATTERN LOOP 36
    effectID = 36;
    effectSpeed = 76;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue < 70)
{
    // PATTERN LOOP 37
    effectID = 37;
    effectSpeed = 77;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 38
    effectID = 38;
    effectSpeed = 78;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 39
    effectID = 39;
    effectSpeed = 79;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 40
    effectID = 40;
    effectSpeed = 80;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 41
    effectID = 41;
    effectSpeed = 81;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 42
    effectID = 42;
    effectSpeed = 82;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 43
    effectID = 43;
    effectSpeed = 83;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 44
    effectID = 44;
    effectSpeed = 84;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 45
    effectID = 45;
    effectSpeed = 85;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 46
    effectID = 46;
    effectSpeed = 86;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 47
    effectID = 47;
    effectSpeed = 87;
}

else if (heartRate >= 80 && heartRate < 85 && emgValue > 90)
{
    // PATTERN LOOP 48
    effectID = 48;
    effectSpeed = 88;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue < 70)
{
    // PATTERN LOOP 49
    effectID = 49;
    effectSpeed = 89;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 50
    effectID = 50;
    effectSpeed = 90;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 51
    effectID = 51;
    effectSpeed = 91;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 52
    effectID = 52;
    effectSpeed = 92;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 53
    effectID = 53;
    effectSpeed = 93;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 54
    effectID = 54;
    effectSpeed = 94;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 55
    effectID = 55;
    effectSpeed = 95;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 56
    effectID = 56;
    effectSpeed = 96;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 57
    effectID = 57;
    effectSpeed = 97;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 58
    effectID = 58;
    effectSpeed = 98;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 59
    effectID = 59;
    effectSpeed = 99;
}

else if (heartRate >= 85 && heartRate < 90 && emgValue > 90)
{
    // PATTERN LOOP 60
    effectID = 60;
    effectSpeed = 100;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue < 70)
{
    // PATTERN LOOP 61
    effectID = 61;
    effectSpeed = 101;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 62
    effectID = 62;
    effectSpeed = 102;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 63
    effectID = 63;
    effectSpeed = 103;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 64
    effectID = 64;
    effectSpeed = 104;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 65
    effectID = 65;
    effectSpeed = 105;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 66
    effectID = 66;
    effectSpeed = 106;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 67
    effectID = 67;
    effectSpeed = 107;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 68
    effectID = 68;
    effectSpeed = 108;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 69
    effectID = 69;
    effectSpeed = 109;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 70
    effectID = 70;
    effectSpeed = 110;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 71
    effectID = 71;
    effectSpeed = 111;
}

else if (heartRate >= 90 && heartRate < 95 && emgValue > 90)
{
    // PATTERN LOOP 72
    effectID = 72;
    effectSpeed = 112;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue < 70)
{
    // PATTERN LOOP 73
    effectID = 73;
    effectSpeed = 113;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 74
    effectID = 74;
    effectSpeed = 114;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 75
    effectID = 75;
    effectSpeed = 115;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 76
    effectID = 76;
    effectSpeed = 116;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 77
    effectID = 77;
    effectSpeed = 117;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 78
    effectID = 78;
    effectSpeed = 118;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 79
    effectID = 79;
    effectSpeed = 119;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 80
    effectID = 80;
    effectSpeed = 120;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 81
    effectID = 81;
    effectSpeed = 121;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 82
    effectID = 82;
    effectSpeed = 122;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 83
    effectID = 83;
    effectSpeed = 123;
}

else if (heartRate >= 95 && heartRate < 100 && emgValue > 90)
{
    // PATTERN LOOP 84
    effectID = 84;
    effectSpeed = 124;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue < 70)
{
    // PATTERN LOOP 85
    effectID = 85;
    effectSpeed = 125;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 86
    effectID = 86;
    effectSpeed = 126;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 87
    effectID = 87;
    effectSpeed = 127;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 88
    effectID = 88;
    effectSpeed = 128;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 89
    effectID = 89;
    effectSpeed = 129;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 90
    effectID = 90;
    effectSpeed = 130;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 91
    effectID = 91;
    effectSpeed = 131;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 92
    effectID = 92;
    effectSpeed = 132;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 93
    effectID = 93;
    effectSpeed = 133;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 94
    effectID = 94;
    effectSpeed = 134;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 95
    effectID = 95;
    effectSpeed = 135;
}

else if (heartRate >= 100 && heartRate < 105 && emgValue > 90)
{
    // PATTERN LOOP 96
    effectID = 96;
    effectSpeed = 136;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue < 70)
{
    // PATTERN LOOP 97
    effectID = 97;
    effectSpeed = 137;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 98
    effectID = 98;
    effectSpeed = 138;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 99
    effectID = 99;
    effectSpeed = 139;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 100
    effectID = 100;
    effectSpeed = 140;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 101
    effectID = 101;
    effectSpeed = 141;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 102
    effectID = 102;
    effectSpeed = 142;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 103
    effectID = 103;
    effectSpeed = 143;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 104
    effectID = 104;
    effectSpeed = 144;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 105
    effectID = 105;
    effectSpeed = 145;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 106
    effectID = 106;
    effectSpeed = 146;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 107
    effectID = 107;
    effectSpeed = 147;
}

else if (heartRate >= 105 && heartRate < 110 && emgValue > 90)
{
    // PATTERN LOOP 108
    effectID = 108;
    effectSpeed = 148;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue < 70)
{
    // PATTERN LOOP 109
    effectID = 109;
    effectSpeed = 149;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 110
    effectID = 110;
    effectSpeed = 150;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 111
    effectID = 111;
    effectSpeed = 151;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 112
    effectID = 112;
    effectSpeed = 152;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 113
    effectID = 113;
    effectSpeed = 153;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 114
    effectID = 114;
    effectSpeed = 154;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 115
    effectID = 115;
    effectSpeed = 155;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 116
    effectID = 116;
    effectSpeed = 156;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 117
    effectID = 117;
    effectSpeed = 157;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 118
    effectID = 118;
    effectSpeed = 158;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 119
    effectID = 119;
    effectSpeed = 159;
}

else if (heartRate >= 110 && heartRate < 115 && emgValue > 90)
{
    // PATTERN LOOP 120
    effectID = 0;
    effectSpeed = 160;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue < 70)
{
    // PATTERN LOOP 121
    effectID = 1;
    effectSpeed = 161;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 122
    effectID = 2;
    effectSpeed = 162;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 123
    effectID = 3;
    effectSpeed = 163;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 124
    effectID = 4;
    effectSpeed = 164;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 125
    effectID = 5;
    effectSpeed = 165;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 126
    effectID = 6;
    effectSpeed = 166;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 127
    effectID = 7;
    effectSpeed = 167;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 128
    effectID = 8;
    effectSpeed = 168;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 129
    effectID = 9;
    effectSpeed = 169;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 130
    effectID = 10;
    effectSpeed = 170;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 131
    effectID = 11;
    effectSpeed = 171;
}

else if (heartRate >= 115 && heartRate < 120 && emgValue > 90)
{
    // PATTERN LOOP 132
    effectID = 12;
    effectSpeed = 172;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue < 70)
{
    // PATTERN LOOP 133
    effectID = 13;
    effectSpeed = 173;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 134
    effectID = 14;
    effectSpeed = 174;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 135
    effectID = 15;
    effectSpeed = 175;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 136
    effectID = 16;
    effectSpeed = 176;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 137
    effectID = 17;
    effectSpeed = 177;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 138
    effectID = 18;
    effectSpeed = 178;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 139
    effectID = 19;
    effectSpeed = 179;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 140
    effectID = 20;
    effectSpeed = 180;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 141
    effectID = 21;
    effectSpeed = 181;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 142
    effectID = 22;
    effectSpeed = 182;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 143
    effectID = 23;
    effectSpeed = 183;
}

else if (heartRate >= 120 && heartRate < 125 && emgValue > 90)
{
    // PATTERN LOOP 144
    effectID = 24;
    effectSpeed = 184;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue < 70)
{
    // PATTERN LOOP 145
    effectID = 25;
    effectSpeed = 185;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 146
    effectID = 26;
    effectSpeed = 186;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 147
    effectID = 27;
    effectSpeed = 187;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 148
    effectID = 28;
    effectSpeed = 188;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 149
    effectID = 29;
    effectSpeed = 189;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 150
    effectID = 30;
    effectSpeed = 190;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 151
    effectID = 31;
    effectSpeed = 191;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 152
    effectID = 32;
    effectSpeed = 192;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 153
    effectID = 33;
    effectSpeed = 193;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 154
    effectID = 34;
    effectSpeed = 194;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 155
    effectID = 35;
    effectSpeed = 195;
}

else if (heartRate >= 125 && heartRate < 130 && emgValue > 90)
{
    // PATTERN LOOP 156
    effectID = 36;
    effectSpeed = 196;
}

else if (heartRate > 130 && emgValue < 70)
{
    // PATTERN LOOP 157
    effectID = 37;
    effectSpeed = 197;
}

else if (heartRate > 130 && emgValue >= 70 && emgValue < 72)
{
    // PATTERN LOOP 158
    effectID = 38;
    effectSpeed = 198;
}

else if (heartRate > 130 && emgValue >= 72 && emgValue < 74)
{
    // PATTERN LOOP 159
    effectID = 39;
    effectSpeed = 199;
}

else if (heartRate > 130 && emgValue >= 74 && emgValue < 76)
{
    // PATTERN LOOP 160
    effectID = 40;
    effectSpeed = 200;
}

else if (heartRate > 130 && emgValue >= 76 && emgValue < 78)
{
    // PATTERN LOOP 161
    effectID = 41;
    effectSpeed = 201;
}

else if (heartRate > 130 && emgValue >= 78 && emgValue < 80)
{
    // PATTERN LOOP 162
    effectID = 42;
    effectSpeed = 202;
}

else if (heartRate > 130 && emgValue >= 80 && emgValue < 82)
{
    // PATTERN LOOP 163
    effectID = 43;
    effectSpeed = 203;
}

else if (heartRate > 130 && emgValue >= 82 && emgValue < 84)
{
    // PATTERN LOOP 164
    effectID = 44;
    effectSpeed = 204;
}

else if (heartRate > 130 && emgValue >= 84 && emgValue < 86)
{
    // PATTERN LOOP 165
    effectID = 45;
    effectSpeed = 205;
}

else if (heartRate > 130 && emgValue >= 86 && emgValue < 88)
{
    // PATTERN LOOP 166
    effectID = 46;
    effectSpeed = 206;
}

else if (heartRate > 130 && emgValue >= 88 && emgValue < 90)
{
    // PATTERN LOOP 167
    effectID = 47;
    effectSpeed = 207;
}

else if (heartRate > 130 && emgValue > 90)
{
    // PATTERN LOOP 168
    effectID = 48;
    effectSpeed = 208;
}}

void applyStyleToColours()
{
    r1 = r1 * styleMultiplier;
    g1 = g1 * styleMultiplier;
    b1 = b1 * styleMultiplier;

    r2 = r2 * styleMultiplier;
    g2 = g2 * styleMultiplier;
    b2 = b2 * styleMultiplier;

    r3 = r3 * styleMultiplier;
    g3 = g3 * styleMultiplier;
    b3 = b3 * styleMultiplier;

    sendToWLED();

    delay(250);
}

void sendToWLED()
{
    HTTPClient http;

    http.begin(wledAddress);

    http.addHeader("Content-Type", "application/json");

    DynamicJsonDocument doc(512);

    doc["on"] = true;

    JsonObject seg = doc.createNestedArray("seg").createNestedObject();

    seg["fx"] = effectID;

    seg["sx"] = effectSpeed;

    seg["ix"] = 128;

    String json;

    serializeJson(doc, json);

    int response = http.POST(json);

    Serial.print("WLED Response: ");
    Serial.println(response);

    http.end();
}