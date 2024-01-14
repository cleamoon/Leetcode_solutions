type Callback = (...args: any[]) => any;
type Subscription = {
  unsubscribe: () => void
}

class EventEmitter {
  subscribers = {}
  subscribe (eventName: string, callback: Callback): Subscription {
    if (this.subscribers[eventName]) {
      this.subscribers[eventName].push(callback)
    } else {
      this.subscribers[eventName] = [callback]
    }
    return {
      unsubscribe: () => {
        const index = this.subscribers[eventName].indexOf(callback)
        if (index !== -1) {
          this.subscribers[eventName].splice(index, 1);
        }
      }
    };
  }

  emit (eventName: string, args: any[] = []): any[] {
    if (!this.subscribers[eventName]) return []
    const res: any[] = []
    this.subscribers[eventName].forEach((sub) => {
      res.push(sub(...args));
    })
    return res
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */