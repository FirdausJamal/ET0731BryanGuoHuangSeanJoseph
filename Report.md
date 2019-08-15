# IoT Security Report
# Contents
### 1. Overview of Lock Smart - What is it?	
### 2. Features of Lock Smart	
- 2.1 Electromagnetic Lock	
- 2.2 2-Factor Authentication	
- 2.3 Email Alerts via AWS SES	
- 2.4  Cross-platform Web Dashboard (OWASP style, refer to ANNEX B1 of TR64)	
### 3. Network Diagram	
### 4. User Journey	
- 4.1 Setting Up Lock Smart	
- 4.2 Verify Email	
- 4.3 Using Lock Smart	
### 5. Compliance Checklist	
### 6. Required Build Materials	
### 7. Potential Improvements	
### 8. References	

## 1: Overview of Lock Smart
Lock Smart is a reliable lock that can be unlocked remotely, either through mobile devices or computers. Lock Smart features advanced security protocols such as data encryption and 2-factor authentication. Due to the nature of such a device, it is part of the Internet of Things (IoT) that easily integrates into our home networks without being intrusive.
## 2: Features of Lock Smart 
We have referred to the IoT security requirement Category of Technical Reference 64 (TR64) while designing the features of our system. We have decided to consider three main factors while designing this product - Data Protection (DP), Access Protection (AP) and Security Management (MT). Some of these may depend on other basic categories, and as such may be required to reference to in the future.

Lock Smart does not boast a wide range of methods to unlock it, unlike other locks on the market. This is due to the increase in attack surface as more features are added to the system. We thus decided to stick with simple yet highly secure ways of locking and unlocking a Lock Smart.

### 2.1: Electromagnetic Lock
An electromagnetic lock was chosen as it is difficult to tamper with. It may require expensive or complex equipment to unlock, which may be more difficult for the average person to acquire or operate. This reduces the likelihood of unauthorized access, while being highly available for authorized users. 

### 2-Factor Authentication
A user can unlock Lock Smart by scanning the unique QR code provided with the Lock Smart set. This QR code will redirect the user to a web page. They must log into the web page with their Lock Smart account. If their account has been successfully logged into, a One-Time Pin (OTP) will be sent to their email. The user must then enter the OTP to the field provided on the Lock Smart Web App. If the generated OTP matches the user-entered OTP, Lock Smart will unlock. 



### 2.3: Email Alerts via AWS SES
Every time an OTP is generated, an email is sent to the owner to inform him. This ensures that the owner is able to monitor the status of his Lock Smart wherever he goes as long as he has access to the internet. It also allows the owner to view suspicious activity such as the attempted unlocking of Lock Smart at odd hours. This gives the owner the ability to deduce if something wrong is happening and allows him to check with the necessary parties (family, friends) before contacting the authorities.

### 2.4: 2-Factor Authentication
A user can unlock Lock Smart by scanning the unique QR code provided with the Lock Smart set. This QR code will redirect the user to a web page. They must log into the web page with their Lock Smart account. If their account has been successfully logged into, a One-Time Pin (OTP) will be sent to their email. The user must then enter the OTP to the field provided on the Lock Smart Web App. If the generated OTP matches the user-entered OTP, Lock Smart will unlock. 


## 3: Network Diagram
As seen from the above 2 diagrams, the unlocking procedure for Lock Smart follows a simple step by step process that is completed within a minute. A more in-depth walkthrough is detailed in section 4

## 4: User Journey
	This section covers the steps required to set up and used the Lock Smart device.

### 4.1: Setting Up Lock Smart
To set up Lock Smart, a person, usually the owner of the Lock Smart device, needs to claim ownership of the device. This is done by the owner 
creating a Lock Smart account to gain ownership of the lock digitally. The owner’s account is the only account that can unlock that particular Lock Smart device. The email associated with the owner’s account will also receive alerts on the lock’s activity.

### 4.2: Verify Email
As Amazon Simple Email Service is used to send emails to authorized users, they must first verify that they are associated with the email address. If the user does not verify his email with Amazon, he will not be able to receive emails.

### 4.3: Using Lock Smart
The owner has to access the Lock Smart Web App. In the Web App, the user will need to sign in using their username and password. After that, they will receive an OTP in their email. Next, they key in the OTP into the given field and if the entered OTP is correct, Lock Smart will be unlocked. If the authentication process fails, the Lock Smart will stay locked.

## 5: Compliance Checklist
Attack Surface|CheckList|TR64 Reference|Description
--------------|---------|--------------|-----------
Web App|Data is sent over secure protocols, No exposure of session key, token etc|RS-03, IA-01|Can withstand malicious attacks, User credentials are salted and hashed
Web Server|Secured login using 2FA, Secure from SQL injections, Data is not stored in clear text, Secure Communications|AP-02, CS-01, DP-03, DP-01, RS-03|2 Factor Authentication with email, Proper random number generation is employed for OTP, Program was coded in a way to prevent SQL injections, User password is salted and hashed, Server uses HTTPS
ESP32|Tamper-proof Enclosure, No exposed joints/connectors to open device, Secure Communications|AP-04, AP-03, RS-03|Enclosure is not easily tampered with, Exposed ports are sealed off, ESP32 uses MQTTS
Entire System|Identify and analyse threats to an Iot system, System designed in a secure way, System should be able to withstand malicious attacks|LP-01, LP-02, RS-03|Conducted threat modeling to identify threats, System is designed and developed using secure systems engineering approach and best practices, System uses necessary protocols to withstand malicious attacks



## 6: Required Build Materials
Item|Price|Link to product
----|-----|---------------
Solenoid, DC 12V, 2.1 kg Force, 10 mm|$15.68|[Link](https://www.amazon.com/Uxcell-a14032200ux0084-Electric-Electromagnet-Solenoid/dp/B00LBQ229Y/ref=nav_signin?_encoding=UTF8&psc=1&refRID=44YNTX0M0WSA7KJVY267&)
Buck Converter|$2.92|[link](https://www.amazon.com/LM2596-Converter-3-0-40V-1-5-35V-Supply/dp/B01GJ0SC2C/ref=sr_1_3?keywords=buck+converter&qid=1565874931&s=gateway&sr=8-3)
ESP32|$9.50|[Link](https://www.amazon.com/KeeYees-Development-Bluetooth-Microcontroller-ESP-WROOM-32/dp/B07QCP2451/ref=sr_1_4?keywords=esp32&qid=1565874868&s=gateway&sr=8-4)
TIP110 Transistor|$1.92|[Link](https://www.amazon.com/LM2596-Converter-3-0-40V-1-5-35V-Supply/dp/B01GJ0SC2C/ref=sr_1_3?keywords=buck+converter&qid=1565874931&s=gateway&sr=8-3)
Misc. electronics (resistors, capacitors, switches, stripboard)|- (taken from school)|-



## 7: Potential Improvements
Although Lock Smart is a relatively secure product, it has room for many improvements. These improvements will make Lock Smart even more secure and marketable. The table below will list down some of the potential improvements that can be made to Lock Smart:

Improvement|Description/Reasoning
-----------|---------------------
Locking Accounts/Using CAPTCHA|Prevent Brute-Force Attacks from Web App input field.
Strictly enforcing a Password Policy|Currently, users are recommended to follow a password policy but are not forced to do so. Forcing users to do so will ensure that passwords meet a good level of security.
Measures to prevent scripts from being injected|Multiple kinds of scripts (SQL Injection, JavaScript) can be injected to compromise the web server.
Encrypting data being sent|Encrypting the 6 digit OTP so that if the packets were intercepted the data would still be secure.
Using Security devices (Hardware Firewall) for the Server|Provides an additional level of security on top of software firewall.
Close unused ports|increase security by not having vulnerable ports open and only having the necessary ports open.



## 8:	References
1. TR64: Www-singaporestandardseshop-sg.ezp1.lib.sp.edu.sg. (2019). SP E-LIBRARY Terms of Use. [online] Available at: https://www-singaporestandardseshop-sg.ezp1.lib.sp.edu.sg/Subscription/Product/Viewer [Accessed 29 Jun. 2019].
2. Door, 1. (2019). 12V电磁锁磁力锁280kg单门180公斤350明装暗装60KG门禁电控锁单门. [online] Ezbuy.sg. Available at: https://ezbuy.sg/product/51000568137309.html?skuid=3904243333001&gclid=CjwKCAjwmNzoBRBOEiwAr2V27aQmMgZiTyEzBpH_GDnSALyFF7aMA6kKYmzbhUsMpn4zxzJZQHqQHRoCdFYQAvD_BwE [Accessed 29 Jun. 2019].
3. Shopee.sg. (2019). 5V Piezo Sounders Passive Buzzer Component for Arduino MINI Alarm Speaker. [online] Available at: https://shopee.sg/5V-Piezo-Sounders-Passive-Buzzer-Component-for-Arduino-MINI-Alarm-Speaker-i.14646941.273727026?gclid=CjwKCAjwmNzoBRBOEiwAr2V27QDGyrWOMaXJE6IMLWImVjgbN2Nk1HD_gt-EoVhFCIbXitHYKaxspxoCYiUQAvD_BwE [Accessed 29 Jun. 2019].
4. www.banggood.com. (2019). S$9.62 55% Geekcreit® ESP32-CAM WiFi + bluetooth Camera Module Development Board ESP32 With Camera Module OV2640  Module Board For Arduino from Electronics on banggood.com. [online] Available at: https://sea.banggood.com/Geekcreit-ESP32-CAM-WiFi-bluetooth-Camera-Module-Development-Board-ESP32-With-Camera-Module-OV2640-p-1394679.html?gmcCountry=SG&currency=SGD&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=garman&utm_campaign=pla-sg-sea-all-pc&ad_id=323171517831&gclid=CjwKCAjwmNzoBRBOEiwAr2V27UaIiRpNsVENtI-XR8neRGyw_hkz2IsfLrasBXjtEJEW0aKX9mKEARoC8lMQAvD_BwE&cur_warehouse=CN [Accessed 29 Jun. 2019].


 







