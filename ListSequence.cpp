#include "Sequence.h"

// Criar sequência vazia
Sequence::Sequence() {
    first = nullptr;
    quantity = 0;
}

// Destruir sequência e liberar memória
Sequence::~Sequence() {
    Node<std::string>* current = first;
    while(current != nullptr) {
        Node<std::string>* temp = current;
        current = current->getNext();
        delete temp; // apagar nó antigo
    }
}

// Pegar o i-ésimo elemento (começando do 1)
std::string Sequence::get(int i) {
    Node<std::string>* current = first;
    int count = 1;
    while(current != nullptr && count < i) {
        current = current->getNext();
        count++;
    }
    if(current) return current->getValue();
    return ""; // se não achar, retorna vazio
}

// Inserir no começo
void Sequence::insertBegin(std::string element) {
    Node<std::string>* node = new Node<std::string>(element);
    node->setNext(first);
    first = node;
    quantity++;
}

// Inserir no final
void Sequence::insertEnd(std::string element) {
    Node<std::string>* node = new Node<std::string>(element);
    if(first == nullptr) {
        first = node;
    } else {
        Node<std::string>* current = first;
        while(current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(node);
    }
    quantity++;
}

// Inserir na posição i
void Sequence::insert(int i, std::string element) {
    if(i <= 1) {
        insertBegin(element);
    } else if(i > quantity) {
        insertEnd(element);
    } else {
        Node<std::string>* current = first;
        int count = 1;
        while(count < i-1) {
            current = current->getNext();
            count++;
        }
        Node<std::string>* node = new Node<std::string>(element);
        node->setNext(current->getNext());
        current->setNext(node);
        quantity++;
    }
}

// Remover do começo
std::string Sequence::removeBegin() {
    if(first == nullptr) return "";
    Node<std::string>* temp = first;
    first = first->getNext();
    std::string val = temp->getValue();
    delete temp;
    quantity--;
    return val;
}

// Remover do final
std::string Sequence::removeEnd() {
    if(first == nullptr) return "";
    if(first->getNext() == nullptr) return removeBegin();

    Node<std::string>* current = first;
    while(current->getNext()->getNext() != nullptr) {
        current = current->getNext();
    }
    Node<std::string>* temp = current->getNext();
    std::string val = temp->getValue();
    delete temp;
    current->setNext(nullptr);
    quantity--;
    return val;
}

// Remover da posição i
std::string Sequence::remove(int i) {
    if(i <= 1) return removeBegin();
    if(i >= quantity) return removeEnd();

    Node<std::string>* current = first;
    int count = 1;
    while(count < i-1) {
        current = current->getNext();
        count++;
    }
    Node<std::string>* temp = current->getNext();
    current->setNext(temp->getNext());
    std::string val = temp->getValue();
    delete temp;
    quantity--;
    return val;
}

// Quantidade de elementos
int Sequence::getQuantity() {
    return quantity;
}

// Está vazia?
bool Sequence::isEmpty() {
    return quantity == 0;
}

// Retorna o primeiro nó
Node<std::string>* Sequence::getFirst() {
    return first;
}

