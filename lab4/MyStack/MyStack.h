#ifndef MYSTACK_MYSTACK_H
#define MYSTACK_MYSTACK_H
#include <iostream>

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode {              // узел списка
private:
    INF d{};                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) {
        next = nullptr;
    } //конструктор
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void) {
        top = nullptr;
    };           // конструктор
    ~MyStack(void) {
        while(!empty()) {
            pop();
        }
    };          // освободить динамическую память
    bool empty(void) {
        if (top == nullptr)
            return true;
        return false;
    };        // стек пустой?
    bool push(INF n) {
        Node* node = new Node;
        if (node == nullptr){
            return false;
        }
        node->d = n;
        node->next = top;
        top = node;
        return true;
    };        // добавить узел в вершину стека
    bool pop(void) {
        if (empty())
            return false;
        Node* node = top;
        top = top->next;
        delete node;
        return true;
    };          // удалить узел из вершины стека
    INF top_inf(void) {
        return top->d;
    };      // считать информацию из вершины стека
};

#endif