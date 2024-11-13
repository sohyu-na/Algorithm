#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int n; 
vector <int> v,L,R;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    v.resize(n);
    L.resize(n);
    R.resize(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    L[0]=v[0]; //0에서 시작
    int result =L[0]; //제거x일때 최대값 저장

    for(int i=1;i<n;i++){
        L[i]=max(v[i],L[i-1]+v[i]);
        result=max(result,L[i]);
    }
    
    R[n-1]=v[n-1]; //n-1에서 시작
    for(int i=n-2;i>=0;i--){
        R[i]=max(v[i],R[i+1]+v[i]);
    }

    //L[i-1]+R[i+1]=> i번째 값을 제거한 결과와 같음
    for(int i=1;i<n-1;i++){
        int temp=L[i-1]+R[i+1];
        result = max(result,temp);
    }

    cout << result ;
    return 0;
}