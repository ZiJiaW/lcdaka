class Solution {
    vector<string> parse(string& s, int& i) {
        vector<string> res;
        vector<string> tmp;
        while (true) {
            tmp.clear();
            while (i < s.size() && s[i] != ',' && s[i] != '}') {
                if (s[i] == '{') {
                    i++;
                    auto t = parse(s, i);
                    if (tmp.empty()) tmp = std::move(t);
                    else {
                        vector<string> tmp_;
                        for (auto &s1 : tmp) {
                            for (auto &s2 : t) {
                                tmp_.push_back(s1+s2);
                            }
                        }
                        tmp = std::move(tmp_);
                    }
                } else {
                    string t;
                    while (s[i] >= 'a' && s[i] <= 'z') t += s[i++];
                    if (tmp.empty()) tmp.push_back(t);
                    else {
                        vector<string> tmp_;
                        for (auto &s : tmp) tmp_.push_back(s+t);
                        tmp = std::move(tmp_);
                    }
                }
            }
            copy(tmp.begin(), tmp.end(), back_inserter(res));
            if (i == s.size() || s[i] == '}') break;
            i++;
        }
        i++;
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        return parse(expression, i);
    }
};