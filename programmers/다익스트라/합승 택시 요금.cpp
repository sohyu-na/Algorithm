#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    //가중치 그래프
    vector<vector<pair<int,int>>> graph(n+1);   
    for(int i=0;i<fares.size();i++){
        graph[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    
    //다익스트라
    vector<int> distS(n+1,INT_MAX); 
    distS[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    pq.push({0,s});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(cost>distS[node]) continue;
        for(auto next : graph[node]){
            if(cost+next.second<distS[next.first]){
                distS[next.first]=cost+next.second;
                pq.push({cost+next.second,next.first});
            }
        }
    }
    answer = distS[a]+distS[b];
    
    for(int i=1;i<=n;i++){
        vector<int> dist(n+1,INT_MAX); 
        dist[i]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
        pq.push({0,i});
    
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
        answer = min(answer,distS[i]+dist[a]+dist[b]);
    }
    return answer;
}