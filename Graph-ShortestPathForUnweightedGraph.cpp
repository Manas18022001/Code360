#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int w = edges[i].second - 1;
        adj[u].push_back(w);
    }

    vector<int> ind(n, 0);
    queue<int> q;

    for(auto i:adj){
        for(auto j:i.second){
            ind[j]++;
        }
    }

    for(int i=0; i<ind.size(); i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    int count = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        count++;
        ans.push_back(front);

        for(auto i:adj[front]){
            ind[i]--;
            if(ind[i] == 0){
                q.push(i);
            }
        }
    }

    if(count == n){
      return false;
    }

    else{
      return true;
    }
    
}