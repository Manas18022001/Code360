#include <bits/stdc++.h>
#include <unordered_map>

void prepAdjList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
         vector<vector<int>> &ans, int node, vector<int> &v)
{

    visited[node] = 1;
    v.push_back(node);
    
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, ans, i, v);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    prepAdjList(adjList, edges);

    for(int i=0; i<V; i++){
        
        if(!visited[i]){
            vector<int> v;
            dfs(adjList, visited, ans, i, v);
            ans.push_back(v);
        }
    }

    return ans;
}