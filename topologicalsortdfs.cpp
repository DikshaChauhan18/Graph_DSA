#include<bits/stdc++.h>
using namespace std;
//topo sort is only fro DAG 

void toposort(int node, unordered_map<int,bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
	    visited[node]=true;
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            toposort(i,visited,s,adj);
	        }
	    }
	    s.push(node);
	}

void dfs(int v,unordered_map<int,list<int>>&adj){
        unordered_map<int,bool>visited;
	    stack<int>s;
	    
	    for(int i=0;i<v;i++){
	        if(!visited[i]){
	            toposort(i,visited,s,adj);
	        }
	    }
	    vector<int>ans;
	    
	    while(!s.empty()){
	        cout<<s.top()<<" ";
	        s.pop();
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
        //adj[v].push_back(u);     
    }
    
    dfs(n,adj);

}