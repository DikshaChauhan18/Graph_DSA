#include<bits/stdc++.h>
using namespace std;

// num of island = num of connected 1
// sc= o(n2)+o(n)queue

//tc = o(n2)

void bfs(int row, int col, vector<vector<bool>>&visited,vector<vector<char>>&adj){
    visited[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});

    int n = adj.size();
    int m = adj[0].size();

    while(!q.empty()){
        pair<int,int>f=q.front();
        int row=f.first;
        int col = f.second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nrow = row+i;
                int ncol= col+j;
                if(nrow>=0 && nrow<n &&ncol>=0 &&ncol<m&&adj[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    
                }
            }
        }
    }
}

void solve(vector<vector<char>>&adj){
        int n=adj.size();
        int m =adj[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && adj[i][j]=='1'){
                    c++;
                    bfs(i,j,visited,adj);
                }
            }
        }
    cout<<c;
}
int main(){
    

    vector<vector<char>>adj ={{'0','1','1','0'},{'0','1','1','0'},{'0','0','1','0'},{'0','0','0','0'},{'1','1','0','1'}};
    solve(adj);
    
}