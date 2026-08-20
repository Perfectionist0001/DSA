class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int result = 0;
        int maxfreq = 0;
        unordered_map<char,int>mp;
        for(high = 0; high < n; high++){
            mp[s[high]]++;
            maxfreq = max(maxfreq,mp[s[high]]);
            while(high - low + 1 - maxfreq > k){
                mp[s[low]]--;
                low++;
            }
            result = max(result,high - low + 1);
        }
        return result;
    }
};
