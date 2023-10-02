/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

//recursion (slow runtime,good memory)
// var reduce = function(nums, fn, init) {
//     var reduceHelp=(sum,i)=>{
//         if(i>=nums.length){
//             return sum
//         }

//         sum=fn(sum,nums[i])
//         return reduceHelp(sum,i+1)
//     }   

//     return reduceHelp(init,0)
// };

//for (good memory,good runtime)
var reduce = function(nums, fn, init) {
    let result=init;
    for (let index = 0; index < nums.length; index++) {
        result=fn(result,nums[index])
    }

    return result
};
