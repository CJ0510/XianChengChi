#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <queue>
#include <pthread.h>

using callback = void (*)(void*);
struct Task
{
    Task()
    {
        fun = nullptr;
        arg = nullptr;
    }
    Task(callback f, void* a)
    {
        fun = f;
        this->arg = a;
    }
    /* data */
    callback fun;
    void* arg;
};


class TaskQueue
{
private:
    /* data */
    std::queue<Task> m_queue;
    pthread_mutex_t m_mutex;

public:
    TaskQueue(/* args */);
    ~TaskQueue();

    // 添加任务
    void addTask(Task& task);
    void addTask(callback fun, void* arg);

    Task takeTask();

    inline int taskNumber()
    {
        return m_queue.size();
    }

};

#endif

