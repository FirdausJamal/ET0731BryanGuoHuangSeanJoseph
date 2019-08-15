# Methodology to Compromise system

## Brief
After analyzing our network diagram, we found a few entry points to our IoT System:
1) Wireless Access Point
2) User password
3) Server
4) ESP32 
5) Electromagnetic Doorlock

## Planned Methodology;
First, compromsing at the wireless access point is required. We planned to use airmon and airodump to compromise the password of the access point. 

However, given that the user has used strong encryption for password such as WPA-PSK, sources show that it will take a long time to compromise by brute force methods. This made us think that the best way to go around this is to use social engineering to "guestimate" SSID and password. 

Next, suppose the password has been obtained, if we were to be connected to the router, we are able to capture the packets of all the devices in the network.

We then planned to use airodump and airmon to do a 4-way handshake to be able to listen to at least HTTP requests acording to this quide: https://null-byte.wonderhowto.com/how-to/intercept-images-from-security-camera-using-wireshark-0191735/

Either from the packets captured or through educated guesses, we can then know when the device is receiving MQTTS responses and where the device is.

From here on , it becomes inreasingly difficult to crack the system as we will need to know what the key is for Secured MQTT,  which MQTT topic corresponds to which door, and how to predict the pseudo random OTP mathematial algorithm.

Finally, if all is impossible, hackers may need to physically tamper the device. The most direct yet counterintuitive method is using a strong magnet to dislodge the solenoid. However, other hardware tampering methodologies are not practical as the ESP32 with the lock is indoors, away from hackers' reach.

## Our futiles attempts:

We managed to seure a Wireless dongle with the RT5372 chipset by Ralink, shown to be compatible with aircrack and wireshark. We then decided to test out the guide in order to compromise the HTTP packets sent in a wireless system. We planned to achieve this by deauthentiating a device in the network as per the guide, and when it automatically reconnects, we capture the 4-way handshake, thus obtaining the network key, and validate its success by sending unsecured HTTP request to capture all the packets sent to the access point. 

With that, we plan to do eavesdropping on our network, whereby we listen to which devices constantly send MQTT/MQTTS requests. This was the maximum we thought we could get as it is hard to obtain the MQTTS keys. It is also difficult to guess the user email, but suppose the user is in the network, we could get some clues from there. We decided to plan what to do next if we managed to reach here.

Hence, we followed the guide, but to our dismay we could not get unicast packets, but only multicast or broadcast messages. After a few troubleshooting sessions we still couldn't get a screenshot similar to the guide. In the end, We suspect that this is due to us using a mobile hotspot instead of a proper router.

Below are some screenshots of our attacking process:
