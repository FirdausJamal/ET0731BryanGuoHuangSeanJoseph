# Lock Smart Proposal

## Overview of Lock Smart - What is it?

When in search of the best way to protect our houses, it has always been using a physical lock as it boasts simplicity and effectiveness. However, not all locks are made equal, and all of them require the analog presence of an authorized user, which are our family members. As we approach a more modern and competitive Singapore, the need of a smart system to remotely grant access to individuals we do not fully trust may be required, such as our babies’ nanny, package delivery man, friends etc.  How can we allow people to achieve this goal without breaking the bank, while maintaining digital and analog security? 

Lock Smart is a reliable lock that can be unlocked remotely, either through mobile devices or computers, while allowing authorized users to use it as simple as traditional analog locks. Lock Smart features advanced security protocols such as data encryption and 2-factor authentication. Due to the nature of such a device, it is part of the Internet of Things (IoT) that easily integrates into our home networks without being intrusive. 

## Features of Lock Smart 
	
We have referred to the IoT security requirement Category of Technical Reference 64 (TR64) while designing the features of our system. We have decided to consider three main factors while designing this product - Data Protection (DP), Access Protection (AP) and Security Management (MT). Some of these may depend on other basic categories, and as such may be required to reference to in the future.
### Electromagnetic Lock with Smart Alarm System
An electromagnetic lock was chosen as it is difficult to tamper with. It may require expensive or complex equipment to unlock, which may be more difficult for the average person to acquire or operate. This reduces the likelihood of unauthorized access, while being highly available for authorized users. 
### 2-Factor Authentication
A user can unlock Lock Smart by scanning the unique QR code provided with the Lock Smart set. This QR code will redirect the user to a web page. They must log into the web page with their Lock Smart account. If their account has been successfully logged into, a One-Time Pin (OTP) will be sent to their email. The user must then enter the OTP to the field provided on the Lock Smart Web App. If the generated OTP matches the user-entered OTP, Lock Smart will unlock. 
Email Alerts via AWS SES
Every time an OTP is generated, an email is sent to the owner to inform him. This ensures that the owner is able to monitor the status of his Lock Smart wherever he goes as long as he has access to the internet. It also allows the owner to view suspicious activity such as the attempted unlocking of Lock Smart at odd hours. This gives the owner the ability to deduce if something wrong is happening and allows him to check with the necessary parties (family, friends) before contacting the authorities.
### Cross-platform Web Dashboard (OWASP style, refer to ANNEX B1 of TR64)
As the web app is hosted online, it can be accessed by a variety of devices such as mobile phones, computers, tablets and more. This gives the owner multiple options to unlock his Lock Smart device, whether from his laptop during working hours or on the move using his mobile phone. This ensures that no matter the circumstances, the owner will always be able to unlock his Lock Smart device so long as his device has internet connection.











