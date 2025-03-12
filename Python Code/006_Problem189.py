# 189. Rotate Array
# https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150

class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k%n                         # we relize rotating n positions equal to do nothing
        if n == 1 or k == 0: return     # if the array contains one element or 
                                        # we rotate 0 positions, we do nothing

        moved = 0                       # will count the elements we have moved
        i = 0                           # will iterate the generators 

        while(moved < n):               # while we havent moved all the elements
            cPos = k
            nPos = (i+k)%n              # we calculate the first point to move the number
            lNum = nums[i]
            while(cPos != i):           # while we havent reach the first element moved
                nNum = nums[nPos]
                nums[nPos] = lNum       # we move the elemen k positions
                cPos = nPos
                nPos = (cPos+k)%n
                lNum = nNum
                moved += 1
            i+=1                        # we change the generator 
    
        return
