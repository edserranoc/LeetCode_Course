# include <iostream>
# include <vector>

using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {

            int n = citations.size();

            if (n==1){
                if (citations[0]>0)return 1;
                else{return 0;}
            }

            int max_h = 1000;
            int min_cit = 0;
            int max_cit = 0;

            vector<int> count (max_h+2, 0);

            for (int i = 0; i < n; i++){
                if (citations[i] <= max_h){
                    count[citations[i]]++;
                    if(citations[i] > max_cit) max_cit = citations[i];
                    if(citations[i] < min_cit) min_cit = citations[i];
                }
            }
            int h = 0;
            for (int i = max_cit; i >= min_cit; i--){

                count[i] += count[i+1];
                if (count[i] >= i){
                    h = i;
                    break;
                }
            }

            return h;

        }
    };


int main() {
    Solution sol;
    vector<int> nums = {0,1};
    cout << sol.hIndex(nums) << endl;
    return 0;

}
