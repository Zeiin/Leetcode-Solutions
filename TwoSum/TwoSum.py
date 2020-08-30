#Beats 98.3% of Python3 solution for Memory Usage  
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        compliments = []
        for idx, val in enumerate(nums):
            if val in compliments:
                return [compliments.index(val), idx]
            else:
                compliments.append(target-val)
                
#Average solution, nothing really special, but 10x faster than the memory-efficiency solution above.                
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        compliments = dict()
        for idx, val in enumerate(nums):
            if compliments.get(val, None) != None:
                return [compliments.get(val), idx]
            else:
                compliments[target-val] = idx