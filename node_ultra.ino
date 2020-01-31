                            /*
                            *
                            * Project Name:      Smart Parking Aid System
                            * Author List:       Yukta Rane, Bhagyeshri Oza 
                            * Filename:          node_ultra.ino
                            * Functions:         setup_wifi(), callback(char*, byte*, unsigned int), reconnect(), setup(), loop() 
                            * Global Variables:  ssid, password, mqtt_server, trigP1, echoP1, trigP2, echoP2, trigP3, echoP3, duration1, duration2, duration3, distance1, distance2, distance3, lastMsg, value
                            *
                            */



/*
 Basic ESP8266 MQTT example

 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.

 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"

*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "JioFi2_7D854D";
const char* password = "v47qtdf7n2";
const char* mqtt_server = "192.168.1.101";

const int trigP1 = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP1 = 0;  //D3 Or GPIO-0 of nodemcu
const int trigP2 = 5;  //D1 Or GPIO-5 of nodemcu
const int echoP2 = 4;  //D2 Or GPIO-4 of nodemcu
const int trigP3 = 12;  //D6 Or GPIO-12 of nodemcu
const int echoP3 = 13;  //D7 Or GPIO-13 of nodemcu

long duration1,duration2,duration3;
int distance1,distance2,distance3;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

                            /*
                            *
                            * Function Name:   setup_wifi
                            * Input:           None
                            * Output:          None
                            * Logic:           This function is used to connect to the specified WiFi network
                            * Example Call:    setup_wifi()
                            *
                            */

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

                            /*
                            *
                            * Function Name:   callback
                            * Input:           topic: mqtt topic to which client will publish
                            * Output:          None
                            * Logic:           This function is used as a callback function after connecting to server. The function displays the topic on serial monitor after connecting to server
                            * Example Call:    callback(topic, payload, 6)
                            *
                            */

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

                            /*
                            *
                            * Function Name:   reconnect
                            * Input:           None
                            * Output:          None
                            * Logic:           This function will loop till we are connected to MQTT broker
                            * Example Call:    reconnect
                            *
                            */

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("sensors/sensor1", "hello world");
      // ... and resubscribe
      client.subscribe("sensors/sensor1");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("sensors/sensor2", "hello world");
      // ... and resubscribe
      client.subscribe("sensors/sensor2");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("sensors/sensor3", "hello world");
      // ... and resubscribe
      client.subscribe("sensors/sensor3");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

                            /*
                            *
                            * Function Name:   setup
                            * Input:           None
                            * Output:          None
                            * Logic:           This function is used to set the input and output pins of nodemcu, to setup Serial communication and to setup server at mqtt broker's ip address
                            * Example Call:    setup()
                            *
                            */

void setup() {
  pinMode(trigP1, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP1, INPUT);   // Sets the echoPin as an Input
  pinMode(trigP2, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP2, INPUT);   // Sets the echoPin as an Input
  pinMode(trigP3, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP3, INPUT);   // Sets the echoPin as an Input
//Serial.begin(9600);      // Open serial channel at 9600 baud rate
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

                            /*
                            *
                            * Function Name:   loop
                            * Input:           None
                            * Output:          None
                            * Logic:           This function automatically loops and takes data from three ultrasonic sensors and to publish appropriate message to corresponding topic
                            * Example Call:    loop()
                            *
                            */

void loop() {
  digitalWrite(trigP1, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 

  digitalWrite(trigP1, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP1, LOW);   // trigPin low

  duration1 = pulseIn(echoP1, HIGH);   //Read echo pin, time in microseconds
  distance1= duration1*340/20000;        //Calculating actual/real distance
  
  digitalWrite(trigP2, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 

  digitalWrite(trigP2, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP2, LOW);   // trigPin low

  duration2 = pulseIn(echoP2, HIGH);   //Read echo pin, time in microseconds
  distance2= duration2*340/20000;        //Calculating actual/real distance
  
  digitalWrite(trigP3, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay 

  digitalWrite(trigP3, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trigP3, LOW);   // trigPin low

  duration3 = pulseIn(echoP3, HIGH);   //Read echo pin, time in microseconds
  distance3= duration3*340/20000;        //Calculating actual/real distance*/
                      

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // distance2= 92.88;
   //distance3= 84;
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
   // ++value;
    if(distance1>91.44){
      snprintf (msg, 75, "Vacant");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance1);
      client.publish("sensors/sensor1", msg);
    }
    else{
      snprintf (msg, 75, "Filled");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance1);
      client.publish("sensors/sensor1", msg);
    }
    if(distance2>91.44){
      snprintf (msg, 75, "Vacant");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance2);
      client.publish("sensors/sensor2", msg);
    }
    else{
      snprintf (msg, 75, "Filled");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance2);
      client.publish("sensors/sensor2", msg);
    }
    if(distance3>91.44){
      snprintf (msg, 75, "Vacant");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance3);
      client.publish("sensors/sensor3", msg);
    }
    else{
      snprintf (msg, 75, "Filled");
      //Serial.print("Publish message: ");
      //Serial.println(msg);
      Serial.println(distance3);
      client.publish("sensors/sensor3", msg);
    }
    
  }
  //duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds        //Calculating actual/real distance
}
