class Solution {
public:

    int BFS(vector<vector<int>>& grid, int n) {

        // all direction cases
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};


        // visited array and queue
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> que;

        que.push({0, 0});
        visited[0][0] = true;

        int dist = 1;

        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                pair<int, int> node = que.front();
                que.pop();

                int row = node.first;
                int col = node.second;

                if(row == n-1 && col == n-1) {
                    return dist;
                }

                for(int k = 0; k < 8; k++) {

                    int newRow = row + dx[k];
                    int newCol = col + dy[k];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && !visited[newRow][newCol]) {

                        visited[newRow][newCol] = true;
                        que.push({newRow, newCol});
                    }
                }
            }

            dist++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        
        return BFS(grid, n);
    }
};