
// Pushes an element to the queue 
TSQueue::void push(T item){
    // Acquire lock 
    std::unique_lock<std::mutex> lock(m_mutex); 

    // Add item 
    m_queue.push(item); 

    // Notify one thread that 
    // is waiting 
    m_cond.notify_one(); 
}
// Pops an element off the queue 
TSQueue::T pop() 
{ 

    // acquire lock 
    std::unique_lock<std::mutex> lock(m_mutex); 

    // wait until queue is not empty 
    m_cond.wait(lock, 
                [this]() { return !m_queue.empty(); }); 

    // retrieve item 
    T item = m_queue.front(); 
    m_queue.pop(); 

    // return item 
    return item; 
} 