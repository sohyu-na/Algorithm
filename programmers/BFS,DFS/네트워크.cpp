#include <string>
#include <vector>

using namespace std;
void dfs(int k, vector<vector<int>>& computers,vector<int>& net){
    for(int i=0;i<computers[k].size();i++){
        if(computers[k][i] && !net[i]){
            net[i]=net[k];
            dfs(i,computers,net);
        }
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> net(n,0);
    for(int i=0;i<n;i++){
        if(!net[i]) { 
            answer++; net[i]=answer;
            dfs(i,computers,net);
        }
    }
    
    return answer;
}