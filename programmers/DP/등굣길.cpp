#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101]={0};
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][0]][puddles[i][1]]=-1;
    }
    
    dp[1][1]=1;
    for(int i=2;i<=m;i++){
        if(dp[i][1]!=-1) dp[i][1]=dp[i-1][1];
        else dp[i][1]=0;
    }
    for(int i=2;i<=n;i++){
        if(dp[1][i]!=-1) dp[1][i]=dp[1][i-1];
        else dp[1][i]=0;
    }
    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            if(dp[i][j]!=-1) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            else dp[i][j]=0;
        }
    }

    return answer = dp[m][n];
}