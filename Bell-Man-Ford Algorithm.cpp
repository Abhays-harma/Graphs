class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> result(V,1e8);
        result[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto &temp:edges)
            {
                int u=temp[0];
                int v=temp[1];
                int d=temp[2];
                if(result[u]!=1e8 && result[u]+d<result[v])
                {
                    result[v]=result[u]+d;
                }
            }
        }
        for(auto &temp:edges)
        {
            int u=temp[0];
            int v=temp[1];
            int d=temp[2];
            if(result[u]!=1e8 && result[u]+d<result[v])
            {
                return {-1};
            }
        }
        return result;
    }
};
