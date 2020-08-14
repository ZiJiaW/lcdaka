class Solution {
    unordered_map<int, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        auto t = new Node(node->val);
        m[node->val] = t;
        for (Node* j : node->neighbors) {
            if (m.find(j->val) == m.end()) t->neighbors.push_back(cloneGraph(j));
            else t->neighbors.push_back(m[j->val]);
        }
        return t;
    }
};