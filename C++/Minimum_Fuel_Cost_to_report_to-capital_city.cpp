// 2477. Minimum Fuel Cost to Report to the Capital
// Date: 12 Feb, 2023

class Solution {
public:
    long long totalFuel;

    long long dfs(int node,int parent,vector<vector<int>> &adj, int &seats) {

        int totalPerson = 1;

        for(auto child : adj[node]) {
            if(child != parent)
                totalPerson += dfs(child,node,adj,seats);
        }

        if(node!=0)
            totalFuel += ceil(double(totalPerson) / seats);

        return totalPerson;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> adj(n);

        for(auto r:roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        totalFuel = 0;
        dfs(0,-1,adj,seats);

        return totalFuel;
    }
};