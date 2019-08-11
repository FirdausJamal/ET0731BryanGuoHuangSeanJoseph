//Original Source Code: https://awsm.dvlprz.com/2017-10-16-esp32-aws-iot-mqtt
//Last Modified on 11/8/2019 6:30PM
//Originally done by: Sean Lau W.C
//Last Modified by : Sean Lau W.C

#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

char *ssid = "";           //Your SSID
char *password = "";       //Your SSID Password
const char *endpoint = ""; //Your HTTPS Endpoint
const int port = 8883;     

byte a,b,c,d,e,f;     //Variables to store OTP from Web Server
byte q,r,s,t,u,v;     //Variables to store OTP from User
char *subTopicG = ""; //MQTT topic to receive OTP from Web Server
char *subTopicR = ""; //MQTT topic to receive OTP from User

const char* rootCA = "";      //CA certificate
const char* certificate = ""; //Own certificate
const char* privateKey = "";  //Private key

WiFiClientSecure httpsClient;
PubSubClient mqttClient(httpsClient);

void setup() {
    pinMode(12,OUTPUT); //Declare PIN 12 to be OUTPUT
    digitalWrite(12,0); //Write LOW to PIN 12
    delay(1000);
    Serial.begin(115200);

    //Connect to WiFi
    Serial.println("Connecting to ");
    Serial.print(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected.");
    
    //Configure MQTT Client
    httpsClient.setCACert(rootCA);
    httpsClient.setCertificate(certificate);
    httpsClient.setPrivateKey(privateKey);
    mqttClient.setServer(endpoint, port);
    
    while (!mqttClient.connected()) {
        if (mqttClient.connect("ESP32_device")) { //Device ID
            Serial.println("Connected.");
            int qos = 0;
            mqttClient.subscribe(subTopicG, qos); //Subscribe to MQTT topic to receive OTP from Web Server
            mqttClient.subscribe(subTopicR, qos); //Subscribe to MQTT topic to receive OTP from User
            Serial.println("Subscribed.");
        } else {
            Serial.print("Failed. Error state=");
            Serial.print(mqttClient.state());
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void mqttCallback (char* topic, byte* payload, unsigned int length) { //Recieve message from AWS IOT
  Serial.println("\nReceived. topic = ");
  Serial.println(topic);                 //Print the topic the message was received from 
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);      //Print the message that was received.
  } 
  int result = strcmp(topic, subTopicG); //Compare the current topic with subTopicG. Returns an integar
  Serial.print("\n");
  Serial.println(result);

  //Storing the OTP generated from Web Server
  if (result == 0){  //0 indicates that the two strings compared are equal. 0 means current topic is subTopigG
    a = payload[20]; //First digit of OTP is stored here
    b = payload[21];
    c = payload[22];
    d = payload[23];
    e = payload[24];
    f = payload[25]; //Last digit of OTP is stored here
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
    Serial.println(e);
    Serial.println(f);

  //Storing the OTP entered by the User
  } else {
    q = payload[16]; //First digit of OTP is stored here
    r = payload[17];
    s = payload[18];
    t = payload[19];
    u = payload[20];
    v = payload[21]; //Last digit of OTP is stored here
    Serial.println(q);
    Serial.println(r);
    Serial.println(s);
    Serial.println(t);
    Serial.println(u);
    Serial.println(v);
  }
  if ((a==q)&&(b==r)&&(c==s)&&(d==t)&&(e==u)&&(f==v)) { //Check that every digit of Generated OTP matches every digit of User entered OTP. 

    //If OTP matches
    Serial.print("OTP Matches");
    Serial.print("\n");
    digitalWrite(12, 1); //Write HIGH to PIN 12
    delay(5000);         //5s Delay
    digitalWrite(12, 0); //Write LOW to PIN 12

    //If OTP does not match
  } else {
    Serial.print("OTP Does not match");
    Serial.print("\n");
  }
}

//Keep printing the received messages from subscribed topics
void loop() {
  mqttClient.loop();
  mqttClient.setCallback(mqttCallback); 
}
