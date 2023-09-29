#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>>adj;
    void addedge(int u,int v, bool direction){
        //direction--> 0= undirected
        //direction--> 1= directed

        //CREATE EDGE FROM U TO V
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }    
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n,m;
    cout<<"enter no of nodes and edges"<<endl;
    cin>>n>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.print();
}