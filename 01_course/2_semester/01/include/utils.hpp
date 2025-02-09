#pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <functional>

namespace Lab1 {

    struct IntNode {
        int _data;
        IntNode* _prev;
        IntNode* _next;

        IntNode() : _prev(this), _next(this) {}

        IntNode(int data) : _prev(this), _next(this), _data(data) {}

        IntNode(int data, IntNode* prev, IntNode* next) : _data(data), _prev(prev), _next(next) {}
    };


    class DoublyLinkedList {

    private:
        IntNode* _sentinel;
        int _size;
        
    public:
        DoublyLinkedList() : _sentinel(new IntNode()), _size(0) {}

        ~DoublyLinkedList() {
            IntNode* temp = this->_sentinel->_next;
            while (temp != this->_sentinel) {
                IntNode* nextNode = temp->_next;
                delete temp;
                temp = nextNode;
            }
            delete _sentinel;
        }

        int size() { return this->_size; }

        void append(int value) {
            IntNode* newNode = new IntNode(value, _sentinel->_prev, _sentinel);
            newNode->_next->_prev = newNode;
            newNode->_prev->_next = newNode;
            this->_size++;
        }

        int get_at(size_t index) {
            if (index >= this->_size || index < 0) throw std::out_of_range("Index out of range");
            
            IntNode* current = this->_sentinel;
            bool inverse = index > _size / 2;
            if (inverse) index = this->_size - index - 1;
            for (int i = 0; i != index; i++) {
                if (inverse) current = current->_prev;
                else current = current->_next;
            }

            return current->_data;
        }

        std::vector<int> getVector() {
            std::vector<int> result;
            IntNode* temp = this->_sentinel->_next;
            while (temp != this->_sentinel) {
                result.push_back(temp->_data);
                temp = temp->_next;
            }

            return result;
        }

        std::string toString() {
            if (this->_size == 0) return "[]";

            std::string result = "[";
            IntNode* temp = this->_sentinel->_next;
            while (temp != this->_sentinel) {
                result = result + std::to_string(temp->_data);
                temp = temp->_next;
                if (temp != this->_sentinel) result +=  ", ";
            }
            result += "]";
            return result;
        }

        bool is_sorted(bool reverse = false) {
            if (this->_size < 2) return true;

            IntNode* temp = this->_sentinel->_next;
            while (temp->_next != this->_sentinel) {
                bool cond = temp->_data < temp->_next->_data;
                if ((reverse && cond) || (!reverse && !cond)) return false;
                temp = temp->_next;
            }

            return true;
        }

        void sort(std::function<bool(int, int)> cmp) {
            if (this->_size < 2) return;
            
            bool swapped;
            IntNode* last = this->_sentinel;
            IntNode* c_prev = nullptr; 
            IntNode* c_next = nullptr;
            
            do {
                swapped = false;
                IntNode* current = this->_sentinel->_next;
                
                while (current->_next != last) {
                    if (cmp(current->_next->_data, current->_data)) {
                        std::swap(current->_data, current->_next->_data);
                        swapped = true;
                    }
                    current = current->_next;
                }
                last = current;
            } while (swapped);
        }

        void remove_if(std::function<bool(int)> comparison) {
            if (this->_size == 0) return;
            
            IntNode* next = nullptr;
            IntNode* temp = this->_sentinel->_next;
            while (temp != this->_sentinel) {
                next = temp->_next;
                if (comparison(temp->_data)) {
                    temp->_next->_prev = temp->_prev;
                    temp->_prev->_next = temp->_next;
                    delete temp;
                    this->_size--;
                }
                temp = next;
            }
        }

        void duplicate_if(std::function<bool(int)> comparison) {
            if (this->_size == 0) return;

            IntNode* next = nullptr;
            IntNode* temp = this->_sentinel->_next;
            while (temp != this->_sentinel) {
                next = temp->_next;
                if (comparison(temp->_data)) {
                    IntNode* newNode = new IntNode(temp->_data, temp->_prev, temp);
                    newNode->_next->_prev = newNode;
                    newNode->_prev->_next = newNode;
                    this->_size++;
                }
                temp = next;
            }
        }
    };
    
    bool isPrime(int n);

    int getFirstDigit(int num);
}
