#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt =0;

void dfs(int sum, int i, vector<int>& numbers, bool check, int target){
    if(check) sum +=numbers[i];
    else sum -=numbers[i];
    
    if(i==numbers.size()-1){
        if(sum == target) cnt++;
        return;
    }
    dfs(sum,i+1,numbers,true,target);
    dfs(sum,i+1,numbers,false,target);
    
}
int solution(vector<int> numbers, int target) {
    int answer =0;
    dfs(0, 0, numbers,true,target);
    dfs(0, 0, numbers,false,target);
    answer = cnt;
    return answer;
}