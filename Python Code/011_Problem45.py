from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        N = len(nums)
        if (N==1):
            return 0
        if (N==2):
            return 1
        
        steps = N*[0]
        steps[0]=nums[0]
        
        if(steps[0]>=N-1):
            return 1
        
        k=1
        i=1
        
        while(i<=N-2):
            if(i<=steps[k-1]):
                if(max(steps[k],steps[k-1])<nums[i]+i):
                    steps[k]= nums[i]+i
                i+=1
            else:
                k+=1
                
            if(steps[k]>=N-1):
                return k+1
            
        return k
    
    
### C++ code
'''
# include <iostream>
# include <vector>

using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {

            int n = nums.size();
            if (n == 1 || n == 2) return n-1;

            vector<int> steps(n, 0);
            steps[0] = nums[0];

            if (steps[0] >= n-1) return 1;

            int i = 1;
            int k = 1;

            while (i < n-1){
                if(i<=steps[k-1]){
                    if(max(steps[k], steps[k-1])< nums[i]+i){
                        steps[k] = nums[i]+i;
                    }
                    i++;                   

                } else {
                    k++;
                }

                if (steps[k] >= n-1) return k+1;
            }
         return k;   
        }
    };

    
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.jump(nums) << endl;
    return 0;

}
'''