#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    vector<int> ind(v, 0);
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

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adj[front]){
            ind[i]--;
            if(ind[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}