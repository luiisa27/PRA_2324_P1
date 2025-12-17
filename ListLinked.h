#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first;
            first = first->next;
            delete aux;
        }
    }

    int size() override {
        return n;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posicion no valida");
        }

        Node<T>* newNode = new Node<T>(e, nullptr);

        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;
        T value;

        if (pos == 0) {
            value = aux->data;
            first = aux->next;
            delete aux;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            aux = prev->next;
            value = aux->data;
            prev->next = aux->next;
            delete aux;
        }
        n--;
        return value;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion no valida");
        }

        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        for (int i = 0; i < n; i++) {
            if (aux->data == e) {
                return i;
            }
            aux = aux->next;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* aux = list.first;
        out << "[ ";
        while (aux != nullptr) {
            out << aux->data << " ";
            aux = aux->next;
        }
        out << "]";
        return out;
    }

    void capicua_list() override {
    // No usado
}

};

#endif

