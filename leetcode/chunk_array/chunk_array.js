/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  const result = [];
  let i = 0;
  arr.forEach((item, index) => {
    if (index % size === 0) {
      i = 0;
    }
    if (!result[Math.floor(index / size)]) {
      result[Math.floor(index / size)] = [];
    }

    result[Math.floor(index / size)].push(item);

    i++;
  });

  return result;
};
