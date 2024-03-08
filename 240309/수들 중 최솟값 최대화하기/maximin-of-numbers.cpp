#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[11];
int grid[11][11];
vector<int> vec;
vector<int> minValues;
int n;

void calc(int depth){
    int minVal = 10001;
    
    if(depth==n){
        for(int i=0;i<n;i++){
            minVal = min(minVal,grid[i][vec[i]]);
        }
        minValues.push_back(minVal);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            vec.push_back(i);
            calc(depth+1);
            vec.pop_back();
            visited[i]=false;
        }
    }
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
    
    calc(0);
    
    int ans = *max_element(minValues.begin(),minValues.end());
    
    cout<<ans;
}