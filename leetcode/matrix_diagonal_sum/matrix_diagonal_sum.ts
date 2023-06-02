// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

function diagonalSum(mat: number[][]): number {
    let jStart=0,i=0,n=mat[0].length-1,sum=0;
    while(i<=Math.floor(n/2)){
        sum+=mat[i][jStart]
        sum+=mat[i][n-jStart]
        sum+=mat[n-i][jStart]
        sum+=mat[n-i][n-jStart]
        
        jStart++;
        i++;
    }
    if(mat.length%2!=0){
        sum-=3*mat[i-1][jStart-1]        
    }

    return sum
};