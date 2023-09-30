#include<bits/stdc++.h>
using namespace std;
// sc = o(n)
//tc = o(n)+o(2e)
void bfs(int v,unordered_map<int,list<int>>&adj){
    int dis[v];
    for(int i=0;i<v;i++)dis[i]=1e9;

    dis[0]=0;
    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(dis[front]+1 <dis[i]){
                dis[i]=dis[front]+1;
                q.push(i);
            }
        }
    }
    for(auto i:dis){
        cout<<i<<" ";
    }
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
    

    bfs(n,adj);
    
}