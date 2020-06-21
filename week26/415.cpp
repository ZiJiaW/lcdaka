class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        auto i = rbegin(num1), j = rbegin(num2);
        int carry = 0;
        while (i != rend(num1) || j != rend(num2) || carry > 0) {
            int sum = carry + (i != rend(num1) ? *i++ : '0') - '0'
                            + (j != rend(num2) ? *j++ : '0') - '0';
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum + '0');
        }
        reverse(begin(res), end(res));
        return res;
    }
};