/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    const result = [];
    let i = 0, j = 0;
    while (i < arr1.length || j < arr2.length) {
        if (arr1[i]?.id > arr2[j]?.id) {
            result.push({ ...arr2[j] })
            j++;
        } else if (arr1[i]?.id < arr2[j]?.id) {
            result.push({ ...arr1[i] })
            i++;
        } else {
            result.push({ ...arr1[i], ...arr2[j] })
            j++;
            i++;
        }
    }
    return result.sort((a, b) => a.id - b.id)
};