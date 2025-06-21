class Solution {
    private:
    vector<int> parent;
    vector<int> rank;
    int comps = 0;
public:

    int findFn(int n)
    {
        if(parent[n] == n)
        {
            return n;
        }

        return findFn(parent[n]);
    }

    bool unionFn(int u, int v)
    {
        int uPar = findFn(u);
        int vPar = findFn(v);

        if(uPar == vPar)
        {
            return false;
        }

        if(rank[uPar] >= rank[vPar])
        {
            parent[vPar] = uPar;
            rank[uPar] += rank[vPar];
        }
        else
        {
            parent[uPar] = vPar;
            rank[vPar] += rank[uPar];
        }
        --comps;
        return true;
    }
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        parent.resize(n);
        rank.resize(n, 1);
        comps = n;

        for(int inx = 0; inx < n; ++inx)
        {
            parent[inx] = inx;
        }

        for(auto edge : edges)
        {
            if(!unionFn(edge[0], edge[1]))
            {
                return false;
            }
            // for(auto par : parent)
            // {
            //     cout << par << "\t";
            // }
            // cout << endl;
        }

        cout << "no cycle detected" << endl;
        // unordered_set<int> unqParents(parent.begin(), parent.end());

        if(comps == 1)
        {
            return true;
        }

        return false;
        
    }
};
