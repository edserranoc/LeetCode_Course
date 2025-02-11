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