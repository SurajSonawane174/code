const { faker } = require('@faker-js/faker');
const mysql = require('mysql2');
let  createRandomUser = ()=> {
    return {
      userId: faker.string.uuid(),
      username: faker.internet.username(), // before version 9.1.0, use userName()
      email: faker.internet.email(),
      avatar: faker.image.avatar(),
      password: faker.internet.password(),
      birthdate: faker.date.birthdate(),
      registeredAt: faker.date.past(),
    };
  }
let  getrandomuser = ()=> {
    return {
      Id: faker.string.uuid(),
      username: faker.internet.username(), // before version 9.1.0, use userName()
      email: faker.internet.email(),
      password: faker.internet.password(),
    };
  }

//   console.log(createRandomUser());
// console.log(getrandomuser());



// Create the connection to database
const connection =  mysql.createConnection({
    host: 'localhost',
    user: 'root',
    database: 'delta_app',
    password: 'Silver@9527',
  });
try {
    connection.query("SHOW TABLE", (err, result)=>{
        if(err) throw err;
        console.log(result);
      });
} catch (err) { 
    console.log(err);
    
}
  
  