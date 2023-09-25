class EventEmitter {
  #events;
  constructor() {
    this.#events = new Map();
  }

  subscribe(event, cb) {
    if (!this.#events.has(event)) {
      this.#events.set(event, []);
    }
    const listeners = this.#events.get(event);

    listeners.push(cb);

    return {
      unsubscribe: () => {
        listeners.splice(listeners.indexOf(cb), 1);
      },
    };
  }

  emit(event, args = []) {
    const callbacks = this.#events.get(event);

    return callbacks ? [...callbacks.map((cb) => cb(...args))] : [];
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
