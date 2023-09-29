#include<bits/stdc++.h>
using namespace std;
bool  solve(int src, unordered_map<int,bool>&visited, unordered_map<int,list<int>>&adj){
      
      unordered_map<int,int>parent;
      parent[src]=-1;
      visited[src]=1;
      
      queue<int>q;
      
      q.push(src);
      
      while(!q.empty()){
          int front = q.front();
          q.pop();
          
          for(auto neighbour:adj[front]){
              if(visited[neighbour]==true && parent[front] != neighbour){
                  return true;
              }
              else if(!visited[neighbour]){
                  q.push(neighbour);
                  visited[neighbour]=1;
                  parent[neighbour]=front;
              }
          }
          
      }
      return false;
  }

bool isCycle(int V, unordered_map<int,list<int>>&adj) {
        
        unordered_map<int,bool>visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = solve(i,visited,adj);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
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
    
    cout<<isCycle(n,adj);
}