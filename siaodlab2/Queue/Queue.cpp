#include "Queue.h"
#include <iostream>
#include <locale.h>
#include <iomanip>

namespace mathTools
{
    template<typename T>
    Queue<T>::Queue()
    {
        BeginQueue = nullptr;
        EndQueue = nullptr;
    }

    template<typename T>
    void Queue<T>::EnQueue(T x)
    {
        QueueNode* p = new QueueNode;
        p->info = x;
        p->next = nullptr;
        if (BeginQueue == nullptr)
            BeginQueue = p;
        else
            EndQueue->next = p;
        EndQueue = p;
    }

    template<typename T>
    T Queue<T>::DeQueue()
    {
        T val;
        QueueNode* p = new QueueNode;
        p = BeginQueue;
        val = BeginQueue->info;
        BeginQueue = p->next;
        if (BeginQueue == nullptr)
            EndQueue = nullptr;
        delete p;
        return(val);
    }

    template<typename T>
    T Queue<T>::Top() const
    {
        return BeginQueue->info;
    }

    template<typename T>
    bool Queue<T>::isEmpty() const
    {
        return (BeginQueue == nullptr) ? true : false;
    }

    template<typename T>
    Queue<T>::~Queue()
    {
        while (!this->isEmpty())
            this->DeQueue();
    }
}

