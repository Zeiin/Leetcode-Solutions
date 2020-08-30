class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        compliments = []
        for idx, val in enumerate(nums):
            if val in compliments:
                return [compliments.index(val), idx]
            else:
                compliments.append(target-val)