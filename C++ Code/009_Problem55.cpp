// 55. Jump Game
// https://leetcode.com/problems/jump-game/submissions/1574940254/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
    
            int maxJump = nums[0];
            int _bool = false;
    
            if(nums.size()==1) return true;
    
            for(int i = 1; i< nums.size(); i++){
                if(i>maxJump){
                    break;
                }
    
                if(maxJump < i + nums[i]) maxJump = i +  nums[i];
    
                if(maxJump >= nums.size()-1) _bool = true;
            }
    
            return _bool;
        }
    };


/*
# include <iostream>
# include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            vector<bool> an(n, false);
            an[n-1]=true;
            for(int i=n-2;i>=0;i--){
                for(int j=1;j<=nums[i];j++){
                    if(an[i+j]){
                        an[i]=true;
                        break;
                    }
                }
            }
            return an[0];
        }

        // Alternative solution without using extra space 
        bool canJump2(vector<int>& nums) {
            int maxInd = 0;
            for(int i=0; i<nums.size(); i++){
                if(i>maxInd){
                    return false;
                }
                maxInd = max(maxInd,i+nums[i]);
            }
            return true;
        }
    };
>>>>>>> 417454a73af6fddea0bef0ccb2297a004b36e834
*/