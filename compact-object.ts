type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function compactObject (obj: Obj): Obj {
  if (obj === null) return obj;
  if (Array.isArray(obj)) return obj.filter(Boolean).map(compactObject as (value: JSONValue, index: number, array: JSONValue[]) => Obj);
  if (typeof obj !== "object") return obj;

  const res = {};
  for (const key in obj) {
    const val = compactObject(obj[key] as Obj);
    if (val) res[key] = val
  }
  return res;
};