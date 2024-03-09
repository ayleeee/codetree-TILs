#include <iostream>
#include <vector>
using namespace std;

int arr[101];
vector<int> temp;
vector<int> temp2;
int n;

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s1,e1;
    cin>>s1>>e1;
    s1--;
    e1--;

    for(int i=0;i<n;i++){
        if(i>=s1 && i<=e1) continue;
        temp.push_back(arr[i]);
    }

    int s2,e2;
    cin>>s2>>e2;
    s2--;
    e2--;

    for(int i=0;i<temp.size();i++){
        if(i>=s2 && i<=e2) continue;
        temp2.push_back(temp[i]);
    }

    cout<<temp2.size()<<"\n";
    for(int i=0;i<temp2.size();i++){
        cout<<temp2[i]<<"\n";
    }
}