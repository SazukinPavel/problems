// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Brute Force
// function twoSum(nums: number[], target: number): number[] {
//     for (let i = 0; i < nums.length; i++) {
//         for (let j = 0; j < nums.length; j++) {
//             if (i!=j && nums[i] + nums[j] === target) {
//                 return [i, j]
//             }
//         }

//     }
//     return []
// };

//HashMap
function twoSum(nums: number[], target: number): number[] {
    //number-index map
   const existedNums=new Map<number,number>()
    for (let i = 0; i < nums.length; i++) {
        console.log(existedNums[target-nums[i]]);
        
        if(existedNums[target-nums[i]]!==undefined){
            return [i,nums[i]]
        }

        existedNums[nums[i]]=i;
    }
    return []
};