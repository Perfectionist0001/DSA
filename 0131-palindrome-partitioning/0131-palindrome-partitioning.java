class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> list = new ArrayList<>();
        helper(0, s, ans, list);
        return ans;
    }
    public void helper(int index, String s, List<List<String>> ans, List<String> list) {
        if (index == s.length()) {
            ans.add(new ArrayList<>(list));
            return;
        }
        String str = "";
        for (int i = index; i < s.length(); i++) {
            str += s.charAt(i);
            if (isPalindrome(str)) {
                list.add(str);
                helper(i + 1, s, ans, list);
                list.remove(list.size() - 1);
            }
        }
    }
    public boolean isPalindrome(String str) {
        int start = 0;
        int end = str.length() - 1;
        while (start < end) {
            if (str.charAt(start) != str.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
}
