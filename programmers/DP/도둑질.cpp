#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> dp(money.size());
    dp[0]=money[0]; //0번 선택 - n-1 불가
    dp[1]=dp[0];
    for(int i=2;i<money.size()-1;i++){
        dp[i] = max(dp[i-1],dp[i-2]+money[i]);
    }
    dp[money.size()-1]= dp[money.size()-2];
    
    vector<int> d(money.size());
    d[0]=0; 
    d[1]=money[1];
    for(int i=2;i<money.size();i++){
        d[i] = max(d[i-1],d[i-2]+money[i]);
    }
    
    return max(dp[money.size()-1],d[money.size()-1]);
}