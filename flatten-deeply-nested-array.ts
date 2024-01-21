type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number, result: MultiDimensionalArray = []): MultiDimensionalArray {
  if (n === 0) return arr

  if (n === 1) {
    arr.forEach(value => {
      if (Array.isArray(value)) {
        value.forEach(subValue => {
          result.push(subValue)
        })
      } else {
        result.push(value)
      }
    })
    return result
  }

  arr.forEach(value => {
    if (Array.isArray(value)) {
      flat(value, n - 1, result)
    } else {
      result.push(value)
    }
  })

  return result
};