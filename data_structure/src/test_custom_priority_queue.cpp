#include "CustomPriorityQueue.hpp"

using namespace std;

int main(int argc, char * argv[]){
	vector<int> arr = {1, 5, 3, 8, 9, 6, 2};
	//CustomPriorityQueue<int, std::less<int>> maxHeap(arr);
	CustomPriorityQueue<int> maxHeap(arr);

	maxHeap.push(30);
	maxHeap.push(10);
	maxHeap.push(50);

	while(!maxHeap.empty()){
		cout << maxHeap.top() << endl;
		maxHeap.pop();
	}

	return 0;
}
