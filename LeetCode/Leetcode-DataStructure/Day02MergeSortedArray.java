class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int mTail = m-1, nTail = n-1;
        int tail = m+n-1;

        while(mTail >=0 && nTail>=0){
            nums1[tail--] = nums1[mTail] >= nums2[nTail] ? nums1[mTail--] : nums2[nTail--];
        }

        while (nTail>=0){
            nums1[tail--] = nums2[nTail--];
        }
    }
}