class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
     bool dfs(int currNode, const vector<vector<int>>& adjList, int prevNode, unordered_set<int>& visited)
     {
         if( visited.find(currNode) != visited.end() )
         {
             return false;
         }

         visited.insert(currNode);
         for(auto nei : adjList[currNode])
         {
             if(nei == prevNode)
             {
                 continue;
             }
             if( !dfs(nei, adjList, currNode, visited) )
             {
                 return false;
             }
         }

         return true;
     }

    bool validTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for(int inx = 0; inx < edges.size(); ++inx)
        {
            adjList[edges[inx][0]].push_back(edges[inx][1]);
            adjList[edges[inx][1]].push_back(edges[inx][0]);
        }
        unordered_set<int> visited;

        if(dfs(0, adjList, -1, visited) && visited.size() == n)
        {
            return true;
        }

        return false;
    }
};
