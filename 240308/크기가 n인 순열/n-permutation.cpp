#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[9];
vector<int> vec;
bool visited[9];

void calc(int depth){
    if(depth==n){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[arr[i]]){
            visited[arr[i]]=true;
            vec.push_back(arr[i]);
            calc(depth+1);
            vec.pop_back();
            visited[arr[i]]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    calc(0);
}