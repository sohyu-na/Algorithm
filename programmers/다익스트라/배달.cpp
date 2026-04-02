#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    //그래프 구현
    vector<vector<pair<int,int>>> graph(N+1);
    for(int i=0;i<road.size();i++){
        graph[road[i][0]].push_back({road[i][1],road[i][2]});
        graph[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    
    //다익스트라 
    vector<int> dist(N+1,INT_MAX);
    dist[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});//비용,노드
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(cost>dist[node]) continue;
        for(auto next : graph[node]){
            if(cost+next.second<dist[next.first]){
                dist[next.first]=cost+next.second;
                pq.push({cost+next.second,next.first});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[i]<=K) answer++;
    }

    return answer;
}