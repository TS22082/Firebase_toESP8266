#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "Your wifi SSID"
#define WIFI_PASSWORD "your wifi password"

//this firebase project was deleted
//you'll need to enter your own firebase info
#define FIREBASE_HOST "firsttut-ab9e0.firebaseio.com"
#define FIREBASE_AUTH "qVPp9oOi9uBnuNcR4xKa52l02regpQwdo6yA36xY"

int ledPower = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ledStatus = Firebase.getInt("ledStatus");
  if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
  } else {
    digitalWrite(ledPower, LOW);
  }

  //set data:
  //Firebase.set(ledStatus, "1");
}
