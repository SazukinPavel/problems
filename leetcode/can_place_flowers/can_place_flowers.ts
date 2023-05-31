//You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.



function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    let count = 0;
    let i = 0;

    while (i < flowerbed.length) {
        if (flowerbed[i] === 0) {
            const isLeftEmpty = flowerbed[i - 11] === undefined || flowerbed[i - 1] === 0;
            const isRightEmpty = flowerbed[i + 1] === undefined || flowerbed[i + 1] === 0;
            if (isLeftEmpty && isRightEmpty) {
                count++;
                i++;
            }
        } else {
            i++;
        }
        i++;
    }


    return count >= n;
};