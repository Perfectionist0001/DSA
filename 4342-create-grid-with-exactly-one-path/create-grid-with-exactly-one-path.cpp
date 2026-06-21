class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> griid(m,string(n,'#'));
        for(int i = 0; i < n; i++){
            griid[0][i] = '.';
        }
        for(int j = 0; j < m; j++){
            griid[j][n - 1] = '.';
        }
        return griid;
    }
};