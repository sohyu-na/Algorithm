#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    // 그래프 
    vector<vector<int>> graph(n+1);
    for(int i=0;i<roads.size();i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    
    // 다익스트라 
    vector<int> dist(n+1,INT_MAX);
    dist[destination]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,destination});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost>dist[node]) continue;
        for(auto next:graph[node]){
            if(cost+1<dist[next]){
                dist[next]= cost+1;
                pq.push({cost+1,next});
            }
        }
    }
    for(int i=0;i<sources.size();i++){
        if(dist[sources[i]]==INT_MAX) answer.push_back(-1);
        else answer.push_back(dist[sources[i]]);
    }
    return answer;
}