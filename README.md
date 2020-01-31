# SmartParkingAidSystem
Problem Statement: How might we reduce traffic congestion caused by lack of information of parking spaces, using a device identifying vacant spaces and broadcasting information through a mobile application for drivers . Description: Traffic management is a very crucial area for quality of life in modern and sustainable cities. Travelling in private vehicles is inevitable in some circumstances, which also demands smart parking slots with real time information system for availability of parking.  In most of the metropolitan cities today, traffic management, availability of parking slots and information regarding the same is missing. This situation is creating traffic snags on a daily basis, wastage of fuel and time, increased air pollution, and frustration for drivers. Drivers waste a lot of time and fuel while looking for vacant parking spaces, causing them considerable frustration. As there is no system informing drivers of vacant parking spaces around them, drivers have to manually look around for parking spaces on the street. Even when using a car park, drivers have to manually check every level to find a parking slot or use the help of car park assistants. Unavailability of sufficient parking slots, lack of information about them and no system to find illegally parked vehicles, leads to rampant illegal parking. Also, the traffic flow gets hampered due to illegally parked vehicles.


Instructions to execute code files
# node_ultra.ino:
1) Open arduino ide and paste the following urls in File->Preferences:
   https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
2) Go to Sketch->Include Library and install PubSubClient library
3) Go to Tools->Board: and select Boards Manager and install esp8266 package.
4) Go to Tools->Board: and select NodeMCU 1.0(ESP-12E) module.
5) Set up your WiFi credentials in code and upload it.(Make sure the raspberry pi is connected to same WiFi)

# mqtt_subscribe.py:
1) Run the file in terminal after installing following libraries:
   1) requirements
   2) python-firebase
