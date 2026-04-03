#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

bool checkWord(string& a, string& b){
    int cnt =0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {

    vector<bool> visited(words.size(),false);
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while(!q.empty()){
        string before = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(before == target) return cnt;

        for(int i=0;i<words.size();i++){
            if(!visited[i] && checkWord(before,words[i])){
                visited[i]=true;
                q.push({words[i],cnt+1});
            }
        }
    }
    return 0;
}