class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        list<int> l;
        for (int i = 0; i < deck.size(); i++) l.push_back(i);
        vector<int> res(deck.size(), 0);
        sort(begin(deck), end(deck));
        int i = 0;
        while (!l.empty()) {
            res[l.front()] = deck[i++];
            l.pop_front();
            l.push_back(l.front());
            l.pop_front();
        }
        return res;
    }
};