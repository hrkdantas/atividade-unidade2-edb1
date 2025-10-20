#include <iostream>
#include <string>
#include <cassert>
#include "Sequence.h"

using namespace std;

void testInsertBegin() {
    Sequence* sequence = new Sequence();
    sequence->insertBegin("a");
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "a");

    sequence->insertBegin("b");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "b");
    assert(sequence->get(2) == "a");

    sequence->insertBegin("c");
    assert(sequence->getQuantity() == 3);
    assert(sequence->get(1) == "c");
    assert(sequence->get(2) == "b");
    assert(sequence->get(3) == "a");

    sequence->insertBegin("x");
    assert(sequence->getQuantity() == 4);
    assert(sequence->get(1) == "x");
    assert(sequence->get(2) == "c");
    assert(sequence->get(3) == "b");
    assert(sequence->get(4) == "a");

    delete sequence;
    cout << "TestInsertBegin OK" << endl;
}

void testInsertEnd() {
    Sequence* sequence = new Sequence();
    sequence->insertEnd("a");
    sequence->insertEnd("b");
    sequence->insertEnd("c");

    assert(sequence->getQuantity() == 3);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "b");
    assert(sequence->get(3) == "c");

    delete sequence;
    cout << "TestInsertEnd OK" << endl;
}

void testRemoveBegin() {
    Sequence* sequence = new Sequence();
    sequence->insertBegin("a");
    assert(sequence->removeBegin() == "a");
    assert(sequence->getQuantity() == 0);

    sequence->insertBegin("a");
    sequence->insertBegin("b");
    assert(sequence->removeBegin() == "b");
    assert(sequence->get(1) == "a");

    delete sequence;
    cout << "TestRemoveBegin OK" << endl;
}

void testRemoveEnd() {
    Sequence* sequence = new Sequence();
    sequence->insertBegin("a");
    sequence->insertBegin("b");
    assert(sequence->removeEnd() == "a");
    assert(sequence->getQuantity() == 1);
    assert(sequence->get(1) == "b");

    delete sequence;
    cout << "TestRemoveEnd OK" << endl;
}

void testInsert() {
    Sequence* sequence = new Sequence();
    for (int i = 1; i <= 5; i++) {
        sequence->insert(i, "elem" + to_string(i));
        assert(sequence->get(i) == "elem" + to_string(i));
    }
    assert(sequence->getQuantity() == 5);
    delete sequence;
    cout << "TestInsert OK" << endl;
}

void testRemove() {
    Sequence* sequence = new Sequence();
    sequence->insertEnd("a");
    sequence->insertEnd("b");
    sequence->insertEnd("c");

    assert(sequence->remove(2) == "b");
    assert(sequence->getQuantity() == 2);
    assert(sequence->get(1) == "a");
    assert(sequence->get(2) == "c");

    delete sequence;
    cout << "TestRemove OK" << endl;
}

void testAll() {
    Sequence* sequence = new Sequence();

    sequence->insertBegin("a");
    sequence->insertBegin("b");
    sequence->insertBegin("c");
    sequence->insertBegin("x"); // Agora x está na posição 1
    sequence->insertBegin("l");
    sequence->insertBegin("m");
    sequence->insertBegin("n");

    // Sequência esperada: n m l x c b a
    string expected[] = {"n", "m", "l", "x", "c", "b", "a"};
    for (int i = 1; i <= 7; i++) {
        assert(sequence->get(i) == expected[i - 1]);
    }

    // Testes de remoção
    assert(sequence->removeBegin() == "n");
    assert(sequence->removeEnd() == "a");
    assert(sequence->remove(3) == "x"); // Remove o "x" que estava na posição 3 agora
    assert(sequence->getQuantity() == 4);

    delete sequence;
    cout << "TestAll OK" << endl;
}

int main() {
    testInsertBegin();
    testInsertEnd();
    testRemoveBegin();
    testRemoveEnd();
    testInsert();
    testRemove();
    testAll();
    return 0;
}
