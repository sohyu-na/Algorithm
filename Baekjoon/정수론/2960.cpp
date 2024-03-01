#include <iostream>
#include <vector>
using namespace std;
int get_k(int n, int k) {
    vector <bool> v(n+1,true);
    v[0] = v[1] = false;

    for (int i = 0; i <= n; i++) {
        if (v[i]) {
            k--; 
            if (!k)
                return i;

            for (int j = i * i; j <= n; j += i) {
                if (v[j]) {
                    v[j] = false; k--;
                }
                if (!k) {
                    return j;
                }
            }
        }
    }
}
int main()
{
    int n,k; cin >> n >>k;
    
    cout << get_k(n, k);
}
