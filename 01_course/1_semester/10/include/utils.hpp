#pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <functional>

namespace Lab9 {

    class IntNode {
        
    private:
        int _data;
        IntNode* _nextNode;
        
    public:

        IntNode(int data) : _data(data), _nextNode(nullptr) {}

        IntNode(int data, IntNode* nextNode) : _data(data), _nextNode(nextNode) {}

        IntNode* next() { return _nextNode; }

        void setNext(IntNode* node) { _nextNode = node; }

        int data() { return _data; }
    };


    class IntSingleLinkedList {

    private:
        const std::string OUT_OF_RANGE_EXCEPT_MSG = "Index is out of range!";

        IntNode* _head;
        
    public:

        IntSingleLinkedList() : _head(nullptr) {}

        void append(int value) {
            IntNode* newNode = new IntNode(value);
            
            if (_head == nullptr) _head = newNode;
            else {
                IntNode* temp = _head;
                while (temp->next() != nullptr) { temp = temp->next(); }
                temp->setNext(newNode);
            }
        }

        int operator[](int index) {
            if ( _head == nullptr || index < 0) throw std::out_of_range(OUT_OF_RANGE_EXCEPT_MSG);
            IntNode* temp = _head;
            for (int i = 0; i < index; i++) {
                if (temp->next() == nullptr) throw std::out_of_range(OUT_OF_RANGE_EXCEPT_MSG);
                temp = temp->next();
            }
            return temp->data();
        }

        std::vector<int> getVector() {
            std::vector<int> result;
            IntNode* temp = _head;
            while (temp->next() != nullptr) {
                result.push_back(temp->data());
                temp = temp->next();
            }
            return result;
        }

        std::string toString() {
            std::string result;
            IntNode* current = _head;
            while (current) {
                result = result + std::to_string(current->data());
                if (current->next()) result += " -> ";
                current = current->next();
            }
            return result;
        }

        void sort(std::function<bool(int, int)> comparison) {
            if (_head == nullptr || _head->next() == nullptr) return;
            IntNode* sorted = nullptr;
            IntNode* current = _head;
            while (current != nullptr) {
                IntNode* next = current->next();
                insertSorted(sorted, current, comparison);
                current = next;
            }
            _head = sorted;
        }

        void remove_if(std::function<bool(int)> comparison) {
            IntNode* previous = nullptr;
            IntNode* current = _head;
            IntNode* next = nullptr;
            while (current != nullptr) {
                next = current->next();
                if (comparison(current->data())) {
                    if (previous != nullptr) previous->setNext(next);
                    if (_head == current) _head = next;
                    delete current;
                    current = previous;
                }
                previous = current;
                current = next;
                next = nullptr;
            }
        }

        void duplicate_all() {
            IntNode* current = _head;
            IntNode* next = nullptr;
            while (current != nullptr) {
                next = current->next();
                IntNode* duplicatedNode = new IntNode(current->data(), next);
                current->setNext(duplicatedNode);
                current = next;
                next = nullptr;
            }
        }

        ~IntSingleLinkedList() {
            IntNode* current = _head;
            while (current != nullptr) {
                IntNode* nextNode = current->next();
                delete current;
                current = nextNode;
            }
        }

        private:
        void insertSorted(IntNode*& sorted, IntNode* newNode, std::function<bool(int, int)> comparison) {
            if (sorted == nullptr || !comparison(sorted->data(), newNode->data())) {
                newNode->setNext(sorted);
                sorted = newNode;
                return;
            }
            IntNode* temp = sorted;
            while (temp->next() != nullptr && comparison(temp->next()->data(), newNode->data())) {
                temp = temp->next();
            }
            newNode->setNext(temp->next());
            temp->setNext(newNode);
        }
    };
    

    bool onlyOddDigits(int num);

    int getFirstDigit(int num);

    bool containsDigit(int num, int digit);
}
