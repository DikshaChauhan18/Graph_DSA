#include<bits/stdc++.h>
using namespace std;
// multi souce shortest path
// detect -ve cycle
// for a -ve cycle :  costing of itself ie [0][0] should be 0 but if we have -ve cycle it will be negative

//tc(n3)
//sc(1)

int main(){
    

    vector<vector<int>>adj={{0,1,43},{1,0,6},{-1,-1,0}};
    int n=adj.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==-1){
                adj[i][j]=(int)1e9;
            }
            if(i==j){
                adj[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adj[j][k]=min(adj[j][k], adj[j][i]+adj[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==(int)1e9){
                adj[i][j]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
}