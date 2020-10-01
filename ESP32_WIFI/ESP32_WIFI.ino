#include <SPI.h>
#include <WiFi.h>

//SSID of your network
char ssid[] = "4G Viettel";
//password of your WPA Network
char pass[] = "@C2onM4eoN4gu@";

void setup()
{
  Serial.begin(115200);
 WiFi.begin(ssid, pass);

  if (!WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while(true);
  }
  // if you are connected, print out info about the connection:
  else {
   // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption,HEX);
  }
}

void loop () {}
