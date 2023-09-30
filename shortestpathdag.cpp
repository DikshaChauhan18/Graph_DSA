#include<bits/stdc++.h>
using namespace std;

// tc o(n+m)

void topo(int src,unordered_map<int,list<pair<int,int>>>&adj,unordered_map<int,bool>&visited,stack<int>&s){
    visited[src]=1;
    for(auto i : adj[src]){
        int v=i.first;
        if(!visited[v]){
            topo(v,adj,visited,s);
        }
    }
    s.push(src);
}


int main(){
    int n,m;
    cin>>n>>m;

    unordered_map<int,list<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        //adj[v].push_back(u);

    }

    unordered_map<int,bool>visited;
        stack<int>s;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topo(i,adj,visited,s);
            }
        }
        
        int src=0;
        
        vector<int>distance(n);
        for(int i=0;i<n;i++){
            distance[i]=INT_MAX;
        }
        distance[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
    
            if(distance[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(distance[top]+ i.second<distance[i.first]){
                        distance[i.first]=distance[top]+i.second;
                    }
                }
            }
            
        }

    for(auto i:distance){
        cout<<i<<" ";
    }
    
}