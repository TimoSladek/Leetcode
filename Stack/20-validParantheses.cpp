class Solution {
public:
    bool isValid(string s) {
        stack<char> ms;
        for (int i = 0;i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                ms.push(s[i]);
            } else {
                if (ms.empty()) return false;
                if (s[i] == ')') {
                    if (ms.top() != '(') return false;
                } else if (s[i] == ']') {
                    if (ms.top() != '[') return false;
                } else {
                    if (ms.top() != '{') return false;
                }
                ms.pop();
            }
        }
        if (ms.empty()) return true;
        return false;
    }
};
