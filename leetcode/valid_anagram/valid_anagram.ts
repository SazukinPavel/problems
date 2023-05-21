// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



function isAnagram(s: string, t: string): boolean {
    if(t.length!==s.length){
        return false
    }
    
    const sLetters=new Map<string,number>()
    const tLetters=new Map<string,number>()
    
    for (let i = 0; i < s.length; i++) {
        sLetters.set(s[i],(sLetters.get(s[i])|| 0)+1)
        tLetters.set(t[i],(tLetters.get(t[i])|| 0)+1)
    }

    for (const [key,count] of sLetters.entries()) {
        console.log(key,count,tLetters.get(key));
        
        if(tLetters.get(key)!==count){
            return false
        }
    }
    
    return true
};