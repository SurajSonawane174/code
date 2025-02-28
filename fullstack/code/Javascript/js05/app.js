let delhi = {
    lattitude : "28.7041, N",
    longitude : "77. 1025 E"
};

let student = {
    name : "Suraj Arun Sonawane",
    cgpa : 8.23,
    mis : 612303174
};
console.log(student);
console.log(student.name);
console.log(student.cgpa);
console.log(student.mis);
console.log(typeof(student));

let prop = "name";
console.log(student[prop]);

console.log("updating the objects");
student.name = "Sonawane suraj arun";
student.city = "pune";
student.gender = "male";
console.log(student);

console.log("nesting of the objects");

let info = {
    aman: {
        city : "delhi",
        grade : "A" 
    },
    shraddha : {
        grade: "B",
        city : "pune"
    },
    karan : {
        grade : "C",
        city : "mumbai"
    }
}

console.log(info);
