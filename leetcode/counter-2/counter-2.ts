// Write a function createCounter. It should accept an initial integer init. It should return an object with three functions.

// The three functions are:

// increment() increases the current value by 1 and then returns it.
// decrement() reduces the current value by 1 and then returns it.
// reset() sets the current value to init and then returns it.


type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number):
    ReturnObj {

    this.count = init;
    this.init = init;

    this.increment = () => {
        this.count++;
        return this.count;
    }

    this.decrement = () => {
        this.count--;
        return this.count;
    }

    this.reset = () => {
        this.count = this.init;
        return this.count;
    }

    return this
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */