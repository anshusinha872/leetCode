// 210. Course Schedule II
//     There are a total of numCourses courses you have to take,
//     labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ ai, bi ] indicates that you must take course bi first if you want to take course ai.

//                                                                                                     For example,
//                                                                                  the pair[0, 1], indicates that to take course 0 you have to first take course 1. Return the ordering of courses you should take to finish all courses.If there are many valid answers, return any of them.If it is impossible to finish all courses, return an empty array.

//                                                                                                                                                                                                                                                                                                                                              Example 1 :

//     Input : numCourses = 2,
//                                                                                  prerequisites = [[ 1, 0 ]] Output : [ 0, 1 ] Explanation : There are a total of 2 courses to take.To take course 1 you should have finished course 0. So the correct course order is[0, 1].Example 2 :

//     Input : numCourses = 4,
//                                                                                  prerequisites = [ [ 1, 0 ], [ 2, 0 ], [ 3, 1 ], [ 3, 2 ] ] Output : [ 0, 2, 1, 3 ] Explanation : There are a total of 4 courses to take.To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is[0, 1, 2, 3].Another correct ordering is[0, 2, 1, 3].Example 3 :

//     Input : numCourses = 1,
//                                                                                  prerequisites = [] Output : [0]

//                                                                                                              Constraints :

//                                                                                                              1 <= numCourses <= 2000 0 <= prerequisites.length <= numCourses * (numCourses - 1)
//                                                                                                                                                                                    prerequisites[i]
//                                                                                                                                                                                        .length ==
//                                                                                                  2 0 <= ai,
//                                                                                  bi < numCourses
//                                                                                              ai !=
//                                                                                      bi
//                                                                                          All the pairs[ai, bi] are distinct.
#include<bits/stdc++.h>
using namespace std;
bool detect_cycle_util(vector<vector<int>> adj,int v,vector<bool> &visited,vector<bool> &recursion){
    visited[v] = true;
    recursion[v] = true;
    for(auto x:adj[v]){
        if(visited[x]==false && detect_cycle_util(adj,x,visited,recursion)==true)
            return true;
        else if(recursion[x]==true)
            return true;
    }
    recursion[v] = false;
    return false;
}
bool detect_cycle(vector<vector<int>> adj, int numCourses){
    vector<bool> visited(numCourses, false);
    vector<bool> recursion(numCourses, false);
    for (int i = 0; i < numCourses;i++){
        if(!visited[i])
            if(detect_cycle_util(adj,i,visited,recursion))
                return true;
    }
    return false;
}
void dfs(vector<vector<int>> adj,int v,vector<bool> &visited,stack<int> &myStack){
    visited[v] = true;
    for(int x:adj[v]){
        if(!visited[x])
            dfs(adj, x, visited, myStack);
    }
    myStack.push(v);
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = prerequisites.size();
    vector<vector<int>> adj(numCourses);
    for (int i = 0; i < n;i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> ans;
    if(detect_cycle(adj,numCourses))
        return ans;
    stack<int> myStack;
    vector<bool> visited(numCourses, false);
    for (int i = 0; i < numCourses;i++){
        if(!visited[i])
            dfs(adj, i, visited, myStack);
    }
    while(!myStack.empty()){
        ans.push_back(myStack.top());
        myStack.pop();
    }
    return ans;
}
int main()
{
    int numCourses = 2000;
    vector<vector<int>> prerequisites{};
    vector<int> vect=findOrder(numCourses, prerequisites);
    for(auto ans:vect)
        cout << ans << " ";
    return 0;
}