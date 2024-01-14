declare global {
  interface Array<T> {
    groupBy (fn: (item: T) => string): Record<string, T[]>
  }
}

Array.prototype.groupBy = function (fn) {
  return this.reduce((accum, curr) => {
    const key = fn(curr)
    if (accum[key]) {
      accum[key].push(curr)
    } else {
      accum[key] = [curr]
    }
    return accum
  }, {})
}

/**
* [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
*/