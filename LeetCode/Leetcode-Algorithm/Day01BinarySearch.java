class Solution {
    public int search(int[] nums, int target) {
        int first = 0, last = nums.length-1;
        int mid = (first+last/2);

        while(first<=last){
            mid = (first+last)/2;
            if(nums[mid]<target){
                first = mid+1;
            }
            else if(nums[mid]>target){
                last = mid-1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
}