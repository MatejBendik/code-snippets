const express = require('express')
const bodyParser = require('body-parser')
const mongoose = require("mongoose");

const app = express()
const port = 3000

app.use(bodyParser.urlencoded({extended: true}));

mongoose.connect("mongodb://localhost:27017/demoDB");

const demoSchema = new mongoose.Schema({
  name: String,
  number_of_players: Number
});

const Demo = mongoose.model("Demo", demoSchema);

app.get('/', function(req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.post("/",function(req,res){
    
const demo = new Sport({
    name: req.body.name,
    password: req.body.password
});

demo.save(function(err){
    if(!err){
        console.log("Successfully saved post");
        res.redirect("/");
    }else{
        console.log(err);
    }
});
});

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})