#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEmpty(vector <int> &heap) {
    return heap.size() == 1;
}
int pop(vector <int>& heap) {
    int item = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();

    int size = heap.size();
    int parent = 1;
    int child = 2;

    while (child<size) {
        if (child + 1 < size and heap[child] < heap[child + 1]) {
            child++;
        }

        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        }
        else {
            break;
        }
    }
    return item;
}

void push(int x, vector <int>& heap) {
    int idx = heap.size();
    heap.push_back(x);

    while (idx > 1 and heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        idx /= 2;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x; cin >> n;
    vector <int> heap_vec;
    heap_vec.push_back(0);

    while (n--) {
        cin >> x;
        if (x == 0) {
            if (isEmpty(heap_vec)) {
                cout << "0\n";
            }
            else {
                cout << pop( heap_vec) << "\n";
            }
        }
        else {
            push(x, heap_vec);
        }
    }

    return 0;
}

