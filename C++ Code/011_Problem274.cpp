// 274. H-Index
// https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:

    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end()); // sort citations 
        int n = citations.size();
        // perform binary search
        int L = 0, R = n, k = (R + L) / 2; 
        while (R - L > 1){ 
            // check if k could be the hidx
            if(citations[n-k] >= k) L = k;  // if so, we check for a larger on
            else R = k; // if too large, we search for a smaller one
              
            k = (R + L) / 2; cout << k << endl;
        } // at the end of this loop L or R = to the h idx
        
        if (citations[n - R] >= R ) return R; // consider the case n is the h-index
        return L; 
    }
};
