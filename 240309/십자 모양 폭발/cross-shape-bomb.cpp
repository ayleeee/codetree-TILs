#include <iostream>
using namespace std;

int n,r,c;
int grid[201][201];
int temp[201][201];

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
    bomb--;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==r && j==c){
                grid[i][j]=0;
            }
        }
    }

    for(int i=0;i<=bomb;i++){
        if(r-i<0 || c-i<0) continue;
        grid[r+i][c]=0;
        grid[r-i][c]=0;
        grid[r][c+i]=0;
        grid[r][c-i]=0;
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