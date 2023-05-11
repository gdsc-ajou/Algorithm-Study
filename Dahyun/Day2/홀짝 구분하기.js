const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input;

rl.on('line', function (line) {
    input =Number(line);
}).on('close', function () {
    if(input%2==0) {console.log(input,"is even")};
    if(input%2==1) {console.log(input,"is odd")};
    
});