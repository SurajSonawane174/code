alert("Lets play the guessing game");
let max =prompt("enter the max number");
let num = prompt("guess the number");
let random = Math.floor(Math.random() * max + 1);
console.log(random);

while(1){
    num = prompt("try again and guess the number");
    if(num == random){
        alert("you  won the game !!!!!! ");
        break
    }else if(num == -1){
        break;
    }
}