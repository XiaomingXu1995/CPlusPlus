#include <bits/stdc++.h>

template <typename T, typename Compare = std::less<T>>
class CustomPriorityQueue{

public:
	CustomPriorityQueue(){}
	CustomPriorityQueue(std::vector<T>& arr){
		for(T& e : arr){
			data.push_back(std::move(e));
		}
		std::make_heap(data.begin(), data.end(), compare);
	}
	~CustomPriorityQueue(){
		std::vector<T>().swap(data);
	}

	void push(const T& element){
		data.push_back(element);
		std::push_heap(data.begin(), data.end(), compare);
	}
	void pop(){
		std::pop_heap(data.begin(), data.end(), compare);
		data.pop_back();
	}

	T top() const{
		if(!data.empty())	
			return data.front();
		else 
			return T();
	}

	bool empty() const{
		return data.empty();
	}

	size_t size() const{
		return data.size();
	}

private:
	std::vector<T> data;
	Compare compare;

};
