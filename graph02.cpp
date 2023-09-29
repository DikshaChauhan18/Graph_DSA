#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int g[n+1][m+1]={0};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}