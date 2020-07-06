class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<tuple<int, int, int>> s;// id, start time, gap
        int gap = 0;
        for (auto log : logs) {
            int i = 0;
            string id, time;
            bool start = false;
            while (log[i] != ':') id += log[i++];
            start = log[i + 1] == 's';
            while (log[++i] != ':');
            i++;
            while (i < log.size()) time += log[i++];
            int tid = stoi(id);
            int ttime = stoi(time);
            if (!start && !s.empty() && get<0>(s.top()) == tid) {
                int gap = get<2>(s.top());
                res[tid] += ttime + 1 - get<1>(s.top()) - gap;
                gap = ttime + 1 - get<1>(s.top());
                s.pop();
                if (!s.empty()) get<2>(s.top()) += gap;
            } else {
                s.push({tid, ttime, 0});
            }
        }
        return res;
    }
};