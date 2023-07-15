function reverseWords(s: string): string {
    if(!s.length){
        return s 
    }
    return s.split(' ').map((w)=>reverseWord(w)).join(' ')
};

function reverseWord(w:string){
    let i=0,j=w.length-1;
    let result=new Array(w.length)
    while(i<=j){
        result[i]=w[j]
        result[j]=w[i]
        i++;
        j--
    }

    return result.join('')
}
