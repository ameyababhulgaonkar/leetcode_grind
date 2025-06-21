class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */

     void addToQ(int m, int n, int r, int c, int cost, queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& rooms)
     {
         vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
         for(int inx = 0; inx < 4; ++inx)
         {
             auto newRow = r + dirs[inx][0];
             auto newCol = c + dirs[inx][1];
             if( newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && rooms[newRow][newCol] != -1 && rooms[newRow][newCol] == INT_MAX)
             {
                rooms[newRow][newCol] = cost + 1;
                q.push({{newRow, newCol}, cost + 1});
             }
         }
     }

    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<pair<int, int>, int>> q;
        for(int inx = 0; inx < rooms.size(); ++inx)
        {
            for(int iny = 0; iny < n; ++iny)
            {
                if(rooms[inx][iny] == 0)
                {
                    q.push({{inx, iny}, 0});
                }
            }
        }

        while(!q.empty())
        {
            int qSize = q.size();
            while(qSize--)
            {
                auto curr = q.front();
                q.pop();
                int r = curr.first.first;
                int c = curr.first.second;
                addToQ(m, n, r, c, curr.second, q, rooms);
            }
        }
    }
};
