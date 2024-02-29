#include <iostream>
#include <vector>
#include <algorithm> //sort함수쓸때 필요함

using namespace std;

vector <int> sorted;//합병함수에서 정렬된 배열을 받아야함 

//예시 코드 참고함
//합병
//b를 기준으로 이미 정렬되어있음
void merge(vector<int>& arr,int left,int b,int right){
    int pl=left, pr=b+1, i=left;
    while(pl<=b&&pr<=right){//두 배열 중 비교가 끝난 배열이 있는지
        if(arr[pl]<arr[pr])
            sorted[i++]=arr[pl++];
        else
            sorted[i++]=arr[pr++];
        }
    while(pl<=b)//오른쪽 배열은 끝, 왼쪽 남음 
        sorted[i++]=arr[pl++];
    while(pr<=right)//왼쪽 배열은 끝, 오른쪽 남음
        sorted[i++]=arr[pr++];
    for(int i=left;i<=right;i++)
        arr[i]=sorted[i];
}
//분할
void mergeSort(vector<int>& arr,int left,int right){
    if(left<right){
        int b = (left+right)/2;//어처피 정수반환하므로 몫만 남음
        mergeSort(arr,left,b);
        mergeSort(arr,b+1,right);
        merge(arr,left,b,right);
    }
    
}


int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n,0);
    sorted.assign(n,0); //벡터 선언후 지정하는 방법 
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    //algorithm include하고 이거 한줄만 쓰면 해결가능 !!!!
	//sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        cout << arr[i]<<"\n";
    }

    return 0;
}