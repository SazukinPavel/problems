/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        const ans = [];
        let j = functions.length
        functions.forEach((f, i) => {
            f().then((data) => {
                ans[i] = data
                j--
                if (j === 0) {
                    resolve(ans)
                }
            }).catch(e => reject(e))
        })
    })
};
