#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>

using namespace std; 
struct Trie {
	Trie* child[10];
	bool isEnd;

	// 초기화 
	Trie() {
		isEnd = false;
		for (int i = 0; i < 10; i++) child[i] = nullptr;
	}
	// 소멸자 
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (child[i] != nullptr) delete child[i];
		}
	}

	bool insert(const string& s) {
		Trie* node = this;

		for (int i = 0; i < s.size(); i++) {
			int num = s[i] - '0';

			//이미 여기서 끝난 번호 존재 = s의 접두어 존재
			if (node->isEnd) return false;
			if (node->child[num] == nullptr) node->child[num] = new Trie();

			node = node->child[num];
		}

		// s를 다 넣었는데 이미 자식이 존재 = s가 기존의 접두어 
		for (int i = 0; i < 10; i++) {
			if (node->child[i] != nullptr) return false;
		}

		node->isEnd = true; // s의 끝
		return true;
	}
};

int main() {
	int t; cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		Trie* root = new Trie();
		bool check = true;

		string phone;
		for (int i = 0; i < n; i++) {
			cin >> phone;

			if (check) {
				if (!root->insert(phone)) check = false;
			}
		}
		cout << (check ? "YES\n" : "NO\n");
		
		delete root;
	}
}

	