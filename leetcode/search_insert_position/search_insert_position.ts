function searchInsert(nums: number[], target: number): number {
    let right=nums.length-1,left=0,mid=0;
    while(left<=right){
        mid=Math.floor(left + (right - left) / 2)

        if(nums[mid]===target){
            return mid;
        }else if(nums[mid]<target){
            left=mid+1
        }else{
            right=mid-1
        }
    }
    console.log(mid,nums[mid])
    const result=nums[mid]<target?mid+1:nums[mid]>nums[mid-1]?mid:mid-1;
    return result<0?0:result;
};