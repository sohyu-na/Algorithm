#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N; cin >> N ;

	vector <int> vp;
	vector <int> vm;
	int k;
	int a = 1;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> k;
		if (k > 1) {
			vp.push_back(k);
		}
		else if (k < 0) {
			vm.push_back(k);
		}
		else if(k==0){
			a = 0;//0이 존재함 
		}
		else {
			ans++;
		}
	}
	sort(vm.begin(), vm.end());
	sort(vp.begin(), vp.end(),greater<>());
	//음수가 2개 이상이면 음수끼리 묶기
	//음수가 1개 이고 0 있으면 0이랑 묶기
	//양수끼리는 1을 제외하고는 묶는게 커짐 

	if (vm.size() % 2 == 0) {//음수가 짝수개 있으면 음수끼리 짝짓기
		for (int i = 0; i < vm.size(); i+=2) {
			ans += vm[i] * vm[i + 1];
		}
	}
	else {
		for (int i = 0; i < vm.size()-1; i += 2) {
			ans += vm[i] * vm[i + 1];
		}
		if (a != 0) {
			ans += vm[vm.size() - 1];
		}
	}
	
	if (vp.size() % 2 == 0) {
		for (int i = 0; i < vp.size(); i += 2) {
			ans += vp[i] * vp[i + 1];
		}
	}
	else {
		for (int i = 0; i < vp.size() - 1; i += 2) {
			ans += vp[i] * vp[i + 1];//cout << ans;
		}
		ans += vp[vp.size() - 1];
	}
	cout << ans;
}