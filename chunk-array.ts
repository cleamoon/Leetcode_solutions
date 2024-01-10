type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk (arr: Obj[], size: number): Obj[][] {
  const ans: Obj[][] = []
  for (let i = 0; i * size < arr.length; i++) {
    const tmp = []
    for (let j = i * size; j < Math.min((i + 1) * size, arr.length); j++) {
      tmp.push(arr[j])
    }
    ans.push(tmp)
  }
  return ans
};
