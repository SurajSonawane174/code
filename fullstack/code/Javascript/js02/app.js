let name = "Suraj Arun Sonawane";
let mis = 612303174;
let cgpa = 8.23; 
console.log("My full name is: ", name);
console.log(`my name is : ${name} and mis is : ${mis} and cgpa is : ${cgpa}`);
let age = 99;
if(age >= 18){
    console.log("you can vote ");
}else{
    console.log("you cannot vote");
    
}

if(cgpa > 5){
    if(cgpa > 8){
        console.log("you passed the exam with good marks");
    }else{
        console.log("you just passed the exam");
    }  
}else{
    console.log("you are failed in this exam, try again!");
    
}
alert("lets talk about the switch case conditional statements");
let color = prompt("enter the color");
switch(color){
    case "red" :
        console.log("it is a red color");
        break;
    case "blue" :
        console.log("it is a blue color");
        break;
    default :
        console.log("the color is not in the list");
        

}


