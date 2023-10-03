/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    const result = Array.isArray(obj) ? [] : {}
    for (const key of Object.keys(obj)) {
        if (obj[key]) {
            if (typeof obj[key] === 'object') {
                result[key] = compactObject(obj[key])
            } else {
                result[key] = obj[key]
            }
        }
    }

    return Array.isArray(result) ? result.filter(a => !!a) : result
};