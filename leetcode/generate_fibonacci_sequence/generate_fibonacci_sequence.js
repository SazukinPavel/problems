/**
 * @return {Generator<number>}
 */
var fibGenerator = function* () {
  let curr = 0,
    next = 1;
  yield curr;
  yield next;

  while (true) {
    let c = next + curr;
    curr = next;
    next = c;
    yield c;
  }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
