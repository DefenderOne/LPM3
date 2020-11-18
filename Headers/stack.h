#pragma once


struct Node {
    char data;
    Node* next;
    Node(char data = char(), Node* next = nullptr);
};

class Stack {
    private:
    Node* head;
    int _size;

    public:
    Stack();
    ~Stack();
    void push(char data);
    char pop();
    bool isEmpty();
    char top();
    void view();
    int size();
};