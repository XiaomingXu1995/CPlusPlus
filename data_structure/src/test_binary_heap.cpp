#include "src/BinaryHeap.hpp"

using namespace std;

int main(int argc, char * argv[]){
	vector<int> arrs = {4, 1, 3, 9, 5};
	BinaryHeap<int> minHeap(true);
	minHeap.make_heap(arrs);
	cout << minHeap.size() << endl;

	minHeap.push(10);
	cout << minHeap.top() << endl;
	minHeap.push(14);
	cout << minHeap.top() << endl;

	cout << "===========" << endl;
	vector<int> arr2 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
	minHeap.make_heap(arr2);
	cout << minHeap.size() << endl;
	cout << endl;

	while(!minHeap.empty()){
		int x = minHeap.top();
		minHeap.pop();
		cout << x << endl;
	}

	return 0;
}
