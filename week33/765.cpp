class Solution {
    class UF {
    private:
        vector<int> p;
        vector<int> r;
    public:
        int count;
        UF(int n): count(n), r(n, 0), p(n, -1) {}
        
        int find(int x) {
            if (p[x] == -1) return x;
            int t = find(p[x]);
            return p[x] = t;
        }
        
        void un(int x, int y) {
            int p1 = find(x);
            int p2 = find(y);
            if (p1 == p2) return;
            count--;
            if (r[p1] == r[p2]) {
                p[p1] = p2;
                r[p2]++;
            } else if (r[p1] > r[p2]) {
                p[p2] = p1;
            } else p[p1] = p2;
        }
        
    };
public:
    int minSwapsCouples(vector<int>& row) {
        UF uf(row.size()/2);
        for (int i = 0; i < row.size()/2; i++) {
            uf.un(row[2*i]/2, row[2*i+1]/2);
        }
        return row.size()/2 - uf.count;
    }
};