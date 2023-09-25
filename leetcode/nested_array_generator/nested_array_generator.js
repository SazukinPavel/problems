/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {
  if (Array.isArray(arr)) {
    for (let index = 0; index < arr.length; index++) {
      yield* inorderTraversal(arr[index]);
    }
  } else {
    yield arr;
  }
};

const gen = inorderTraversal([1, [2, 3]]);
console.log(gen.next().value, gen.next().value, gen.next().value);
