# Remove Duplicates from Sorted Array

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        index = 0
        non_duplicated = 1

        for i in range(1,n):
            if nums[index]!=nums[i]:
                index += 1
                nums[index]=nums[i]
                non_duplicated += 1

        return non_duplicated