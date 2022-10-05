#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &graph,int src,vector<int> &vect,vector<vector<int>> &ans){
        vect.push_back(src);
        if(src==graph.size()-1){
            ans.push_back(vect);
        }
        for(int u:graph[src]){
            dfs(graph, u, vect,ans);
        }
        vect.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        int v = graph.size();
        int src = 0;
        int dst = v - 1;
        vector<int> vect;
        dfs(graph, src,vect,ans);
        return ans;
    }
};
int main(){
    int v;
    cin >> v;
    vector<vector<int>> graph(v);
    graph[0].push_back(4);
    graph[0].push_back(3);
    graph[0].push_back(1);
    graph[1].push_back(3);
    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[2].push_back(3);
    graph[3].push_back(4);
    Solution s;
    s.allPathsSourceTarget(graph);
}