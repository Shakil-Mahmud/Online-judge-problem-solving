/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int first = 1, last = n,  mid = first+(last-first)/2;

        while(first<last){

            if(isBadVersion(mid)){
                last = mid;
            }
            else{
                first = mid+1;
            }
            mid = first+(last-first)/2;
        }

        return mid;
    }
}