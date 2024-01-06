type Fn = (...params: number[]) => number

function memoize (fn: Fn): Fn {
  const argsToRes = {}
  return function (...args) {
    const argumentsString = JSON.stringify(args)
    if (argumentsString in argsToRes) {
      return argsToRes[argumentsString]
    } else {
      const res = fn(...args)
      argsToRes[argumentsString] = res
      return res
    }
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */