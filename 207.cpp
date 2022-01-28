// 207. Course Schedule
//     There are a total of numCourses courses you have to take,
//     labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ ai, bi ] indicates that you must take course bi first if you want to take course ai.

//                                                                                                     For example,
//                                                                                  the pair[0, 1], indicates that to take course 0 you have to first take course 1. Return true if you can finish all courses.Otherwise, return false.

//                                                                                                                                                                                                                               Example 1 :

//     Input : numCourses = 2,
//                                                                                  prerequisites = [[ 1, 0 ]] Output : true Explanation : There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.Example 2 :

//     Input : numCourses = 2,
//                                                                                  prerequisites = [ [ 1, 0 ], [ 0, 1 ] ] Output : false Explanation : There are a total of 2 courses to take.To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
#include<bits/stdc++.h>
using namespace std;
bool cycle_detect_util(int v,vector<vector<int>>&adj,vector<bool>&visited,int numCourses,vector<bool> &recursion){
    visited[v] = true;
    recursion[v] = true;
    for(int x:adj[v]){
        if(visited[x]==false && cycle_detect_util(x,adj,visited,numCourses,recursion)==true)
            return true;
        else if(recursion[x]==true)
            return true;
    }
    recursion[v] = false;
    return false;
}
bool cycle_detect(vector<vector<int>> &adj, int numCourses)
{
    vector<bool> visited(numCourses, false);
    vector<bool> recursion(numCourses, false);
    for (int i = 0; i < numCourses;i++)
        if(!visited[i])
            if(cycle_detect_util(i, adj, visited, numCourses,recursion))
                return true;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    int n = prerequisites.size();
    vector<vector<int>> adj(numCourses);
    for (int i = 0; i < n;i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    if(cycle_detect(adj,numCourses))
        return false;
    return true;
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites{{1,0},{0,1}};
    cout<<canFinish(numCourses, prerequisites);
    return 0;
}