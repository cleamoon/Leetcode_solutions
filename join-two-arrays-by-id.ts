type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { "id": number } & Record<string, JSONValue>;

const comp = (a, b) => {
    if (a.id > b.id) return 1
    else if (a.id < b.id) return -1
    else return 0
}

function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
    let tmp = { }
    arr1.forEach(e1 => {
        tmp[e1.id] = e1
    })
    arr2.forEach(e2 => {
        const found = tmp[e2.id] || {}
        tmp[e2.id] = { ...found, ...e2 }
    })
    let ret = Object.values(tmp)
    ret.sort(comp)
    return ret as ArrayType[]
};