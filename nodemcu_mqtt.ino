#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Wifi Connection Config
const char* wlanName = "KEDAI DJENGGOT $$$";
const char* wlanPassword = "malamselasa";

// Define Variable for mqtt broker
const char* brokerAddress = "ec2-3-86-238-120.compute-1.amazonaws.com";
const char* brokerUsername = "jti";
const char* brokerPassword = "password";

// Define instance for wificlient
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length);


void reconnect() {
  //  Reconnect if connection lost
  Serial.println("In reconnect...");
  
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("smart_lamp", brokerUsername, brokerPassword)) {
      Serial.println("connected");
      client.subscribe("smartHome");
      client.subscribe("dimmingLamp");
    } else {
      Serial.print("failed, ");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
  
}

//Broker callback
void callback(char* topic, byte* payload, unsigned int length) {
  for (int i = 0; i < length; i++) {
   // validate topic name and
   // Send data to serial
   if (strcmp(topic,"smartHome") == 0 ) {
    Serial.write(payload[i]);
    Serial.write("");
   }
   
   if (strcmp(topic,"dimmingLamp") == 0 ) {
    Serial.write(payload[i]);
    Serial.write("");
   }
   
  }
}

void setup() {
  //  Initial Serial
  Serial.begin(115200);
    
  //  Declare wifi config
  WiFi.begin(wlanName,wlanPassword);
  while (WiFi.status() != WL_CONNECTED )  {
    // Delay for get wifi status
    delay(500);
    Serial.print("#");
  }
  Serial.println("");
  Serial.println("Connected");
  
  //Set Server Broker
  client.setServer(brokerAddress,1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
   reconnect(); 
  }
  client.loop();
}
