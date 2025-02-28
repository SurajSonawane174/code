const express = require("express");
const app = express();
const port = 8080;
app.listen(port, ()=>{
    console.log("listening from port ${port}");
    
}); 
const path = require("path");
// this package is usefull for the path.join it simply joins the paths of curr dir and the view
app.set("view engine", "ejs");
//ejs automatically require the ejs package
app.set("views", path.join(__dirname, "/views"));// it is  usefull when we are starting the server from diff dir and view js is in other folder
app.get("/", (req, res)=>{
    // res.send("this is root"); 
    res.render("home.ejs");
});
app.get("/rolldice", (req, res)=>{
    // res.send("this is the rolldice page"); 
    let dicevalue = Math.floor(Math.random()*6 ) +1;
    const subjects = ["oopd", "co", "toc", "bfsi", "poe", "echo", "coi"];
    res.render("rolldice", {dicevalue, subjects});
});

app.get("/hello", (req, res)=>{
    res.send("this is hello"); 
    // res.render("home.ejs");
});