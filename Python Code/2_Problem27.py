# 27. Remove Element

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        int_max = 51
        k = 0

        # si encontramos un val, lo cambiamos por uno mayor que todos O(N) 
        for i in range(len(nums)):          
            if nums[i] == val:
                nums[i] = int_max
                k += 1 # contamos cuantos vals encontramos

        # al ordenar mandamos los ex-val hasta atrás O(NlogN) 
        nums.sort()

        return len(nums) - k

        
