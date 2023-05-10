const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = '';
let a;

rl.on('line', function (line) {
    input = line;
}).on('close',function(){
    for(let i=0; i<input.length;i++){
    if(input[i].toUpperCase()==input[i]) {a=input[i].toLowerCase();process.stdout.write(a);}
    if(input[i].toLowerCase()==input[i]) {a=input[i].toUpperCase();process.stdout.write(a);}
    }
    
});