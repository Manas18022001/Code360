#include<bits/stdc++.h>

bool isCycle(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
             unordered_map<int, bool> &DFSvisited, int node)
{
    visited[node] = 1;
    DFSvisited[node] = 1;

    for(auto i:adjList[node]){
      if(!visited[i]){
        bool ans = isCycle(adjList, visited, DFSvisited, i);
        if(ans){
          return true;
        }
      }

      else if(DFSvisited[i]){
        return true;
      }
    }

    DFSvisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            // bool ans = isCycle(adjList, visited, i+1);
            bool ans = isCycle(adjList, visited, DFSvisited, i);
            if(ans == 1){
                return 1;
            }
        }
    }
    return 0;
}