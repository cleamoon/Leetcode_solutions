type Fn = (...params: any[]) => Promise<any>;

function timeLimit (fn: Fn, t: number): Fn {
  const timer = new Promise((_, reject) => setTimeout(reject, t, "Time Limit Exceeded"))

  return async function (...args) {
    return Promise.race([timer, new Promise((resolve) => resolve(fn(...args)))])
  }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */