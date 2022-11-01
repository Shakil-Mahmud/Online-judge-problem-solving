class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i,value in enumerate(nums):
            if target-value in dic:
                return [dic[target-value],i]
            dic[value] = i