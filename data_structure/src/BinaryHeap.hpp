#include <bits/stdc++.h>

template <typename T>
class BinaryHeap{
public:
	BinaryHeap(bool is_min_) : is_min_heap(is_min_) {}
	~BinaryHeap(){
		std::vector<T>().swap(arr);
	}
	size_t size();
	bool empty();
	T top();
	void push(T element);
	void pop();
	void make_heap(std::vector<T>& arr_);

private:
	std::vector<T> arr;
	bool is_min_heap = true;
};


template <typename T>
size_t BinaryHeap<T>::size(){
	return arr.size();
}

template <typename T>
bool BinaryHeap<T>::empty(){
	return arr.empty();
}

template <typename T>
T BinaryHeap<T>::top(){
	if(!arr.empty()){
		return arr[0];
	}
	else
		return T();
}

template <typename T>
void BinaryHeap<T>::push(T element){
	arr.push_back(element); // add the new element to the end of arr
	int current_index = arr.size()-1;
	// the top element is the first element in the arr
	while(current_index > 0){
		int parent_index = (current_index - 1) / 2;
		if((is_min_heap && arr[parent_index] < arr[current_index]) || (!is_min_heap && arr[parent_index] > arr[current_index])){
			std::swap(arr[parent_index], arr[current_index]);
			current_index = parent_index;
		}
		else{
			break;
		}
	}
}

template <typename T>
void BinaryHeap<T>::pop(){
	if(arr.empty()) return;
	std::swap(arr[0], arr[arr.size()-1]);
	arr.pop_back();

	int current_index = 0;
	int heap_size = arr.size();
	while(true){
		int left_child_index = current_index * 2 + 1;
		int right_child_index = current_index * 2 + 2;
		int root_index = current_index;

		if(left_child_index < heap_size && ((is_min_heap && arr[left_child_index] > arr[root_index]) || (!is_min_heap && arr[left_child_index] < arr[root_index]))){
			root_index = left_child_index;
		}
		if(right_child_index < heap_size && ((is_min_heap && arr[right_child_index] > arr[root_index]) || (!is_min_heap && arr[right_child_index] < arr[root_index]))){
			root_index = right_child_index;
		}
		if(root_index != current_index){
			std::swap(arr[current_index], arr[root_index]);
			current_index = root_index;
		}
		else{
			break;
		}
	}

}

template <typename T>
void BinaryHeap<T>::make_heap(std::vector<T>& arr_){
	arr.assign(arr_.begin(), arr_.end());
	size_t heap_size = arr.size();
	for(int i = heap_size / 2 - 1; i >= 0; --i){
		int current_index = i;
		while(true){
			int left_child_index = current_index * 2 + 1;
			int right_child_index = current_index * 2 + 2;
			int root_index = current_index;
			if(left_child_index < heap_size && ((is_min_heap && arr[left_child_index] > arr[root_index]) || (!is_min_heap && arr[left_child_index] < arr[root_index]))){
			root_index = left_child_index;
			}
			if(right_child_index < heap_size && ((is_min_heap && arr[right_child_index] > arr[root_index]) || (!is_min_heap && arr[right_child_index] < arr[root_index]))){
			root_index = right_child_index;
			}
			if(root_index != current_index){
				std::swap(arr[current_index], arr[root_index]);
				current_index = root_index;
			}
			else{
				break;
			}
		}
	}
}




