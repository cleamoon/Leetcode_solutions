type Fn<T> = () => Promise<T>

function promiseAll<T> (functions: Fn<T>[]): Promise<T[]> {
  return new Promise((resolve, reject) => {
    const result = new Array(functions.length)
    let finishedCount = 0

    functions.forEach((fn, i) => {
      fn()
        .then(res => {
          result[i] = res
          finishedCount += 1
          if (finishedCount === functions.length) return resolve(result)
        })
        .catch(error => reject(error))
    })
  })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */