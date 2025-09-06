#pragma once

template <typename T>
class Node {

    private:
    T value;
    Node<T>* next;

    public:

    Node(T& data) {
        this->value = data;
        this->next = nullptr;
    }
    T& getValue() {
        return this->value;
    }

    void setValue(T data) {
        this->value = data;
    }

    Node<T>* getNext(){
        return this->next;
    }

    void setNext(Node<T>* next) {
        this->next = next;
    }

    ~Node<T>() {
        //This is a destructor
    }


};
