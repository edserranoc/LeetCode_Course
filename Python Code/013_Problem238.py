from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [1] * n
        temp = 1
        
        for i in range(1, n):
            ans[i] = ans[i - 1] * nums[i - 1]
        for i in range(n - 2, -1, -1):
            temp *= nums[i + 1] 
            ans[i] = ans[i] * temp
            
        return ans

if __name__ == "__main__":
    obj = Solution()
    print(obj.productExceptSelf([1, 2, 3, 4])) # [24, 12, 8, 6]
    print(obj.productExceptSelf([1, 2, 3, 4, 5])) # [120, 60, 40, 30, 24]
   
   
"""
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int n = nums.size();
        vector<int> ans(n,1);

        for (int i = 1; i < n; i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        for (int i = n-2; i >= 0; i--){
            temp = temp*nums[i+1];
            ans[i]=temp*ans[i];
        }
        return ans;

    }
};"""