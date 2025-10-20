#ifndef __Sequence__Node__
#define __Sequence__Node__

template <typename T>
class Node
{
private:
    T value;
    Node* next;

public:
    Node();
    Node(T val);
    Node(T val, Node* n);

    T getValue();
    void setValue(T val);
    Node* getNext();
    void setNext(Node* n);
};

template<typename T>
Node<T>::Node(): next(nullptr) {}

template<typename T>
Node<T>::Node(T val): value(val), next(nullptr) {}

template<typename T>
Node<T>::Node(T val, Node* n): value(val), next(n) {}

template<typename T>
T Node<T>::getValue() { return value; }

template<typename T>
void Node<T>::setValue(T val) { value = val; }

template<typename T>
Node<T>* Node<T>::getNext() { return next; }

template<typename T>
void Node<T>::setNext(Node<T>* n) { next = n; }

#endif
