type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (value: JSONValue) => number

function sortBy (arr: JSONValue[], fn: Fn): JSONValue[] {
  const cmp = (a: JSONValue, b: JSONValue): number => {
    if (fn(a) < fn(b)) return -1
    else if (fn(a) > fn(b)) return 1
    else return 0
  }
  arr.sort(cmp)
  return arr
};