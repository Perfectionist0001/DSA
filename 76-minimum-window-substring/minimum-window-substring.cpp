class Solution {
public:
    bool function(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 128; i++) {
            if (have[i] < needed[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int>have(128,0);
        vector<int>needed(128,0);
        for(int i = 0; i < n; i++){
            needed[t[i]]++;
        }
        int low = 0;
        int high = 0;
        int result = INT_MAX;
        int start = 0;
        for(high = 0; high < m; high++){
            have[s[high]]++;
            while(function(have,needed)){
                int length = high - low + 1;
                if(length < result){
                    result = length;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(result == INT_MAX){
            return "";
        }
        else{
            return s.substr(start,result);
        }
    }
};