class Solution {
    public int[] sortedSquares(int[] nums) {
        int arrayLength = nums.length;
        int leftIterator=arrayLength-1, i, j=0;
        int num1=0, num2=0;
        int squareArray[] = new int[arrayLength];

        for(i=0 ; i<arrayLength ; i++){
            if(nums[i]>=0){
                leftIterator = i-1;
                break;
            }
        }

        while(j<arrayLength){
            if(leftIterator>=0 && i<arrayLength){
                num1 = nums[leftIterator];
                num2 = nums[i];
                if( num1*num1 <= num2*num2 ){
                    squareArray[j++] = num1*num1;
                    leftIterator--;
                }
                else{
                    squareArray[j++] = num2*num2;
                    i++;
                }
            }
            else if(leftIterator>=0){
                squareArray[j++] = nums[leftIterator]*nums[leftIterator];
                leftIterator--;
            }
            else if(i<arrayLength){
                squareArray[j++] = nums[i]*nums[i];
                i++;
            }
        }

        return squareArray;
    }
}