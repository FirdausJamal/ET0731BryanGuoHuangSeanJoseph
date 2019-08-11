#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <EEPROM.h>
#define EEPROM_SIZE 512 //Number of bytes to access

//Lau Family
//DTEH24expr!!
char *ssid = "LSTEST";
char *password = "AAbb123??";
const char *endpoint = "aa5nyidma5p15-ats.iot.us-east-1.amazonaws.com";
const int port = 8883;

byte a,b,c,d,e,f;
byte q,r,s,t,u,v;
char *subTopicG = "OTP/G";
char *subTopicR = "OTP/R";

const char* rootCA = "-----BEGIN CERTIFICATE-----\nMIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\nADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\nb24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\nMAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\nb3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\nca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\nIFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\nVOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\njgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\nAYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\nA4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\nU5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\nN+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\no/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\nrqXRfboQnoZsG4q5WTP468SQvvG5\n-----END CERTIFICATE-----"; //CA certificate
const char* certificate = "-----BEGIN CERTIFICATE-----\nMIIDWTCCAkGgAwIBAgIUY3BzQhHYgRxfERsgndLor3GFA8owDQYJKoZIhvcNAQEL\nBQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\nSW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE5MDgwNzEyMTEy\nM1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\nZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAOG8nBfvnnzZwTPtoEm/\nCZb7GhelmOOJMRT5EcCoNU9qCcwP9kUj/RMVwsbuplISoITpnzXIEXi7HUFjenll\nLON4qwZ8LvX8RAcyEglvXL3Ozoi5yQSfbL8dnhw9DPRyD7WBRgax1UB9NkD0HYYp\nB1FP4d/bOUEqYhjID4FHcPjP4mpL7Ysde//Clm2ld5fPv4dWPy6N+/exmXDkE0BJ\nfqGZUXSAoTW00Az66etZmkbIR9kCNDtt1CN2pHns/jPsGZItvGXJeyyi8Tiv+kwa\nFIyfz7+9oOivyKVFVXG/pjGxROeccsW371A+cceJ+Rmr7GWFNaE1njNzaNGVqeZD\nEVsCAwEAAaNgMF4wHwYDVR0jBBgwFoAU0WXR0vUsjrgHEmSjqI/nWVUGL2IwHQYD\nVR0OBBYEFFe6ERyvC4hJlrfYCclIpwFrZrjlMAwGA1UdEwEB/wQCMAAwDgYDVR0P\nAQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBtJPDpvwDZOGedp2iUfHwGRTZz\nKh58wFQs5dg5zwkYsAUPGckeqVvh2cVl/6yE3y6Ec6Cuv94kFqMH2B413d8ud2m5\nXKPU86Tcbx8Imd2/shItg7zcsNGJcb/GmB0k64jO54mUW9Iqsy9/bHNu7YAgWvT6\nWC4hZ1enZnrsyWlbw8rUvrmcRntZOmbC15Ypc9M9QMcjM1n14mj3UdbnvlWp6EFG\no//I1Nvwzk99xM5FzPrMywlS0yCUivWqbrd0a1Npcl8nNneKq7FQ/8vRbft3J+BT\nLh5nf+A2O0z2ELjoKx+n7QMQUwbkDYzhriNljmrciN5dr7XPkkPjjRE3Ebai\n-----END CERTIFICATE-----\n"; //Own certificate
const char* privateKey = "-----BEGIN RSA PRIVATE KEY-----\nMIIEowIBAAKCAQEA4bycF++efNnBM+2gSb8JlvsaF6WY44kxFPkRwKg1T2oJzA/2\nRSP9ExXCxu6mUhKghOmfNcgReLsdQWN6eWUs43irBnwu9fxEBzISCW9cvc7OiLnJ\nBJ9svx2eHD0M9HIPtYFGBrHVQH02QPQdhikHUU/h39s5QSpiGMgPgUdw+M/iakvt\nix17/8KWbaV3l8+/h1Y/Lo3797GZcOQTQEl+oZlRdIChNbTQDPrp61maRshH2QI0\nO23UI3akeez+M+wZki28Zcl7LKLxOK/6TBoUjJ/Pv72g6K/IpUVVcb+mMbFE55xy\nxbfvUD5xx4n5GavsZYU1oTWeM3No0ZWp5kMRWwIDAQABAoIBAEJ5SzIVQwObEDTd\nff0Zf5ZxXU6nWi1vAgAeFGc6YXCAVmA8NxZHMchD+TahomK6z4A0V8j7oIGAAG53\n/+HttFlL+HkRarbPUa0Yxoz2uUW/t7w1kYeF9v0UmLHSHJWDXTLi3Z8tERJLjQV1\nnZgbTudX8bj9EpApDfgkOcSlKBRsfacoB+QIyY724lRRA0EWCfIMrKbv4QjWMMec\nkfTzOthKChxC4OLJNLZHNr7YZGvSJJNLK+gmkSPoMZFQQvMvsBgAGjDyDHte7JWE\n6vPJ5cjti7NmniNnYkVHS8GsKNELSvNFCE7L4N+cu2aH74wS0NP/EWjy6CI55Xh1\nh4Y2NxkCgYEA9+uvS31dmPyrhKWm7kzFaN+nYr3PS8LXI4wZ/Ypf9FN2YY+S7pmc\nWNE8rncnCv1+bpe28E45GQioE00/mQmJnVwg5N9GC0zC4LlYquz1PfJfoo6zoMxU\n3spC2Oyi/UbeWlStU/gW2CMN9kF+JTuucdH6drrVuW3wFEEKMi72vWcCgYEA6Rfa\nQuPjwrO09UWwMwREn8v0VWHJypuB+agtYOp3KNB3S/m2/bvIxtRvz0OoxfYmTn9/\nJE/dQg5OkUK51Y2tdHSNTAfesbCG/bH0EZ0vnXWilKwKZCeVZyW111UHFaWy6Hh7\n6B06y7Suw7ie9hPJtQLIea7o4Sllx7MWMUu/3+0CgYBH/hnGSx5d6amI+G2UL5j3\nzlKWGtZSgr7kpK97b65TjdUHmaCqRtMe+4uqghFFYL1RMh8+gwiTm27rQ/he4WUj\n2/f1XlzBtUW16jy0TeEdXv+kfdntrMhMdeGZioX+FJFHG+XFR3qiwvMv+m6+MymC\nBd68kZ60nRclWomybu7ZqwKBgQDTAZu8l83z0HiM3FQgKsnwmlIKBOcGeXXUyjCi\nHj5WfTixV1IXKaoci+zXhNlAs46D2xj+hym1hXwMNYpCzulplaTfYfRviGz7Nd/L\nHi8fbIEL8x3JAqhV4qZVUwyBxSlLFt6cBfHWvC7E0NldzBX5vZY7yWHZin8vo2gA\noiEFFQKBgG1G4TDtermVBxs4p1+74BWAdh9hcWHvE89kjed9HRZWBzBYrg2lDrk/\ngjXCqcxUb6ZiJcVJM/7guZtEGdJkhcD8EraBChdXGHpZvz0N54KIILkBvmN5OqrR\nem+O5TThOPAr+IGNeCipiE6zqvXN64ORyTOPdEyqLXRk8q+80Tvo\n-----END RSA PRIVATE KEY-----\n";

WiFiClientSecure httpsClient;
PubSubClient mqttClient(httpsClient);

void setup() {
    pinMode(12,OUTPUT);
    digitalWrite(12,0);
    delay(1000);
    Serial.begin(115200);
    EEPROM.begin(EEPROM_SIZE);
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
        if (mqttClient.connect("ESP32_device")) {
            Serial.println("Connected.");
            int qos = 0;
            mqttClient.subscribe(subTopicG, qos);
            mqttClient.subscribe(subTopicR, qos);
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
  Serial.println(topic);
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]); 
  } 
  int result = strcmp(topic, subTopicG);
  Serial.print("\n");
  Serial.println(result);
  if (result == 0){
    a = payload[20];
    b = payload[21];
    c = payload[22];
    d = payload[23];
    e = payload[24];
    f = payload[25];
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
    Serial.println(e);
    Serial.println(f);
  
  } else {
    q = payload[16];
    r = payload[17];
    s = payload[18];
    t = payload[19];
    u = payload[20];
    v = payload[21];
    Serial.println(q);
    Serial.println(r);
    Serial.println(s);
    Serial.println(t);
    Serial.println(u);
    Serial.println(v);
  }
  if ((a==q)&&(b==r)&&(c==s)&&(d==t)&&(e==u)&&(f==v)) {
    Serial.print("OTP Matches");
    Serial.print("\n");
    digitalWrite(12, 1);
    delay(5000);
    digitalWrite(12, 0);
  } else {
    Serial.print("OTP Does not match");
    Serial.print("\n");
  }
}

void loop() {
  mqttClient.loop();
  mqttClient.setCallback(mqttCallback);
}
