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
