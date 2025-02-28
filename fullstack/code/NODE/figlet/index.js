const figlet = require("figlet");
figlet("THERE  ARE  ONLY  TWO  TIME  THAT  I  WANTS  TO  BE WITH  YOU  NOW  AND  FOREVER", function (err, data) {
    if (err) {
      console.log("Something went wrong...");
      console.dir(err);
      return;
    }
    console.log(data);
  });