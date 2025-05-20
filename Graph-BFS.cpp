#include<list>
#include<queue>
#include<unordered_map>

void bfs(unordered_map <int, list<int>> &AdjList, int node,
         unordered_map <int, bool> &visited, vector<int> &ans){
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i:AdjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}

void prepareAdjList(unordered_map <int, list<int>> &AdjList, vector<vector<int>> &adj, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int u = i;
            int v = adj[i][j];
            AdjList[u].push_back(v);
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    unordered_map <int, bool> visited;
    unordered_map <int, list<int>> AdjList;
    //prepare adjacency list
    prepareAdjList(AdjList, adj, n);

    //BFS
    // for(int i=0; i<n; i++){
    //     bfs(AdjList, i, visited, ans);
    // }
    bfs(AdjList, 0, visited, ans);
    return ans;
}