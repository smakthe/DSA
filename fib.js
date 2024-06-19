let counter = 0

function fibonacci(n){
    const memorize = {};
    
    function helper(n){
        counter++;
        if (n in memorize) return memorize[n];
        if (n<3) return 1;
        return memorize[n] = helper(n-1)+helper(n-2);
    }
    
    return helper(n);
}

console.log(fibonacci(3))
console.log(counter)