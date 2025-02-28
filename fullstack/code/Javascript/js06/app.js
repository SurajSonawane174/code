function factorial(n){
    if(n == 1 || n == 0) return 1;
    return factorial(n-1) * n;
}

function roll (){
    let n = Math.floor(Math.random() * 6 + 1);
    console.log(n);
    
}
console.log(factorial(5));
const sum = function sum(a, b){
    return a + b;
}

function multiple_greet(func, n){
    for(let i= 0; i < n; i++){
        func();
    }
}
function greet(){
    console.log("welcome");
    
}

console.log(sum(4, 6));
multiple_greet(greet, 5)

const calculator = {
    add: function(a, b){
        return a + b;
    },
    sub: function(a, b){
        return a -b;
    },
    divide : function(a, b){
        return a / b;
    },
    multiply(a, b){
        return a * b;
    }
};

console.log(calculator.add(4, 5));
