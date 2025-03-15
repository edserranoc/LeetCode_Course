// 55. Jump Game
// https://leetcode.com/problems/jump-game/submissions/1574940254/?envType=study-plan-v2&envId=top-interview-150

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