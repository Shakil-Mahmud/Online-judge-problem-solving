/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let exist = new Map();

    for(let i=0 ; i<nums.length ; i++){
        if(exist.has(nums[i]))
            return true;
        else
            exist.set(nums[i],1);
    }
    return false;
};