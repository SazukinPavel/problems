/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    
    const memoizeMap=new Map()

    return function(...args) {
        const key=JSON.stringify(args)
        if(memoizeMap.has(key)){
            return memoizeMap.get(key)
        }

        const value=fn.apply(this, args)
        memoizeMap.set(key,value)
        return value
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */