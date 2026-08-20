class Solution {
    // USING DISJOINT SET
public:
    vector<int> parent;

    // Find parent
    int findParent(int node) {

        if(parent[node] == node) return node;
        return findParent(parent[node]);
    
    }

    // Union
    bool Union(int u, int v) {
    
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv) {
            parent[pv] = pu;
            return true;
        }
        return false;
    }
        
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size(); // number of edges
        parent.resize(n + 1); // +1 because nodes are usually 1-indexed in these problems

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto& edge : edges) {

            if(Union(edge[0], edge[1]) == false) return edge;
            

        }

        return {};

    }
};