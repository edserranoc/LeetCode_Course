from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        total = 0
        n = len(ratings)
        candies = [1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                candies[i]=candies[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]:
                candies[i]=candies[i+1]+1
            total+=candies[i]
        return total+candies[n-1]
    
if __name__ == "__main__":
    s = Solution()
    print(s.candy([1,0,2]))  # Output: 5
    print(s.candy([1,2,2]))  # Output: 4