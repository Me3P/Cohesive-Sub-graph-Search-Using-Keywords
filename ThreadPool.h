//
// Created by Saman on 13/03/2024.
//

#include <atomic>
#include <vector>
#include <iostream>
#include <functional>
#include <thread>
#include "TSQueue.h"

#ifndef UNTITLED_ThreadPool_H
#define UNTITLED_ThreadPool_H

class ThreadPool{
public:
    TSQueue<std::function<void()>> work_queue;
    std::queue<std::thread> threads;
    std::atomic_bool shut_down;
    
    ~ThreadPool();
    ThreadPool(std::atomic_bool);

    void operator()();
    template<typename Function_type> void submit(Function_type f);
    void run();
};


#endif //UNTITLED_ThreadPool_H