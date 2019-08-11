# IoT Security Report
# Contents
1. Overview of Lock Smart
2. Features of Lock Smart
3. User Journey
4. TR 64 References
5. Security Testing
## 1: Overview of Lock Smart
Lock Smart is a reliable lock that can be unlocked remotely, either through mobile devices or computers. Lock Smart features advanced security protocols such as data encryption and 2-factor authentication. Due to the nature of such a device, it is part of the Internet of Things (IoT) that easily integrates into our home networks without being intrusive.
## 2: Features of Lock Smart
### 2.1: 2-Factor Authentication (2FA) (Lock Smart account + Email)
Authorized accounts can unlock the Lock Smart by logging into a web page. They must log into the web page with their Lock Smart account. Once logged in,the owner will choose which lock he wants to unlock then, a One-Time Pin (OTP) will be sent to their email. The owner must then enter the OTP to the field provided on the Lock Smart Web App (AP-02).

### 2.2: Cross-platform Web Dashboard (OWASP style, refer to ANNEX B1 of TR64)
Prior to using Lock Smart, the owner must create a Lock Smart account and enter the Serial Identification (SID) of the lock into the Lock Smart Web App to gain ownership of the lock digitally. 
All Lock Smart users must first associate a username and a strong password with the said Web App (MT01, IA-01, DP-03). Once the account is created and the lock is linked, only that account can unlock Lock Smart remotely. (Security Management.)



### 2.3: Password Policy (MT01)

Passwords must adhere to the following:
1)	Minimum of 8 characters
2)	One uppercase letter
3)	One lowercase letter
4)	One Number
5)	One Special Character
6)	Password cannot be the same as username
7)	Passwords have to be updated every 6 months. 
Failure to comply with 7) will result in the account losing its authorised status.
## 3: User Journey
The owner will have to create an account on the Lock Smart website and link the lock and their email to their account. After which whenever the owner wants to unlock the lock he will have to log in using his credentials and select which lock to unlock. After selection a 6 digit otp will be generated and sent to the owners email to be input onto the website to unlock the lock.


## 4: TR 64 Reference
IoT Threat assessment:
System Susceptibility:
Physical Tampering
Social Engineering

System accessibility
Attacker Capability

## 5: Security Testing
