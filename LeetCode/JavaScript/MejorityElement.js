/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    
    let exist = {};
    let n=nums.length;
    if(n===1)
        return nums[0];

    for(let i=0 ; i<n ; i++){
        if(typeof exist[nums[i]] === 'undefined' ){
            exist[nums[i]] = 1;
        }
        else{
            exist[nums[i]]++;
            if(exist[nums[i]] > n/2 )
                return nums[i];
        }
    }

};