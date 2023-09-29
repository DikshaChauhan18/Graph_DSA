#include<bits/stdc++.h>
using namespace std;


//NO OF PROVINCES : no of dfs call of traversal to cover all nodes

// for dfs - sc = o(n)+o(n)={node+recursion stack space}
//           tc = o(v+2e)-all nodes--o(n)


void solvebfs(int v, unordered_map<int,list<int>>&adj){
    vector<int>ans;
    unordered_map<int,bool>visited;
    queue<int>q;
    q.push(v);
    int c=0;
    visited[v]=true;
    c++;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){
            
            if(!visited[i]){
                c++;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    cout<<"no of provinces = "<<c<<endl;
}
void dfscall(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited,int v){
    
    visited[v]=true;
    
    for(auto i: adj[v]){
        if(!visited[i]){
            dfscall(adj,visited,i);
            
        }
    }
}

void dfs(int v,unordered_map<int,list<int>>&adj,int m){
    unordered_map<int,bool>visited;
    int c=0;
    for(int i=0;i<m;i++){
        if(!visited[i]){
            c++;
            dfscall(adj,visited,i);
        }
    }
    
    cout<<" no of provinces "<<c;

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
    solvebfs(1,adj);
    dfs(1,adj,m);
    
}