// 169. Majority Element
// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // if empty array, return
        // if(nums.size() == 0) return;

        // if not empty we sort and count
        sort(nums.begin(), nums.end());
        int ccount = 1;                          //ccount counts the aparitions of the current number
        pair <int, int> major = {nums[0], 1};   // major keeps the majority element and its total appearances

        for(int idx = 1; idx < nums.size(); idx++){
            if(nums[idx] != nums[idx-1]){          // if we change the number
                if(ccount >= major.second){        // and if the last count is grater than the majority appearances
                    major.first = nums[idx-1];     // we change the major
                    major.second = ccount;
                }
                ccount = 1;
            } else{
                ccount++;
            }
        }

        if(ccount >= major.second){         // if the last one we counted, is the major, we return that one
            return nums[nums.size()-1];
        }

        // if the major is not the last element, we return the major
        return major.first;
    }
};
