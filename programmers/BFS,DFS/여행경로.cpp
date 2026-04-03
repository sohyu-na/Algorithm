#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> answer;

bool DFS(string city, vector<string>& path,vector<vector<string>>& tickets,vector<bool>& used){
    if(path.size()==tickets.size()+1){
        answer=path;
        return true;
    }
    for(int i=0;i<tickets.size();i++){
        if(!used[i] && city == tickets[i][0]){
            path.push_back(tickets[i][1]);
            used[i]=true;
            if(DFS(tickets[i][1],path,tickets,used)) return true;
            
            used[i]=false;
            path.pop_back(); 
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end()); //사전순 정렬
    
    vector<bool> used(tickets.size(), false);
    vector<string> path;
    path.push_back("ICN");
    DFS("ICN",path,tickets,used);
    
    return answer;
}