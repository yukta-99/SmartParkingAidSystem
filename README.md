# SmartParkingAidSystem
Collaborators: [Rutwik Patel](https://github.com/rutwik-99)


Problem Statement: How might we reduce traffic congestion caused by lack of information of parking spaces, using a device identifying vacant spaces and broadcasting information through a mobile application for drivers . Description: Traffic management is a very crucial area for quality of life in modern and sustainable cities. Travelling in private vehicles is inevitable in some circumstances, which also demands smart parking slots with real time information system for availability of parking.  In most of the metropolitan cities today, traffic management, availability of parking slots and information regarding the same is missing. This situation is creating traffic snags on a daily basis, wastage of fuel and time, increased air pollution, and frustration for drivers. Drivers waste a lot of time and fuel while looking for vacant parking spaces, causing them considerable frustration. As there is no system informing drivers of vacant parking spaces around them, drivers have to manually look around for parking spaces on the street. Even when using a car park, drivers have to manually check every level to find a parking slot or use the help of car park assistants. Unavailability of sufficient parking slots, lack of information about them and no system to find illegally parked vehicles, leads to rampant illegal parking. Also, the traffic flow gets hampered due to illegally parked vehicles.


# Instructions to execute hardware code files

# Nodemcu -
# node_ultra.ino:
1) Open arduino ide and paste the following urls in File->Preferences:
   https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
2) Go to Sketch->Include Library and install PubSubClient library
3) Go to Tools->Board: and select Boards Manager and install esp8266 package.
4) Go to Tools->Board: and select NodeMCU 1.0(ESP-12E) module.
5) Set up your WiFi credentials in code and upload it.(Make sure the raspberry pi is connected to same WiFi)

# Raspberry Pi -
# mqtt_subscribe.py:
1) Run the file in terminal after installing following libraries:
   1) requirements
   2) python-firebase
   
# Instructions to execute software code

1) Install node js and npm
2) Install Ionic 4 using the official documentation given here: https://ionicframework.com/docs/cli/commands/start
3) Make an Ionic Project with Angular following the official documentation
4) Generate a page in the project, called ' carpark ' and copy the contents of carpark.page.html from this repository in the file named carpark.page.html in the folder ' carpark '. Follow the same procedure for carpark.page.ts
5) Generate a serive in the project, called ' carpark.service ' and copy the contents of carpark.service.ts from this repository in the file named carpark.service.ts in the folder ' carpark '
6) Generate another page within the carpark page called ' parkingslots ' and copy the contents of parkingslots.page.html from this repository in the file named parkingslots.page.html in the folder ' parkingslots '. Follow the same procedure for parkingslots.page.ts
7) Run the command ' ionic serve ' in the command prompt after navigating to the folder where the Ionic project is stored
