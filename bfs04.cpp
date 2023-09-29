#include<bits/stdc++.h>
using namespace std;
// sc = o(n)
//tc = o(n)+o(2e)
void bfs(int v,unordered_map<int,list<int>>&adj){
    vector<int>ans;
    unordered_map<int,bool>visited;
    queue<int>q;
    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }

    for(auto i: ans){
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
    
    for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
    }

    bfs(1,adj);
    
}