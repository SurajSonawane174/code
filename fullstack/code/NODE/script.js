// console.log(process.argv);
// const somevalue = require("./math");
// console.log(somevalue);


// const info = require("./fruits");
// console.log(info);
// console.log(info[0].name);



import { sum, PI } from "./math.js";   
import {generate, count} from "random-words";
console.log(sum(45234, 24562));
console.log(PI);

console.log(generate());
//output: 'army'

console.log(generate(5));
//output: ['army', 'beautiful', 'became', 'if', 'actually']

console.log(generate({ minLength: 2 }));
//output: 'hello'

console.log(generate({ maxLength: 6 }));
//output: 'blue'

console.log(generate({ minLength: 5, maxLength: 5 }));
//output : 'world' 