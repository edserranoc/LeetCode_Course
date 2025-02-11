// 88. Merge Sorted Array

#include <algorithm>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int it2 = 0;
        // remplazamos los 0's por los valores de nums2 en O(N)
        for(int it2 = 0; it2 < n; it2++){
            nums1[m + it2] = nums2[it2];
        }
        // ordenamos en O(N + M log(N + M))
        sort(nums1.begin(), nums1.end());
    }
};
