//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include "Media.h"
#include <iostream>

template <typename T = Media*>
struct Node {
    T data;
    Node<T>* next;
    explicit Node(T value) : data(value), next(nullptr) {}
};

template <typename T = Media*>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;

public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insertBack(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = newNode;
            newNode->next = head;
            current = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(T value) {
        insertBack(value);
    }

    void clear() {
        if (!head) {
            return;
        }

        tail->next = nullptr;

        Node<T>* n = head;
        while (n) {
            Node<T>* nxt = n->next;
            delete n->data;
            delete n;
            n = nxt;
        }

        head = nullptr;
        tail = nullptr;
        current = nullptr;

        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    void displayList() const {
        if (!head) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;

        const Node<T>* start = head;
        const Node<T>* cur = head;
        int index = 1;

        do {
            if (cur->data) {
                std::cout << index++ << ". " << cur->data->toString() << std::endl;
            } else {
                std::cout << index++ << ". (null)" << std::endl;
            }
            cur = cur->next;
        } while (cur != start);

        std::cout << "------------------------" << std::endl;
    }

    void playCurrent() const {
        if (current && current->data) {
            current->data->play();
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }

    void playNext() {
        if (!head) {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
            return;
        }

        if (!current) {
            current = head;
        } else {
            current = current->next;
        }

        if (current->data) {
            current->data->play();
        }
    }
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H
