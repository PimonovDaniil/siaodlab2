#pragma once
#include <iostream>
namespace mathTools
{
    template<typename T>
    class Queue {
    private:
        struct QueueNode
        {
            T info;
            QueueNode* next;
        };

        QueueNode* BeginQueue;
        QueueNode* EndQueue;


    public:
        Queue();

        void EnQueue(T x);

        T DeQueue();

        T Top() const;

        bool isEmpty() const;

        ~Queue();
	};   
}
