EXE=test_binary_heap test_custom_priority_queue

all: ${EXE}
test_binary_heap: src/test_binary_heap.cpp 
	g++ src/test_binary_heap.cpp -o test_binary_heap
test_custom_priority_queue: src/test_custom_priority_queue.cpp
	g++ src/test_custom_priority_queue.cpp -o test_custom_priority_queue

clean:
	rm ${OBJ} ${EXE}

