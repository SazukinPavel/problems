// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.



function searchRange(nums: number[], target: number): number[] {
    let mid = 0, low = 0, high = nums.length
    while (low <= high) {
        mid = Math.floor((low + high) / 2)
        if (target === nums[mid]) {

            const result: number[] = [];
            while (nums[mid] === target) {
                mid--
            }
            mid++;
            result.push(mid)
            while (nums[mid] === target) {
                mid++
            }
            mid--;
            result.push(mid)
            return result
        }
        else if (target > nums[mid])
            low = mid + 1
        else
            high = mid - 1
    }
    return [-1, -1]
};