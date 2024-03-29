//
// Created by wangxing on 19-7-23.
//

// 使用两个栈实现队列


#include <iostream>
#include "Stack.h"

template <typename T>
class MyQueue
{
public:
    template <typename U>
    // 节点加入节点
    void add(U &&value)
    {
        newValues.push(std::forward<U>(value));
    }

    T peek()
    {
        if (reversed.isEmpty())
            move(newValues, reversed);
        return reversed.peed();
    }

    // 队列移出节点
    T remove()
    {
        if (reversed.isEmpty())
            move(newValues, reversed);
        return reversed.pop();
    }

    bool isEmpty()
    {
        return newValues.isEmpty() && reversed.isEmpty();
    }

private:
    static void move(Stack<T> &from, Stack<T> &to)
    {
        while(!from.isEmpty())
        {
            to.push(from.pop());
        }
    }
    Stack<T> newValues;   // 保存新进入的节点的栈
    Stack<T> reversed;    // 从该栈中弹出较久的节点,实现队列功能
};

int main()
{
    MyQueue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.add(i);
        std::cout << "Queued value " << i << std::endl;
    }

    for (int i = 0; i < 5 ; ++i)
    {
        std::cout << "Removed value " << queue.remove() << std::endl;
    }

    for (int i = 10; i < 15; ++i)
    {
        queue.add(i);
        std::cout << "Queued value " << i << std::endl;
    }

    while (!queue.isEmpty())
    {
        std::cout << "Removed value " << queue.remove() << std::endl;
    }
    return 1;
}