#include <iostream>
#include "../Headers/stack.h"

Node::Node(char data, Node* next) {
    this->data = data;
    this->next = next;
}


Stack::Stack() {
    head = nullptr;
    _size = 0;
}

Stack::~Stack() {
    Node* deletedNode;
    while (head != nullptr) {
        deletedNode = head;
        head = head->next;
        deletedNode->next = nullptr;
        delete deletedNode;
    }
}

void Stack::push(char data) {
    Node* newNode = new Node(data, head);
    head = newNode;
    _size++;
}

char Stack::pop() {
    Node* poppedNode = head;
    head = head->next;
    char result = poppedNode->data;
    poppedNode->next = nullptr;
    delete poppedNode;
    _size--;
    return result;
}

char Stack::top() {
    return head->data;
}

void Stack::view() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << ' ';
        temp = temp->next;;
    }
    std::cout << std::endl;
}

bool Stack::isEmpty() {
    return head == nullptr;
}

int Stack::size() {
    return _size;

}