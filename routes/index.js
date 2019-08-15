var express = require('express'); //  include middleware
var router = express.Router();
var bcrypt = require('bcrypt');
var AWS = require('aws-sdk');
const session = require('express-session');
var randomOtp = Math.floor(100000 + Math.random() * 900000);

router.use(session({ secret: 'ssshhhhh' }));

//Global variables
const saltRound = 10;
var ootp;

AWS.config.update({ region: "us-east-1" });
process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';

/* GET home page. */
router.get('/', function (req, res, next) {
  res.render('loginPage', { title: 'Login' });
});

router.post('/controlPage', function (req, res, next) {
  var sess = req.session;
  sess.username = req.body.Username;
  var password = req.body.Password;
  const db = require("../database");
  const device = require("../awsIot");
  console.log(sess.username);


  db.query("SELECT username, password FROM account WHERE username = ?", [sess.username], function (error, result, field) {
    if (error) return next(error);
    if (result.length == 0) {
      res.render('loginPage', { title: "Login", error: "Sorry this username does not exist" });
    } else {
      const pass = result[0].password.toString();
      console.log(result);
      bcrypt.compare(password, pass, function (error, response) {
        if (response === true) {
          console.log("password match")
          device.on('connect', function () {
            console.log('connected');
          });
          res.render('controlPage', { title: "Key Selection" });
        } else {
          console.log("does not match")
          res.render('loginPage', { title: "Login", error: "Wrong Password!" });
        }
      });
    }
  });
});

router.get('/register', function (req, res, next) {
  res.render('signupPage', { title: 'Register' });
});

router.post('/loginPost', function (req, res, next) {

  var username = req.body.Username;
  var email = req.body.Email;
  var password = req.body.Password;
  const db = require("../database");
  bcrypt.hash(password, saltRound, function (error, hash) {
    db.query("SELECT username, email FROM account WHERE username = ? OR email = ?", [username, email], function (error, result, fields) {
      if (error) return next(error);
      if (result.length == 0) { //  if there is no such row in the database
        db.query("INSERT INTO account (username, email, password) VALUES (?, ?, ?)", [username, email, hash], function (error, result, field) {
          if (error) return next(error);
          res.redirect('/')
        });
      } else {
        res.render('signupPage', { title: 'Register', error: 'sorry the user already exists!' });
      }
    });
  });
});

router.post('/otpPost', function (req, res, next) {
  var sess = req.session;
  var userEmail;
  const device = require("../awsIot");
  const db = require("../database");
  console.log("test ", sess.username);

  db.query("SELECT username, email FROM account where username = ?", [sess.username], function (error, results, field) {
    if (error) return next(error);
    console.log("before ", results);
    //userEmail = results[0].email;
    console.log("after ", userEmail);
    ootp = randomOtp.toString();
    ootpStringified = JSON.stringify({ otpFromWebserver: ootp });
    device.publish('OTP/G', ootp);
    sendEmail(senderEmail = "locksmart0731@gmail.com", receipientEmail = results[0].email, CCEmail = "bryanteepakhong.17@ichat.sp.edu.sg", messageSubject = "An OTP Request has been made", messageBody = ootp);
    console.log('working?');
  });

  // device.on('connect', function () {
  //   console.log('connect');
  //   device.publish('test');
  // });



  device
    .on('message', function (topic, payload) {
      console.log('message', topic, payload.toString());
    });
  res.render('otp', { title: "OTP" });
});

router.post('/logOut', function (req, res, next) {

  var otp = req.body.otp;
  const device = require("../awsIot");

  console.log('connect2');
  //device.subscribe('topic/sub/otp');
  device.publish('OTP/R', JSON.stringify({ otpFromUser: otp }));
  console.log('success2');

  device
    .on('message', function (topic, payload) {
      console.log('message', topic, payload.toString());

      req.session.destroy(function (err) {
        if (err) {
          return console.log(err);
        }
      });
    });
  res.render('accessGranted.hbs', { title: "access granted!" });
});


module.exports = router;


// Create sendEmail params 

function sendEmail(senderEmail = "locksmart0731@gmail.com", receipientEmail = "bryantee1998@gmail.com", CCEmail = "bryanteepakhong.17@ichat.sp.edu.sg", messageSubject = "Test Message", messageBody = "This is a Test message") {
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
          Data: messageBody
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
  var ses = new AWS.SES({ apiVersion: '2010-12-01' }).sendEmail(params).promise();

  // Handle promise's fulfilled/rejected states
  ses.then(
    function (data) {
      console.log(data.MessageId);
    }).catch(
      function (err) {
        console.error(err, err.stack);
      });
}