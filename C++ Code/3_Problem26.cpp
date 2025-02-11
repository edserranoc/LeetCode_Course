// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1539697350/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        // https://en.cppreference.com/w/cpp/algorithm/unique
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        return nums.size();
    }
};