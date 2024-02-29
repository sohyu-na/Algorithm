#include <iostream>
#include <vector>

using namespace std;

//함수로 추출, 주소값으로 
//버블 정렬
void bubbleSort(vector<int>& arr){
    //n-1번 반복 
    for(int i=0;i<arr.size()-1;i++){
        //0,1부터 n-1,n까지 
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
            //int k=arr[j];
            //arr[j]=arr[j+1];
            //arr[j+1]=k;
            swap(arr[j],arr[j+1]);//두 원소 위치 바꾸는 함수 
            }
        }
    }
}

//향상된 버블 정렬
void advBubbleSort(vector<int>& arr){
    for (int i=0; i<arr.size()-1;i++){
        //swap여부를 boolean으로 표시
        bool is_swap = false; 
        for(int j=0;j<arr.size()-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                is_swap=true;
            }
        }
        if(!is_swap){//이미 정렬되어있는 경우를 걸러서 ++
            return;
        }
    }
}

//++선택정렬
//++삽입정렬

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bubbleSort(arr);
    for(int i=0;i<n;i++){
        cout << arr[i]<<"\n";
    }

    return 0;
}