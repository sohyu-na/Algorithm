#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int dp[1000001];

void calc(int a){
    for(int i=3;i<=a;i++){
        dp[i]=(dp[i-2]+dp[i-1])%15746;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    // 입력
	int a; cin >> a;
	
	// 계산 
	dp[1]=1; 
	dp[2]=2; 
    calc(a);
    
	// 출력 
	cout<< dp[a];
}