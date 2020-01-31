                            """
                            *
                            * Project Name: 	Smart Parking Aid System
                            * Author List: 	Yukta Rane
                            * Filename:         mqtt_subscribe.py
                            * Functions:        on_connect(client, userdata, flags, rc), on_message(client, userdata, msg)
                            * Global Variables:	mqtt_topic1, mqtt_topic2,mqtt_topic3, mqtt_broker_ip, client
                            *
                            """

import paho.mqtt.client as mqtt
from firebase import firebase
firebase = firebase.FirebaseApplication('https://parking-cloud-1315b.firebaseio.com/', None)

mqtt_topic1 = "sensors/sensor1"
mqtt_topic2 = "sensors/sensor2"
mqtt_topic3 = "sensors/sensor3"
mqtt_broker_ip = "192.168.1.101"

client = mqtt.Client()

                            """
                            *
                            * Function Name: 	on_connect
                            * Input: 		client:   variable used to store library paho.mqtt.client and use it to subscribe to published topics on connecting to publisher.
                            *                   userdata: user defined data of any type that is passed as the userdata parameter to callbacks. It may be updated at a later point with the user_data_set() function.
                            *                   flags:    set to false internally and then toggles to true when connected to client
                            *                   rc:       rc (return code) is used for checking that the connection was established
                            * Output: 		None
                            * Logic: 		This function describes what actions to perform after getting connected to the client
                            * Example Call:	on_connect(client,userdata,0,1)
                            *
                            """

def on_connect(client, userdata, flags, rc):
    # rc is the error code returned when connecting to the broker
    print("Connected!", str(rc))
    
    # )Once the client has connected to the broker, subscribe to the topic
    client.subscribe(mqtt_topic1)
    client.subscribe(mqtt_topic2)
    client.subscribe(mqtt_topic3)

                            """
                            *
                            * Function Name: 	on_message
                            * Input: 		client:   variable used to store library paho.mqtt.client and use it to subscribe to published topics on connecting to publisher.
                            *                   userdata: user defined data of any type that is passed as the userdata parameter to callbacks. It may be updated at a later point with the user_data_set() function.
                            *                   msg:      It contains the published topic and payload associated with it
                            * Output: 		None
                            * Logic: 		This function is called everytime the topic is published to.If you want to check each message, and do something depending on the content, the code to do this should be run in this function
                            * Example Call:	on_message(client,userdata,msg)
                            *
                            """
    
def on_message(client, userdata, msg):
    
    # This function is called everytime the topic is published to.
    # If you want to check each message, and do something depending on
    # the content, the code to do this should be run in this function
    if(msg.topic == "sensors/sensor1"):
        print("Topic: ", msg.topic + "\nMessage: " + str(msg.payload))
        firebase.put('/car-park-one/-Lzj1Ca_RQDkcKGCNT4f', 'slot1', msg.payload)
    elif(msg.topic=="sensors/sensor2"):
        print("Topic: ", msg.topic + "\nMessage: " + str(msg.payload))
        firebase.put('/car-park-one/-Lzj1Ca_RQDkcKGCNT4f', 'slot2', msg.payload)
    elif(msg.topic=="sensors/sensor3"):
        print("Topic: ", msg.topic + "\nMessage: " + str(msg.payload))
        firebase.put('/car-park-one/-Lzj1Ca_RQDkcKGCNT4f', 'slot3', msg.payload)
    # The message itself is stored in the msg variable
    # and details about who sent it are stored in userdata

# Here, we are telling the client which functions are to be run
# on connecting, and on receiving a message
client.on_connect = on_connect
client.on_message = on_message

# Once everything has been set up, we can (finally) connect to the broker
# 1883 is the listener port that the MQTT broker is using
client.connect(mqtt_broker_ip, 1883)

# Once we have told the client to connect, let the client object run itself
client.loop_forever()
client.disconnect()



