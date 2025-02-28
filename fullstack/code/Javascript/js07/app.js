const student ={
    name: "suraj", 
    mis: 612303174, 
    cgpa : 8.23, 
    print(){
        console.log(this.name);
        console.log(this.mis);
        console.log(this.cgpa);
        

    }
}; 
student.print();

const sum = (a, b)=> {
    return a+b;
};

// const sum = (a, b)=> a+b;
console.log(sum(345, 345));

setTimeout(()=>{
    console.log("this is due to timeout function");
}, 4000);

console.log("it is being executed before the timeout function");


