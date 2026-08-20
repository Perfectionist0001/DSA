class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int result = 0;
        unordered_map<char,int> mp;
        for(int high = 0; high < n; high++) {
            mp[s[high]]++;
            while(mp.size() < high - low + 1) {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                    mp.erase(s[low]);
                low++;
            }
            result = max(result, high - low + 1);
        }
        return result;
    }
};