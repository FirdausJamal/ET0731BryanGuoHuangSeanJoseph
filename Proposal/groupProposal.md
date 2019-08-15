# Lock Smart Proposal

## Why a Smart Lock?

When in search of the best way to protect our houses, it has always been using a physical lock as it boasts simplicity and effectiveness. However, not all locks are made equal, and all of them require the analog presence of an authorized user, which are our family members. As we approach a more modern and competitive Singapore, the need of a smart system to remotely grant access to individuals we do not fully trust may be required, such as our babies’ nanny, package delivery man, friends etc.  How can we allow people to achieve this goal without breaking the bank, while maintaining digital and analog security? 


## What is Lock Smart?

Lock Smart is a reliable lock that can be unlocked remotely, either through mobile devices or computers, while allowing authorized users to use it as simple as traditional analog locks. Lock Smart features advanced security protocols such as data encryption and 2-factor authentication. Due to the nature of such a device, it is part of the Internet of Things (IoT) that easily integrates into our home networks without being intrusive. 

## Features of Lock Smart 
	
We have referred to the IoT security requirement Category of Technical Reference 64 (TR64) while designing the features of our system. We have decided to consider three main factors while designing this product - Data Protection (DP), Access Protection (AP) and Security Management (MT). Some of these may depend on other basic categories, and as such may be required to reference to in the future.

### Electromagnetic Lock with Smart Alarm System
  - Difficult to tamper with
  - Strong locking mechanism
### 2-Factor Authentication
  - Prevents unauthorized access even if account is hijacked
### Email Alerts via AWS SES
  - Track Activity of OTPs
  - 24/7 as long as device receiving emails has internet access
### Cross-platform Web Dashboard (OWASP style, refer to ANNEX B1 of TR64)
  - Access via phones
  - Access via computers
 
## Why not use a normal lock?

A normal lock requires the same key to be distributed to various members of the household. This may seem like an easy task, but what if someone loses their keys? Sure, you could use a spare key if you have one hanging around or you could also engage the services of a locksmith. However, there is a better way to do this which is to simply have a Lock Smart account shared by the household. Since it is not a physical device, it cannot be physically lost. Also, since only members of the households know about the username and password, it cannot be easily replicated by potential housebreakers. Furthermore, a mobile device can be used to unlock Lock Smart remotely, meaning you can unlock it while going up the elevator or right before reaching your doorstep. This saves users the hassle of opening bags or fiddling around pockets to get the key out and slowly unlock a traditional lock.

## What about security?

As Lock Smart is part of the Internet of Things (IoT), it is definitely prone to online threats. This is something that IoT products cannot escape from due to the nature of such products. Hence, the only safe way to use IoT products without being compromised is by implementing comprehensive security to it. Lock Smart does so by using secure protocols such as HTTPS and MQTTS, salting and hashing of passwords in the database and encrypting data, just to name a few. These security implementations ensure that Lock Smart cannot be easily tempered with if done correctly.

## Conclusion

Lock Smart is a smart lock which aims to provide utmost convenience to its users while at the same time ensuring that it is not easily compromised by hackers and the like.










