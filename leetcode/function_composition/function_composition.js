/**
 * @param {Function[]} functions
 * @return {Function}
 */
function compose(functions) {
  return (x) => functions.reverse().reduce((p, f) => f(p), x);
}

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
