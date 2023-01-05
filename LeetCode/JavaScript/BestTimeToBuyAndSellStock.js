/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    if(prices.length<=1)
        return 0;

    let profit = 0;
    let min_buy = prices[0];

    for(let i=0 ; i<prices.length ; i++){
        min_buy = Math.min(prices[i], min_buy);
        profit = Math.max(profit, prices[i]-min_buy);
    }

    return profit;
};