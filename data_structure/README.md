# Data Structure

### class BinaryHeap

constructor:
```c++
BinaryHeap<T> minHeap(true); // true means top element is the largest
```
member functions:
```c++
size_t size(); // return the heap size
bool empty(); // return true when empty
T top(); // return the top element
void push(); // push an element into heap
void pop(); // pop the top element, heap size minus one
void make_heap(std::vector<T>& arr_); // create heap from a vector
```
More details of the example are shown in  `test_binary_heap.cpp`.

