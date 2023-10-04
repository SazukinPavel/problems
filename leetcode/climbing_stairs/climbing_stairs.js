/**
 * @param {number} n
 * @return {number}
 */


// var climbStairs = function (n) {
//     const cache = new Map()

//     function climbStairsHelp(n) {
//         if (n < 2) {
//             return 1
//         }


//         if (!cache.has(n)) {
//             cache.set(n, climbStairsHelp(n - 1) + climbStairsHelp(n - 2))
//         }

//         return cache.get(n)
//     }

//     return climbStairsHelp(n)
// };


var climbStairs = function (n) {
    if (n < 2) {
        return 1
    }

    let prev = 1, curr = 2, next = 2;

    for (let index = 2; index < n; index++) {
        next = prev + curr
        prev = curr
        curr = next
    }

    return next
};
console.log(climbStairs(46));