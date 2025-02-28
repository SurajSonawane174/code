let name = "           Silver   ";
let newname = name.trim();
console.log(`here is the name after trim ${name}`);
console.log(`here is the new string return by the trim on the name ${newname}`);
name = "Suraj Arun SONAWANE";
console.log(name.toUpperCase());
console.log(name.toLowerCase());

console.log(name.indexOf("Arun"));
console.log(name.indexOf("arun"));
name = "Suraj Arun SONAWANE                    "; 
console.log(name.toLowerCase().trim());

console.log(name.slice(0, 5));
console.log(name.slice(5));
console.log(name.slice(-8));

console.log(name.replace("S", "s"));
console.log(name.repeat(7));


// --------------------Array data structure -------------

let family = ["anna", "mummy", "didi", "jully"];
console.log(family);
console.log(family[0]);
console.log(family[-1]);

let info = ["suraj arun sonawane", 612303174, 8.23, "I-319"];
console.log(info);
family[3]  ="chuha";
family[4] = "kubiiiiii";
console.log(family);
info.push(20);
console.log(info);
console.log(info.pop());
console.log(info);
console.log("shifting and the unshift methods for the array");

info.unshift(20);
console.log(info);

console.log(info.shift());
console.log(info);

let start = ['january', 'july', 'march', 'august'];
let end = ['july', 'june', 'march', 'august'];

start.shift();
start.shift();
start.unshift("june");
start.unshift("july");
console.log(start);
console.log(start.indexOf("march"));
console.log(start.indexOf("March"));
console.log(start.includes("march"));
console.log(start.includes("March"));


console.log("concatination and the reverse of the arrays");

let arr1 = [1, 2, 3, 4, 5];
let arr2 = [5, 6, 7, 8, 9];
let arr3 = arr1.concat(arr2);
console.log(arr3);
console.log(arr3.length);

console.log(arr3.reverse());
console.log(arr3);


let colors = ["red", "yellow", "blue", "orange ", "pink", "white"]




