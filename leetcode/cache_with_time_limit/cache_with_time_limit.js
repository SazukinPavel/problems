
var TimeLimitedCache = function () {
    this.cache = new Map()
    this.timerMap = new Map()
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    const timerId = setTimeout(() => this.cache.delete(key), duration)

    const result = timerMap.get(key)

    if (!!result) {
        clearTimeout(result)
    }
    this.timerMap.set(key, timerId)

    this.cache.set(key, value)

    return !!result
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    return this.cache.get(key) || -1
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    return [...this.cache.keys()].length
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */