// Create sendEmail params 

function sendEmail(senderEmail = "locksmart0731@gmail.com", receipientEmail = "bryantee1998@gmail.com", CCEmail="bryanteepakhong.17@ichat.sp.edu.sg", messageSubject="Test Message"){
var params = {
    Destination: { /* required */
      CcAddresses: [
        CCEmail,
        /* more items */
      ],
      ToAddresses: [
        receipientEmail,
        /* more items */
      ]
    },
    Message: { /* required */
      Body: { /* required */
        Html: {
         Charset: "UTF-8",
         Data: "HTML_FORMAT_BODY"
        },
        Text: {
         Charset: "UTF-8",
         Data: "TEXT_FORMAT_BODY"
        }
       },
       Subject: {
        Charset: 'UTF-8',
        Data: messageSubject
       }
      },
    Source: senderEmail /* required */
  };
  
  // Create the promise and SES service object
  var ses = new AWS.SES({apiVersion: '2010-12-01'}).sendEmail(params).promise();
  
  // Handle promise's fulfilled/rejected states
  ses.then(
    function(data) {
      console.log(data.MessageId);
      ses.sendEmail(params, function(err, data){
          if (err) console.log(err, err.stack);
          else console.log(data);
      });
    }).catch(
      function(err) {
      console.error(err, err.stack);
    });
}