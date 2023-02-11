// Q-1129. Shortest Path with Alternating Colors
// Date: 11 Feb, 2023


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges){

        vector<int> res(n, -1), visited(n, 0);
        vector<vector<pair<int, int>>> vp(n);
        queue<pair<int, int>> q;

        for(auto &it : red_edges) vp[it[0]].push_back({it[1], 1});
        for(auto &it : blue_edges) vp[it[0]].push_back({it[1], 2});

        res[0] = 0;
        q.push({0, 1});
        q.push({0, 2});

        int temp = 0;
        while(!q.empty())
        {
            int len = q.size();
            temp++;
            for(int i=0; i<len; ++i)
            {
                auto val = q.front();
                q.pop();
                int node = val.first;
                int color = val.second;

                if(visited[node] & color) continue;
                visited[node] |= color;
                if(res[node] == -1) res[node] = temp - 1;

                for(auto &it : vp[node])
                {
                    int next_node = it.first;
                    int next_color = it.second;

                    if(next_color == color) continue;
                    q.push({next_node, next_color});
                }
            }
        }
        return res;
    }
};
