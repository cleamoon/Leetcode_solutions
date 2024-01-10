type F = (x: number) => number;

function compose (functions: F[]): F {
  return function (x) {
    while (true) {
      const curr = functions.pop()
      if (!curr) break
      x = curr(x)
    }
    return x
  }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */