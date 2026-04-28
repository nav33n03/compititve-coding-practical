class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for(auto &e:edges)adj[e[0]].push_back(e[1]);
        
        vector<int>ind(V,0);
        for(int i=0;i<V;i++)
        for(int v:adj[i])ind[v]++;
        
        queue<int>q;
        for(int i=0;i<V;i++)
        if(ind[i]==0)q.push(i);
        
        int visited=0;
        while(!q.empty())
        
        {
            int u=q.front();q.pop();
            visited++;
            for(int v:adj[u])
            if(--ind[v]==0)q.push(v);
        }
        
    return visited!=V;}
};


