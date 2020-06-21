class Solution {
    struct node {
        vector<node*> kids;
        bool isFolder;
        node(): isFolder(false), kids(27, nullptr) {}
        ~node() { for (auto t : kids) delete t; }
        void calc(vector<string>& r, string t, bool found) {
            if (isFolder) {
                r.push_back(t);
                found = true;
            }
            for (int i = 0; i < 26; i++) {
                if (kids[i]) kids[i]->calc(r, t+char('a'+i), found);
            }
            if (kids[26] && !found) kids[26]->calc(r, t+'/', found);
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        node* root = new node();
        for (auto &s : folder) {
            node* cur = root;
            for (auto c : s) {
                int id = c == '/' ? 26 : c - 'a';
                if (!cur->kids[id]) cur->kids[id] = new node();
                cur = cur->kids[id];
            }
            cur->isFolder = true;
        }
        vector<string> res;
        root->calc(res, "", false);
        delete root;
        return res;
    }
};