var awsIot = require('aws-iot-device-sdk');

var device = awsIot.device({
  keyPath: 'C:/Users/GH_/Desktop/awsIotKeys/b5bc6dd74a-private.pem.key',
  certPath: 'C:/Users/GH_/Desktop/awsIotKeys/b5bc6dd74a-certificate.pem.crt.txt',
  caPath: 'C:/Users/GH_/Desktop/awsIotKeys/AmazonCA1Certificate.txt',
  host: 'aa5nyidma5p15-ats.iot.us-east-1.amazonaws.com',
  port: '8883'
});

module.exports = device;