#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[22];
int arrSum;
int ans = 10001;

// 현재, 선택된 숫자 개수, 합
void pickNumber(int cur, int cnt, int sum);

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        arrSum+=arr[i];
    }
    
    pickNumber(0,0,0);
    cout<<ans;
}

void pickNumber(int cur, int cnt, int sum){
    if(cur == 2*n){
        if(cnt==n){
            // 현재까지 선택된 숫자들의 합 - 나머지 숫자들의 합
            ans = min(ans, abs(sum-abs((arrSum-sum))));
        }
        return;
    }
    
    // 현재 숫자를 선택한 경우
    pickNumber(cur+1, cnt+1, sum+arr[cur]);
    // 현재 숫자를 선택하지 않은 경우
    pickNumber(cur+1, cnt, sum);
}