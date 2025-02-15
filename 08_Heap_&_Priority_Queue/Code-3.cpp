// K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/description/

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for (auto& p : points)
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> ans;
        while (k--){
            vector<int> el = pq.top();
            pq.pop();
            ans.push_back({el[1], el[2]});
        }
        return ans;
    }