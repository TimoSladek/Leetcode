class Solution {
public boolean isPalindrome(String s) {
    String newS = s.toLowerCase().replaceAll("[^a-z0-9]", "");
    int l = 0, r = newS.length()-1;
    while (l <= r) {
        if (newS.charAt(l) != newS.charAt(r)) return false;
        l++;
        r--;
    }
    return true;
}
}