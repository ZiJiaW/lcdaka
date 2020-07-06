class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        stack<int> s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                s.push(i);
            } else {
                int t = s.top();
                s.pop();
                if (s.empty()) {
                    res += S.substr(t+1, i-t-1);
                }
            }
        }
        return res;
    }
};