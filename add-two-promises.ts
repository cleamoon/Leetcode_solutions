type P = Promise<number>

async function addTwoPromises (promise1: P, promise2: P): P {
  let ans1 = 0

  return promise1.then(value => {
    ans1 = value
    return promise2
  }).then(value => value + ans1)
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */