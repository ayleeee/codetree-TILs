#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int cost[11][11];
bool visited[11];
vector<int> vec;

int ans=INT_MAX;

void FindMin(int cnt){
    if(cnt==n){
        int total_cost = 0;
        for(int i=0;i<vec.size()-1;i++){
            int now_cost = cost[vec[i]][vec[i+1]];
            if(now_cost == 0) return;
            total_cost+=now_cost;
        }
        int additional_cost = cost[vec.back()][0];
        if(additional_cost==0) return;
        ans = min(ans,total_cost+additional_cost);
        return;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            vec.push_back(i);
            FindMin(cnt+1);
            visited[i]=false;
            vec.pop_back();
        }
    }
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }

    visited[0] = true;
    vec.push_back(0);
    FindMin(1);

    cout<<ans;
    return 0;
}