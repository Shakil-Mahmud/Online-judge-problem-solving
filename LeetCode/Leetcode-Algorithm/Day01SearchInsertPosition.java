class Solution {
    public int searchInsert(int[] nums, int target) {
        int first = 0, last = nums.length-1;
        int mid = first+(last-first)/2;

        while(first<=last){
            mid = first+(last-first)/2;
            if(target>nums[mid]){
                first = mid+1;
            }
            else if(target<nums[mid]){
                last = mid-1;
            }
            else{
                return mid;
            }
        }
        if(nums[mid]<target)
            mid++;
        return mid;
    }
}