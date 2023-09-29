#include<bits/stdc++.h>
using namespace std;

// sc = o(n)+o(n)+recursion stack space

//tc = o(degree)=o(2e)


void dfscall(vector<int>&ans,unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited,int v){
    ans.push_back(v);
    visited[v]=true;

    for(auto i: adj[v]){
        if(!visited[i]){
            dfscall(ans,adj,visited,i);
        }
    }
}

void dfs(int v,unordered_map<int,list<int>>&adj){
    vector<int>ans;
    unordered_map<int,bool>visited;

    dfscall(ans,adj,visited,1);

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

    dfs(1,adj);
}