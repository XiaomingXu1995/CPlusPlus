#include <bits/stdc++.h>
#include <pthread.h>

class ThreadPool{
public:
	ThreadPool(int thread_number_) : thread_number(thread_number_), is_running(true){
		thread_t_arr.resize(thread_number);
		for(int i = 0; i < thread_number; i++){
			pthread_create(&thread_t_arr[i], nullptr, worker_thread, this);
		}
	}

	~ThreadPool(){
		stop();
	}

	void stop(){
		if(!is_running){
			return;
		}
		is_running = false;
		pthread_mutex_lock(&mutex);
		pthread_cond_broadcast(&condition);
		pthread_mutex_unlock(&mutex);
		for(int i = 0; i < thread_number; i++){
			pthread_join(thread_t_arr[i], nullptr);
		}
	}

	void enque_task(void (*task)(void*), void* arg){
		pthread_mutex_lock(&mutex);
		tasks.push({task, arg});
		pthread_cond_signal(&condition);
		pthread_mutex_unlock(&mutex);
	}

private:
	struct Task{
		void (*function) (void*);
		void *argument;
	};
	int thread_number;
	volatile bool is_running;
	std::vector<pthread_t> thread_t_arr;
	std::queue<Task> tasks;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

	static void * worker_thread(void * arg){
		ThreadPool * pool = static_cast<ThreadPool*>(arg);
		while(pool->is_running){
			pthread_mutex_lock(&pool->mutex);
			while(pool->tasks.empty() && pool->is_running){
				pthread_cond_wait(&pool->condition, &pool->mutex);
			}
			if(!pool->tasks.empty()){
				auto task = pool->tasks.front();
				pool->tasks.pop();
				pthread_mutex_unlock(&pool->mutex);
				task.function(task.argument);
			}
			else{
				pthread_mutex_unlock(&pool->mutex);
			}
		}//end while
		return nullptr;
	}
};
