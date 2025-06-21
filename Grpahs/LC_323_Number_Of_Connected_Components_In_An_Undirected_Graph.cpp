class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */

    void bfs(int currNode, const vector<vector<int>>& adjList, vector<bool>& visited)
    {
        queue<int> q;
        q.push(currNode);
        visited[currNode] = true;

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(auto nei : adjList[curr])
            {
                if(!visited[nei])
                {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);

        int res = 0;
        for(int inx = 0; inx < n; ++inx)
        {
            if(!visited[inx])
            {
                ++res;
                bfs(inx, adjList, visited);
            }
        }


        return res;
    }
};
