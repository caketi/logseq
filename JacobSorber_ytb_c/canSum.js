const { methodOf } = require("lodash");
const { trace } = require("node:console");
const { number } = require("yargs");

const canSum = (targetSum, numbers, memo={})=>{

    if (targetSum in memo) return memo[targetSum];
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (let num of nubmers){
        const reaminder = targetSum - num; 
        if ( canSum(reaminder, numbers, memo) === true){
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}


const howSum = (targetSum, numbers, memo={}) =>{
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0 ) return []
    if (targetSum < 0) return null

    for ( let num of numbers){
        const remainder  = targetSum - num;
        const remainderresult = howSum(remainder, numbers, memo);
        if (remainderresult != null){
          memo[targetSum] = [...remainderresult, num];
        return memo[targetSum]
        }
    }
    memo[targetSum] = null
    return null;
}

const bestSum = (targetSum, numbers, memo={})=>{
    if(targetSum in memo) return memo[targetSum]
    if (targetSum === 0 ) return [];
    if (targetSum < 0) return null;

    let shortestCombination = null;

    for (let num of numbers){
        const remainder = targetSum - num;
        const remainderCombination = bestSum(targetSum, num, memo);
        if (remainderCombination !== null){
         const combination = [...remainderCombination, num]
            if (shortestCombination === null || combination.length < shortestCombination.length){
                shortestCombination = combination;
            }
        }
    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
}
