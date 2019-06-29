# Lock Smart

- Overview of Lock Smart - What is it?
- Features of Lock Smart
- User Journey
- Required Build Materials and BOM

## Overview of Lock Smart - What is it?

When in search of the best way to protect our houses, it has always been using a physical lock as it boasts simplicity and effectiveness. However, not all locks are made equal, and all of them require the analog presence of an authorized user, which are our family members. As we approach a more modern and competitive Singapore, the need of a smart system to remotely grant access to individuals we do not fully trust may be required, such as our babies’ nanny, package delivery man, friends etc.  How can we allow people to achieve this goal without breaking the bank, while maintaining digital and analog security? 

Lock Smart is a reliable lock that can be unlocked remotely, either through mobile devices or computers, while allowing authorized users to use it as simple as traditional analog locks. Lock Smart features advanced security protocols such as data encryption and 2-factor authentication. Due to the nature of such a device, it is part of the Internet of Things (IoT) that easily integrates into our home networks without being intrusive. 

## Features of Lock Smart 
	
We have referred to the IoT security requirement Category of Technical Reference 64 (TR64) while designing the features of our system. We have decided to consider three main factors while designing this product - Data Protection (DP), Access Protection (AP) and Security Management (MT). Some of these may depend on other basic categories, and as such may be required to reference to in the future.

Lock Smart does not boast a wide range of methods to unlock it, unlike other locks on the market. This is due to the increase in attack surface as more features are added to the system. We thus decided to stick with simple yet highly secure ways of locking and unlocking a Lock Smart

### Electromagnetic Lock with Smart Alarm System

An electromagnetic lock was chosen as it is difficult to tamper with (AP-03). It may require expensive or complex equipment to unlock, which may be more difficult for the average person to acquire or operate. This reduces the likelihood of unauthorized access, while being highly available for authorized users. An alarm system also acts as a tamper evident to alert the owner and neighbours of an intrusion. 

### 2-Factor Authentication (2FA) (Lock Smart account + Email)

Authorized accounts can unlock the Lock Smart by scanning the unique QR code provided with the Lock Smart set. This QR code will redirect the user to a web page. They must log into the web page with their Lock Smart account. If their account is authorised by the owner, a One-Time Pin (OTP) will be sent to their email. The user must then enter the OTP to the field provided on the Lock Smart Web App (AP-02).

### Live video feed for Surveillance (refer to ANNEX B2)

A video camera comes with Lock Smart to act as a surveillance tool. The owner, upon verifying that a person is allowed to enter his/her house through the camera, can then choose to unlock the door remotely. The camera remains active unless deactivated by the user, and the means of storage is enclosed to provide security (AP04). Furthermore, it also acts as an assurance that no unauthorized personnel can enter the room except for the authorized personnel.

### Cross-platform Web Dashboard (OWASP style, refer to ANNEX B1 of TR64)
	
Prior to using Lock Smart, the owner must create a Lock Smart account and enter the Serial Identification (SID) of the lock into the Lock Smart Web App to gain ownership of the lock digitally. The owner’s account is called the master account. The master account can add and remove authorized accounts to grant them access to the lock.

All Lock Smart users must first associate a username and a strong password with the said Web App (MT01, IA-01, DP-03). Once the account is created, it must be verified by the owner to become an authorised account. Only authorised accounts can receive the OTP mentioned in B). Only the master account can observe the live video feed and directly unlock Lock Smart remotely without OTP. (Security Management.)

### Password Policy (MT01)

Passwords must adhere to the following:
1.	Minimum of 8 characters
2.	One uppercase letter
3.	One lowercase letter
4.	One Number
5.	One Special Character
6.	Password cannot be the same as username
7.	Passwords have to be updated every 6 months. 

Failure to comply with 7. will result in the account losing its authorised status.

## User Journey

There are two ways for the person to enter the house. One of the ways is to scan the QR code on the door. Another way is to remotely unlock the door.

As of the QR code, the user will need to scan the QR code and this will bring the user to a web app. In the web app, the user will need to sign in into his/her account to check whether it is an authorised account to access the house. When signing into the account, the user will need to provide their username and password. After that, they will receive an OTP in their email. Next, they need to key in the OTP into the web app. If the OTP entered is correct, the door will be unlocked. If the authentication process fails, the door will not be unlocked. The user can now use another way to gain access to the house.

Another way to enter the house is to allow the owner to remotely unlock the door for the user. In order for the owner to get notified, the user will need to press the doorbell. This doorbell will send a post to the web app to notify the owner that someone is outside the door. When the owner is notified, he can use the surveillance camera at the door to verify the person. If the owner knows the person, he can open the door remotely using the web app. On the other hand, if the owner does recognize the user, he can choose to keep the door unlocked.

## Required Build Materials and BOM

| Item | Price | Link to Product|
| ---- | :---: | :------------- |
| Electromagnetic Lock (generic) | $6.33 | https://ezbuy.sg/product/51000568137309.html?skuid=3904243333001&gclid=CjwKCAjwmNzoBRBOEiwAr2V27aQmMgZiTyEzBpH_GDnSALyFF7aMA6kKYmzbhUsMpn4zxzJZQHqQHRoCdFYQAvD_BwE|
| NodeMCU (Door control and keypad control) | (Provided) | (Provided) |
| Buzzer/Speaker (generic) | $1.66 | https://shopee.sg/5V-Piezo-Sounders-Passive-Buzzer-Component-for-Arduino-MINI-Alarm-Speaker-i.14646941.273727026?gclid=CjwKCAjwmNzoBRBOEiwAr2V27QDGyrWOMaXJE6IMLWImVjgbN2Nk1HD_gt-EoVhFCIbXitHYKaxspxoCYiUQAvD_BwE |
| ESP32 Camera (Live feed) | (request?) | https://sea.banggood.com/Geekcreit-ESP32-CAM-WiFi-bluetooth-Camera-Module-Development-Board-ESP32-With-Camera-Module-OV2640-p-1394679.html?gmcCountry=SG&currency=SGD&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=garman&utm_campaign=pla-sg-sea-all-pc&ad_id=323171517831&gclid=CjwKCAjwmNzoBRBOEiwAr2V27UaIiRpNsVENtI-XR8neRGyw_hkz2IsfLrasBXjtEJEW0aKX9mKEARoC8lMQAvD_BwE&cur_warehouse=CN|

## References:
- TR64: Www-singaporestandardseshop-sg.ezp1.lib.sp.edu.sg. (2019). SP E-LIBRARY Terms of Use. [online] Available at: https://www-singaporestandardseshop-sg.ezp1.lib.sp.edu.sg/Subscription/Product/Viewer [Accessed 29 Jun. 2019].
- Door, 1. (2019). 12V电磁锁磁力锁280kg单门180公斤350明装暗装60KG门禁电控锁单门. [online] Ezbuy.sg. Available at: https://ezbuy.sg/product/51000568137309.html?skuid=3904243333001&gclid=CjwKCAjwmNzoBRBOEiwAr2V27aQmMgZiTyEzBpH_GDnSALyFF7aMA6kKYmzbhUsMpn4zxzJZQHqQHRoCdFYQAvD_BwE [Accessed 29 Jun. 2019].
- Shopee.sg. (2019). 5V Piezo Sounders Passive Buzzer Component for Arduino MINI Alarm Speaker. [online] Available at: https://shopee.sg/5V-Piezo-Sounders-Passive-Buzzer-Component-for-Arduino-MINI-Alarm-Speaker-i.14646941.273727026?gclid=CjwKCAjwmNzoBRBOEiwAr2V27QDGyrWOMaXJE6IMLWImVjgbN2Nk1HD_gt-EoVhFCIbXitHYKaxspxoCYiUQAvD_BwE [Accessed 29 Jun. 2019].
- www.banggood.com. (2019). S$9.62 55% Geekcreit® ESP32-CAM WiFi + bluetooth Camera Module Development Board ESP32 With Camera Module OV2640  Module Board For Arduino from Electronics on banggood.com. [online] Available at: https://sea.banggood.com/Geekcreit-ESP32-CAM-WiFi-bluetooth-Camera-Module-Development-Board-ESP32-With-Camera-Module-OV2640-p-1394679.html?gmcCountry=SG&currency=SGD&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=garman&utm_campaign=pla-sg-sea-all-pc&ad_id=323171517831&gclid=CjwKCAjwmNzoBRBOEiwAr2V27UaIiRpNsVENtI-XR8neRGyw_hkz2IsfLrasBXjtEJEW0aKX9mKEARoC8lMQAvD_BwE&cur_warehouse=CN [Accessed 29 Jun. 2019].