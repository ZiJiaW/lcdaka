class Solution {
public:
    string countOfAtoms(string f) {
        list<pair<string, int>> s;
        int i = 0;
        string tmp, count;
        while (i < f.size()) {
            if (isupper(f[i])) {
                tmp += f[i++];
                while (islower(f[i])) {
                    tmp += f[i++];
                }
                if (i == f.size() || !isdigit(f[i])) {
                    s.push_back({tmp, 1});
                    tmp.clear();
                }
            } else if (isdigit(f[i])) {
                while (isdigit(f[i])) {
                    count += f[i++];
                }
                s.push_back({tmp, stoi(count)});
                tmp.clear();
                count.clear();
            } else if (f[i] == '(') {
                s.push_back({"#", 1});
                i++;
            } else {
                i++;
                while (isdigit(f[i])) {
                    count += f[i++];
                }
                int t = stoi(count);
                count.clear();
                auto p = --s.end();
                while (p->first != "#") {
                    p->second *= t;
                    p--;
                }
                s.erase(p);
            }
        }
        map<string, int> m;
        for (auto &&p : s) {
            m[p.first] += p.second;
        }
        string res;
        for (auto& p : m) {
            res += p.first;
            if (p.second > 1)
                res += to_string(p.second);
        }
        return res;
    }
};