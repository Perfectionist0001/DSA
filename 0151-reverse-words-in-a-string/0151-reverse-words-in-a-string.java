class Solution {
    public String reverseWords(String s) {
        StringBuilder temp = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        s = s.trim();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ' || i == 0) {
                if (i == 0 && s.charAt(i) != ' ') {
                    temp.append(s.charAt(i));
                }
                temp.reverse();
                if (temp.length() > 0) {
                    ans.append(temp);
                    ans.append(" ");
                }
                temp.setLength(0);
            } else {
                temp.append(s.charAt(i));
            }
        }
        return ans.toString().trim();
    }
}

