// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.




function average(salary: number[]): number {
    let i = 0;
    let sum = 0;
    let min = salary[0]
    let max = salary[0]
    for (; i < salary.length; i++) {
        sum += salary[i]
        if (salary[i] > max) {
            max = salary[i]
        }

        if (salary[i] < min) {
            min = salary[i]
        }
    }

    return (sum - min - max) / (i - 2)
};