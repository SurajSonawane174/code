 

arr.forEach(function(el){
    console.log(el);
    
});
arr.forEach((el)=>{
    console.log(el*el);
    
});

for (const element of arr) {
    console.log(element/ 10);
    
}

let even = arr.filter((el)=>{
    return (el % 2 == 0)});
console.log(even);
