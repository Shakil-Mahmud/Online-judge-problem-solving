/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
     
    let obj = new Object();

    for(let i=0 ; i<nums.length ; i++){
        if( typeof (obj[nums[i]] ) !== 'undefined'  ){
            return [ obj[nums[i]], i ];
        }
        else{
            obj[target-nums[i]] = i;
        }
    }
};