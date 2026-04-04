#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool possible(int mid, vector<int>& rocks, int n){
    int prev =0;
    for(auto i : rocks){
        if(i-prev<mid) {
            n--;
        }
        else{
            prev=i;
        }       
        if(n<0) return false;
    }
    return true;
}

int solution(int distance, vector<int> rocks, int n) {    
    sort(rocks.begin(),rocks.end());
    rocks.push_back(distance);
    
    int left = 0;
    int right = distance;
    
    while(left<=right){
        int mid = (left+right)/2;
        if(possible(mid,rocks,n)) left = mid+1;
        else right=mid-1;
    }
    
    return right;
}