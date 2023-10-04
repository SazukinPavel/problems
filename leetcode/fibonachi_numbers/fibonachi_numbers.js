/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    function fibHelp(){
        if(n<3){
        return 1
    }

    return fib(n-1)+fib(n-2)
    }

    if(n===0){
        return 0
    }

    return fibHelp(n)
};