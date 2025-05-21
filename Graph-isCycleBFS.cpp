#include<bits/stdc++.h>

bool isCycle(unordered_map<int, list<int>> &adjList, 
             unordered_map<int, bool> &visited, int node)
{
    unordered_map<int, int> parent;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                parent[i] = frontNode;
            }

            else if(visited[i]==true && i != parent[frontNode]){
                return true;
            }
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycle(adjList, visited, i);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
