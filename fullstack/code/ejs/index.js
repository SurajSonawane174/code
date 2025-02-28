//this file will act as a server 
const express = require("express");
const app = express();
// here express is an function which will return us something values
// app is server side web application   ,it is actually an object

// console.dir(app);
let port = 3000;//(listen function takes two arguments port, function)
app.listen(port, ()=>{
    console.log(`app listeninig on the port ${port}`);
    
});
// app.use((req, res)=>{
//     console.log(req);
//     console.log("request recieved");
//     // res.send("this is a basic repsonse");    
//     // res.send({
//     //     name : "suraj",
//     //     mis: 612303174,
//     //     div: 2
//     // });
//     res.send("<div><h1>Fruits</h1> <ul>mango</ul><ul>orange</ul><ul>banana</ul></div>");
    
// });
// app.get("/apple", (req, res)=>{
//     res.send({
//         name: "apple",
//         color: "crimson red",
        
//     });
// });
// app.get("/banana", (req, res)=>{
//     res.send({
//         name: "banana",
//         color: "yellow",
        
//     });
// });
// app.get("/orange", (req, res)=>{
//     res.send({
//         name: "orange",
//         color: "orange",
        
//     });
// });
app.get("/", (req, res)=>{
    res.send("you are at home page, here is the root and changes");
});
app.get("/:username", (req, res)=>{
    console.log(req.params);
    
    res.send("you are at home page, here is the root and changes");
});
app.get("*", (req, res)=>{
    res.send("you are at wrong page");
});