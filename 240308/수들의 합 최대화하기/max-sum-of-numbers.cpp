#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grid[11][11];
bool visited[11];
int n;
int mx;
vector<int> vec;

void calc(int depth){
    if(depth==n){
        int sum = 0;
        for(int i=1;i<=vec.size();i++){
            sum+=grid[i][vec[i-1]];
        }
        mx = max(mx,sum);
        return;
    }
    
    for(int i=1;i<=n;i++){
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    calc(0);
    cout<<mx;
}