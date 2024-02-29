#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n ;
    map <int,string> car ;
    vector <int> v(n);
    string input;
    int sum=0;
    
    for (int i=1;i<n+1;i++)
        cin >> car[i];
        
    for (int j=0;j<n;j++){
        cin >> input;
        for (int i=1;i<n+1;i++){
            if(car[i]==input)
                v[j]=i;
        }
    }
    for(int i=0;i<n;i++){
       for (int j=1;j<n-i;j++){
            if(v[i]>v[i+j]){
                sum++;
                break;
            }
        } 
    }
    
    cout << sum ;
    
    return 0;
    
}