# Majority Element

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = 0
        numb = 0

        for number in nums:
            if counts ==0:
                numb = number
            
            if number ==numb:
                counts+=1
            else:
                counts-=1
        
        return numb 