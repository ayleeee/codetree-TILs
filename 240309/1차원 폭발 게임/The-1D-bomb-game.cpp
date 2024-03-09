/*
 1 이상 100 이하의 숫자가 적혀있는 N개의 폭탄
 M개 이상 연속으로 같은 숫자가 적혀있는 폭탄은 터진다,
 중력에 의해 위에 있던 폭탄들은 다 밑으로 떨어진다.
 M개 이상 연속한 숫자를 갖는 폭탄들이 존재하지 않을 때까지 반복했을 때의 최종 결과
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> arr;
int temp[101];

int counter(int start, int value){
    for(int e = start+1;e<arr.size();e++){
        if(arr[e]!=value){
            return e-1;
        }
    }
    return arr.size()-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    
    while(true){
        bool bomb = false;
        
        for(int start=0;start<arr.size();start++){
            int num = arr[start];
            if(num==0) continue;
            
            int end = counter(start,num);
            
            if((end-start+1)>=M){
                for(int j=start;j<=end;j++){
                    arr[j]=0;
                }
                bomb = true;
            }
        }
        arr.erase(remove(arr.begin(),arr.end(),0),arr.end());
        
        if(!bomb){
            break;
        }
    }
    
    cout<<arr.size()<<"\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}