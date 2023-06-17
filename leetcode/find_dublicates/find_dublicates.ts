function findDuplicate(nums: number[]): number {
    const existed = new Map<number, boolean>()

    let i = 0;
    while (!existed[nums[i]]) {
        existed[nums[i]] = true
        i++;
    }

    return nums[i]
};