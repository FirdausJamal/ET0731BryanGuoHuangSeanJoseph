# TR 64 Compliance Checklist

A Checklist is important in assessing how secure the IoT based project is. Below is a compliance checklist we adhered to.

## Attack Surface 1: Web App
### Checklist:
- TR 64 : RS-03
    - Data is sent over secure protocols **[done]**
    
      This was achieved by serving the Web App via HTTPS protocol. Data from user to the Web Server are all encrypted according to the TLS 1.2
      Messages published to Message Query Telemetry Transport(WQTT) topics are also securely published and subscribed via the MQTTS implementation.
      Our system are hence more resistant to malicious attacks targetting the Confidentaility and Integrity of data.

- TR 64 : IA-01
No exposure of session key, token etc **[done]**

    - The self signed certificate to implement SSL uses X.509 Certificate Authority. Encryption keys are stored locally in user files and difficut to 
    access. All user credentials are salted and hashed using the bcrypt algorithm, passwords are never saved in clear text. 


## Attack Surface 2: Web Server
### Checklist:
- TR 64 : AP-02 & CS-01
    - Secured login using 2FA **[done]**
    
    The team has implemented 2FA to control the lock, first requiring a user sign-in and an OTP to be received from user registered email. We used the math Random function without seeding the value, then applying simple arithmetric encryption to represent the value in a 6 digit OTP format.
    
- TR 64 : DP-01 **[done]**

    - Data is not stored in clear text
    User password is salted and hashed with the bcrypt algorithm then saved into a MySQL database.

-TR 64 : RD-03 **[done]**

    - Secure Communications
    The Web Server does not handle Rougue HTTP requests, but only respond to proper HTTPS requests, providing security by obscurity. All keys are stored in hidden dedicated folders in the server.
    
## Attack Surface  3: ESP32
### CHecklist:
- TR 64 : AP-04 **[done]**

    - Tamper-proof Enclosure
    The 3D-printed box requries a 60mm long screwdriver to access. Special screws have been designed, and each screw slot is to be fitted with a special screw bit. 

- TR 64 : AP-03 **[done with proof of concept]**

    - No exposed joints/conenctors to open devices 
    The miro USB of the device is to stuffed with a residual MicroUSB head and hot glued to prevent easy access to rewrite firmware (materials prepared). The hardware serial is hot glued and pins are desoldered, making it difficult to access.
    
- TR 64 : RS-03
    - Secure Communications **[done]**
    
    ESP32 is conencted to a local Access Point protected with WPA-PSK, and communicates with AWS-IoT via MQTTS.
    
## Attack Surface 4; System as a whole
### Checklist:
- TR 64 : LP-01  **[done]**

    - Conducted threat modeling to identify threats
    The team used the STRIDE tool to identify threats on the network architecture, which then led to this compliance checklist. 
    
- TR 64 : LP-02 
    - System designed in a secure way **[done]**
    
    All HTTP and MQTT versions of the web app has been changed to HTTPS and MQTTS, some prototyping ideas such as ESP32 web server has also been abolished in order to decerase attack surface
