let btn = document.querySelector("button");
console.dir(btn); 
console.log(btn); 
let likes = 0;
btn.onclick = ()=>{
    console.log("you liked the image");
    likes++;
};
btn.onmouseenter = ()=>{
    console.log("mouse");
    
}
let say_hello = ()=>{
    console.log("Say Hello");    
};
let say_silver = ()=>{
    console.log("Say Silver");
    alert("hi silver");    
};
    
let eventl = document.querySelector('.event');
eventl.addEventListener("click", say_hello);
eventl.addEventListener("click", say_silver);
