// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

// The ith item is said to match the rule if one of the following is true:

// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.



function countMatches(items: string[][], ruleKey: string, ruleValue: string): number {
    let count=0;
    for(let i=0;i<items.length;i++){
        const [type,color,name]=items[i]
        const map={type,color,name}

        if(map[ruleKey]===ruleValue){
            count++
        }
    }
    return count
};