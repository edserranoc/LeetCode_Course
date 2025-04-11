// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int strStr(string haystack, string needle) {
        int right = 0, needle_ptr = 0;

        for(int left = 0; left < haystack.size(); left ++){
            if(haystack[left] == needle[0]){
                right = left;
                while(haystack[right] == needle[needle_ptr] && right < haystack.size()){
                    if(needle_ptr == needle.size()-1) return left;
                    right ++; needle_ptr ++;
                }
                needle_ptr = 0;
            }
        }
        return -1;
    }
};
