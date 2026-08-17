class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;
        int high = 0;
        int result = 0;
        unordered_map<int,int> mp;
        for(high = 0; high < n; high++) {
            mp[fruits[high]]++;
            while(mp.size() > 2) {
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }
                low++;
            }
            int length = high - low + 1;
            result = max(result, length);
        }
        return result;
    }
};