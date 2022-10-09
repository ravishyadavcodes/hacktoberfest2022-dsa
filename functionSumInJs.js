// by wendell00

function sum(){
    let args = [].slice.call(arguments, 0);
    let sum = 0;
    for(let i = 0; i < args.length; i++){
        sum += args[i];
    }
    return sum
}

console.log(sum(1,5))
console.log(sum(8,0,9,8,5))
console.log(sum(0,3,2))
console.log(sum(1))