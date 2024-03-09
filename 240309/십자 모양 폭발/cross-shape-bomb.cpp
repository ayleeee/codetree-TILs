#include <iostream>
#include <cmath>
using namespace std;

int n,r,c;
int grid[201][201];
int temp[201][201];

bool InRange(int x, int y, int r, int c, int bomb){
    return (x==r||y==c)&&abs(x-r)+abs(y-c)<bomb;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    cin>>r>>c;
    r--;
    c--;
    
    
    int bomb = grid[r][c];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(InRange(i, j, r, c, bomb)){
                grid[i][j]=0;
            }
        }
    }
    
    for(int col=0;col<n;col++){
        int temp_row = n-1;
        for(int row=n-1;row>=0;row--){
            if(grid[row][col]!=0){
                temp[temp_row][col]=grid[row][col];
                temp_row--;
            }
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}