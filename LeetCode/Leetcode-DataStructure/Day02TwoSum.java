class Solution {
    public int[] twoSum(int[] nums, int target) {
     		HashMap<Integer, Integer> prev = new HashMap<Integer, Integer>();
		int ans[] = new int[2];
		for(int i=0 ; i<nums.length ; i++) {
			if( prev.containsKey(target-nums[i])) { 
				ans[0] = prev.get(target-nums[i]);
				ans[1] = i;
				break;
			}
			else {
				prev.put(nums[i], i);				
			}
		}
		return ans;   
    }
}