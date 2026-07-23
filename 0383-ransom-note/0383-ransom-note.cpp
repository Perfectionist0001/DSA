class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size();
        int n = magazine.size();
        for(int i = 0; i < m; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(ransomNote[i] == magazine[j]){
                    found = true;
                    magazine[j] = '*';
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};