// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
function groupAnagrams(strs: string[]): string[][] {
    const variationMap=new Map<string,number[]>();
    for(let i=0;i<strs.length;i++){
        const key=strs[i].split('').sort().join('')
        if(variationMap.get(key)){
            variationMap.set(key,[...variationMap.get(key) || [],i])
        }else{
            variationMap.set(key,[i])
        }
    }

    const result:string[][]=[]

    for (const value of variationMap.values()) {
        result.push(value.map((index)=>strs[index]))
    }

    return result
}