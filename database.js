var mysql = require("mysql");

var connection = mysql.createConnection({
    host    :   "localhost",
    user    :   "root",
    password:   "",
    database:   "iots_project"
});

connection.connect(function(error, result){
    if(!error){
        console.log("connection successful!");
    }else{
        console.log("please check your connection!");
    }
});

module.exports = connection;    //  allow other javascript file to use the variable here by requiring it