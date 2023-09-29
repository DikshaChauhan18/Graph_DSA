#include<bits/stdc++.h>
using namespace std;
// sc = o(n)
//tc = o(n)+o(2e)
bool solve(int i, unordered_map<int,bool>&visi,unordered_map<int,bool>&dfsvisi,unordered_map<int,list<int>>&adj){
    visi[i]=true;
    dfsvisi[i]=true;

    for(auto j: adj[i]){
        if(!visi[j]){
            bool c= solve(j,visi,dfsvisi,adj);
            if(c)return true;
            
        }
        else if(dfsvisi[j])return true;
    }
    dfsvisi[i]=false;
    return false;
}

bool dfs(int v,unordered_map<int,list<int>>&adj){
    unordered_map<int,bool>visi;
    unordered_map<int,bool>dfsvisi;

    for(int i=0;i<v;i++){
        if(!visi[i]){
            bool c= solve(i,visi,dfsvisi,adj);
            if(c)return true;
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
        //adj[v].push_back(u);     
    }
    bool check = 0; 
    check =dfs(1,adj);
    if(check==1)cout<<"cycle";
    else cout<<"no";
}