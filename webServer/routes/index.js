var express = require('express'); //  include middleware
var router = express.Router();
var bcrypt = require('bcrypt');
var randomOtp = Math.floor(100000 + Math.random() * 900000);

process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';

const saltRound = 10;

const queryString = require('querystring');
const https = require('https');


/* GET home page. */
router.get('/', function (req, res, next) {
  res.render('loginPage', { title: 'Login' });
});

router.post('/login', function (req, res, next) {
  var username = req.body.Username;
  var password = req.body.Password;

  const db = require("../database");

  db.query("SELECT username, password FROM account WHERE username = ?", [username], function (error, result, field) {
    if (error) return next(error);
    if (result.length == 0) {
      res.render('loginPage', { title: "Login", error: "Sorry this username does not exist" });
    } else {
      const pass = result[0].password.toString();
      console.log(result);
      bcrypt.compare(password, pass, function (error, response) {
        if (response === true) {
          console.log("password match")
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

router.post('/registerPost', function (req, res, next) {
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

router.post('/controlPage', function (req, res, next) {

  var postOTP = "foodstalls=Makan Corner";
  
  var options = {
    hostname: 'localhost',
    path: '192.168.43.249:5000/eat',
    method: 'POST',
    headers: {
        'Content-Type':'text/json',
        'Content-Length': postOTP.length
    }
  };
  
  var secureReq = https.request(options, (res) => {
    console.log('statusCode:', res.statusCode);
    console.log('headers:', res.headers);
  
    res.on('data', (d) => {
      process.stdout.write(d);
    });
  });
  
  secureReq.on('error', (e) => {
    console.error(e);
  });
  
  secureReq.write(postOTP);
  secureReq.end();
   


  res.render('otp', { title:"OTP" })
});

router.post('/otpPost', function (req, res, next) {



})
module.exports = router;
