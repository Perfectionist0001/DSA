class Solution {
public:
    bool checkString(string s) {
        bool foundB = false;
        for (char letter : s) {
            if (letter == 'b') {
                foundB = true;
            }
            if (foundB && letter == 'a') {
                return false;
            }
        }
        return true;
    }
};