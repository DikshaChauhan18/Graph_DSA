//given a graph -> when we try to color it with any 2 color such that any no neighbour node should have same color;
//linear graph with no cycle is always bipartite
// even cyclemlen = bipartite
//odd = not




#include<bits/stdc++.h>
using namespace std;
//Expected Time Complexity: O(V + E)
//Expected Space Complexity: O(V)
bool isBipartite(unordered_map<int,list<int>>&adj, int v){
    
    int visited[v];
    for(int i=0;i<v;i++)visited[i]=-1;
    

    queue<int>q;
    q.push(0);
    visited[0]=0;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for( auto i: adj[front]){
            if(visited[i]==-1){
                visited[i] = !visited[front];
                q.push(i);
            }
            else if(visited[i]==visited[front]){
                return false;
            }
        }
    }
    return true;

}
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,list<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
  
    isBipartite(adj, n) ? cout << "Yes" : cout << "No";
    
}