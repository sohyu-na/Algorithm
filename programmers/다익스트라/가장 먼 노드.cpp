#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 그래프 
    vector<vector<int>> graph(n+1);
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    // 다익스트라 - 1을 기준으로 
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto next:graph[node]){
            if(cost+1<dist[next]){
                dist[next]=cost+1;
                pq.push({cost+1,next});
            }
        }
    }
    int max = 0;
    for(int i=1;i<=n;i++){
        if(max<dist[i]){
            max = dist[i];
            answer=1;
        }else if(max==dist[i]){
            answer++;
        }
    }
    
    return answer;
}