#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long arr[100001];
long long dp[100001];
long long temp=0;

void calc(int k) {
    temp = temp+arr[k]>arr[k]?temp+arr[k]:arr[k];
    if(dp[k-1]>temp){
        dp[k]=dp[k-1];
    }else{
        dp[k]=temp;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	cin >> arr[1];
	dp[1]=arr[1];
    temp = arr[1];
	
	for (int i = 2; i <= n; i++) {
		// 입력
		cin >> arr[i];
	
		// 계산
		calc(i);
	}
	// 출력 
	cout << dp[n];
}