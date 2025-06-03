// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int water = 0;
            bool flag = false;
            stack<pair<int, int> > st;
            cout << endl;

            for (int index = 0; index < height.size()-1; index++) {
                
            
                if (!flag && height[index]>height[index+1]) {
                    st.push({index,height[index]});
                    flag = true;
                } else if (flag && height[index]>height[index+1]){
                    st.push({index,height[index]});

                } else if (flag && height[index]<height[index+1]){

                    if(height[index+1] < st.top().second){
                        water += (height[index+1]-height[index])*(index - st.top().first);
                    }else if (height[index+1] == st.top().second){
                        water += (st.top().second - height[index])*(index-st.top().first);
                        st.pop();
                        if (st.empty()){
                            flag = false;
                        }
                    }else if (height[index+1] > st.top().second){
                        water += (st.top().second - height[index])*(index-st.top().first );
                        int pos = st.top().first, value = st.top().second;
                        int second_flag = true;
                        st.pop();
                        while (st.size() > 0) {
                            if (!st.empty() && height[index+1]> st.top().second){
                                water += (st.top().second - value)*(index - st.top().first);
                                pos = st.top().first;
                                value = st.top().second;
                                st.pop();
                                if (st.empty()){
                                    flag = false;
                                    break;
                                }
                            } else if (!st.empty()&& height[index+1] == st.top().second) {
                                water += (st.top().second - value)*(index-st.top().first);
                                st.pop();
                                if (st.empty()){
                                    flag = false;
                                }
                                break;
                            } else {
                                water += (height[index+1]-value)*(index - st.top().first);
                                break;
                            }
                            
                        }

                        if (!st.size()) {
                            flag = false;
                        }
                        
                    }
                }
                //cout << "index: " << index << " height[index]: " << height[index] << " water: " << water << endl;
            }

            return water;
    };
};

int main() {
    Solution sol;
    vector<int> height = {8,2,8,9,0,1,7,7,9};
    cout << "Trapped rainwater: " << sol.trap(height) << endl;
    return 0;
}

//g++ -o run 016_Problem42.cpp 