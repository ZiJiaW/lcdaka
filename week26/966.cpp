class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s;
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        vector<string> res;
        auto toLow = [](string& a) {
            for (auto&c : a) c = tolower(c);
        };
        auto trans = [](string& a) {
            for (auto& c : a) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '#';
            }
        };
        for (int i = 0; i < wordlist.size(); i++) {
            auto t(wordlist[i]);
            s.insert(t);
            toLow(t);
            if (m1.find(t) == m1.end()) m1[t] = i;
            trans(t);
            if (m2.find(t) == m2.end()) m2[t] = i;
        }
        for (auto &str : queries) {
            if (s.find(str) != s.end()) res.push_back(str);
            else {
                toLow(str);
                if (m1.find(str) != m1.end()) res.push_back(wordlist[m1[str]]);
                else {
                    trans(str);
                    if (m2.find(str) != m2.end()) res.push_back(wordlist[m2[str]]);
                    else res.push_back("");
                }
            }
        }
        return res;
    }
};