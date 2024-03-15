#include "ThreadPool.h"



void ThreadPool::()(){
    while (done || )
    {
        std::function<void()> task = work_queue.pop();
        task();
    }   
}

ThreadPool::ThreadPool(std::atomic_bool done,join_threads joiner){
    this->done = done;
    this->joiner = joiner;
    int const thread_count = std::max(std::thrad::hardware_concurrency() - 1, 1);
    try
    {
        for (int i = 0; i < thread_count; i++){
            threads.push_back(
                std::thread(&thread_pool::worker_thread, this));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        done = true;
        throw;
    }   
    
    
}

ThreadPool::~ThreadPool(){
    done = true;
}


template<typename Function_type, typename... Args> // typename F
auto ThreadPool::submit(Function_type f, Args&&... args) -> std::future<decltype(f(args...))> // F&&
{
    auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(std::forward<F>(f), std::forward<Args>(args)...);
    auto wrapper_func = [task_ptr]() { (*task_ptr)();};
    {
        work_queue.push(wrapper_func);
    }
    work_queue.push(std::function<void()>(f));

    return task_ptr->get_future();
}

void ThreadPool::run(){
    std::cout<< "Testing thread pool" << std::endl;
    ThreadPool pool;

    for (int i = 0; i < 100; i++)
    {
        pool.submit([=]{
            printf(" %d printed by thread - %d \n", i, (uint64_t)std::this_thread::get_id());
        });
        
        system("pause");
    }
    
}

int main(){
    ThreadPool p(false, join_threads);
    p.run();
}