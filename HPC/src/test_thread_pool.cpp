#include "ThreadPool.hpp"
#include <cstdio>
#include <unistd.h>

void example_task(void * arg){
	int * num = static_cast<int*>(arg);
	//std::cout << "Task executation with argument: " << *num << std::endl;
	printf("Task executaion with argument %d\n", *num);
	delete num;
}


int main(int argc, char* argv[]){
	int num_threads = 4;
	bool is_finished = false;
	ThreadPool pool(num_threads);
	for(int i = 0; i < 10; i++){
		int *num = new int(i);
		pool.enque_task(example_task, num);
	}
	//the sleep is to promise all the tasks are enqueued.
	sleep(2);
	std::cout << "finished the main" << std::endl;

	return 0;
}
