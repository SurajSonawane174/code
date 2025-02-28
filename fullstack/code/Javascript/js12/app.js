// function savetodata(data, success, failuar){
//     let internet = Math.floor(Math.random()*10) + 1;
//     if(internet >= 4){
//         success();
        
//     }
//     else {
//         failuar();
//     }
// };
// let success = ()=>{
//     console.log("your data was saved");
//     savetodata("aparna", ()=>{
//         console.log("success 2: data 2 saved");
//     }, ()=>{
//         console.log("failuar 2: data not saved");
//     }); 
// };
// let failuar = ()=>{
//     console.log("weak connetction data not saved");
// }
// savetodata("silver", success, failuar);


// using promises

function savetodatabase(data){
    return new Promise((resolve, reject)=>{
        let internetspeed = Math.floor(Math.random() * 10) + 1;
        if(internetspeed >4){
            resolve("success: data was saved");
        }else{
            reject("failuar: weak data connection");
        }
    });       
}
// console.log(req);
savetodatabase("apana college")
.then(()=>{
    console.log("promise was resolve");
})
.catch(()=>{
    console.log("promise was rejected");
    
});