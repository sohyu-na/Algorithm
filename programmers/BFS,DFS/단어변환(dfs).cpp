#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;
int answer = INT_MAX;

bool checkWord(string& a, string& b){
    int cnt =0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}
void dfs(string& before, string& target, vector<string>& words, int cnt,vector<bool>& visited){
    if(before == target){
        answer = min(answer, cnt);
        return;
    }
    for(int i=0;i<words.size();i++){
        if(!visited[i] && checkWord(before,words[i])){
            visited[i]=true;
            dfs(words[i],target,words,cnt+1,visited);
            visited[i]=false; 
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(),false);
    dfs(begin,target,words,0,visited);
    
    if(answer==INT_MAX) return 0;
    else return answer;
}