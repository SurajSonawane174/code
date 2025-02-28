async function greet(){
    return "hello";
}
let url  = "https://catfact.ninja/fact";
fetch(url)
.then((response)=>{
    console.log(response);
    // console.log(response.json());
    response.json().then((data) =>{
        console.log(data);
    })
})
.catch(( er)=>{
    console.log("ERROR-", er);
    
})