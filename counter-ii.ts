type Counter = {
  increment: () => number,
  decrement: () => number,
  reset: () => number,
}

function createCounter (init: number): Counter {
  let value = init

  return ({
    increment: () => {
      value += 1
      return value
    },
    decrement: () => {
      value -= 1
      return value
    },
    reset: () => {
      value = init
      return init
    },
  })
};

/**
* const counter = createCounter(5)
* counter.increment(); // 6
* counter.reset(); // 5
* counter.decrement(); // 4
*/