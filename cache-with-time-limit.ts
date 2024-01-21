class TimeLimitedCache {
  dict = {}
  timerCount = 0

  constructor() {
  }

  set (key: number, value: number, duration: number): boolean {
    let found = this.dict[key]
    if (found) {
      clearTimeout(this.dict[key].timer)
    } else {
      this.timerCount += 1
      this.dict[key] = {}
    }
    this.dict[key].value = value
    this.dict[key].timer = setTimeout(() => {
      delete this.dict[key]
      this.timerCount -= 1
    }, duration)
    return Boolean(found)
  }

  get (key: number): number {
    const result = this.dict[key]
    if (result) return result.value
    else return -1
  }

  count (): number {
    return this.timerCount
  }
}

/**
* const timeLimitedCache = new TimeLimitedCache()
* timeLimitedCache.set(1, 42, 1000); // false
* timeLimitedCache.get(1) // 42
* timeLimitedCache.count() // 1
*/