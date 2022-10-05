class Solution {
public:
    void dfs(vector<vector<int>> &graph,int src,vector<bool> &vis){
        vis[src]=true;
        for(int u:graph[src]){
            if(vis[u]==false){
                dfs(graph,u,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size();
        vector<vector<int>> graph(v);
        for(int i=0;i<v;i++){
            for(int v:rooms[i]){
                    graph[i].push_back(v);
            }
        }
        vector<bool> vis(v,false);
        int count=0;
        for(int i=0;i<v;i++){
            if(vis[i]==false){
                count++;
                dfs(graph,i,vis);
            }
        }
        return count==1?true:false;
    }
};