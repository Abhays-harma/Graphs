class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<bool> visited(V,0);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty())
        {
            P p=pq.top();
            pq.pop();
            int node=p.second;
            int wt=p.first;
            if(visited[node]) continue;
            visited[node]=1;
            sum+=wt;
            for(auto &v:adj[node])
            {
                int neighbour_node=v[0];
                int d=v[1];
                if(visited[neighbour_node]==false)
                {
                    pq.push({d,neighbour_node});
                }
            }
        }
        return sum;
    }
};
