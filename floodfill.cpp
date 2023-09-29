// flood fill algo is basically that we have to fill the given and all its connected nodes having same color,
// starting row and col as well as the color is given
// up down left right movement is allowed


#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc,int inicolor, vector<vector<int>>&ans, vector<vector<int>>&adj,int ncolor,int nr[],int nc[]){
    int n = adj.size();
    int m = adj[0].size();
    ans[sr][sc]=ncolor;
    for(int i=0;i<4;i++){
        int nrow = sr+nr[i];
        int ncol = sc+nc[i];
        if(nrow >=0 && nrow <n && ncol >=0 && ncol<m){
            if(adj[nrow][ncol]==inicolor && ans[nrow][ncol]!=ncolor){
                dfs(nrow,ncol,inicolor,ans,adj,ncolor,nr,nc);
            }
        }
    }
}

vector<vector<int>> solve(vector<vector<int>>&adj,int sr, int sc,int newcolor){
    int inicolor= adj[sr][sc];

    vector<vector<int>>ans = adj;
    int newrow[]={-1,0,+1,0};
    int newcol[]={0,+1,0,-1};
    dfs(sr,sc,inicolor,ans,adj,newcolor,newrow,newcol);
    return ans;
}
int main(){
    

    vector<vector<int>>adj ={{1,1,1},{2,2,0},{2,2,2}};
    int sr = 2, sc =0;
    int newcolor=3;
    vector<vector<int>>ans = solve(adj,sr,sc,newcolor);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}