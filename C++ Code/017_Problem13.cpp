// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;

        for(int i = s.size()-1; i >= 0 ; i--){
            switch(s[i]){
                case 'I':
                    num++;
                    break;
                
                case 'V':
                    num += 5;
                    if(i > 0 && s[i-1] == 'I'){
                        num--;
                        i--;
                    }
                    break;
                case 'X':
                    num += 10;
                    if(i > 0 && s[i-1] == 'I'){
                        num--;
                        i--;
                    }
                    break;
                case 'L':
                    num += 50;
                    if(i > 0 && s[i-1] == 'X'){
                        num -= 10;
                        i--;
                    }
                    break;
                case 'C':
                    num += 100;
                    if(i > 0 && s[i-1] == 'X'){
                        num -= 10;
                        i--;
                    }
                    break;
                case 'D':
                    num += 500;
                    if(i > 0 && s[i-1] == 'C'){
                        num -= 100;
                        i--;
                    }
                    break;
                case 'M':
                    num += 1000;
                    if(i > 0 && s[i-1] == 'C'){
                        num -= 100;
                        i--;
                    }
                    break;
                
            }
        }

        return num;
    }
};
