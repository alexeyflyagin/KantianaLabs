// The laboratory work was performed by a 1st year student
// Direction: Mathematical support and administration of information systems
// Option: 8
// Flyagin Alexey


#include <iostream>


class CustomVector {
private:
    int* data;
    size_t size;
    size_t capacity;
    
public:
    CustomVector(size_t s = 0) : size(s), capacity(s), data(s ? new int[s]{} : nullptr) {}

    CustomVector(const CustomVector& other) {
        copy_from_another_vector(other);
    }

    CustomVector& operator=(const CustomVector& other) {
        if (this == &other) return *this;

        delete[] data;
        copy_from_another_vector(other);
        return *this;
    }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    void resize(size_t count, int value = 0) {
        if (count == size) return;
        if (count == 0) {
            clear();
            return;
        }
        size_t new_capacity = (count > capacity) ? std::max(count, capacity * 2) : capacity;
        int* new_data = new int[new_capacity];

        if (size > count) {
            std::copy(data, data + count, new_data);
        } else {
            std::copy(data, data + size, new_data);
            std::fill(new_data + size, new_data + count, value);
        }

        delete[] data;
        data = new_data;
        size = count;
        capacity = new_capacity;
    }

    void reserve(size_t new_cap) {
        if (new_cap <= capacity) return;

        int* new_data = new int[new_cap];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

    void shrink_to_fit() {
        if (size == capacity) return;
        if (empty()) {
            clear();
            return;
        }
        int* new_data = new int[size];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = size;
    }

    int front() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[0];
    }

    int back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[size - 1];
    }

    int get_size() const { return size; }

    bool empty() const { return size == 0; }

    int get_capacity() const { return capacity; }

    void push_back(int value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[capacity];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    void insert(const size_t pos, const int value, const size_t count = 1) {
        if (pos > size) throw std::out_of_range("Index out of range");
        if (count == 0) return;
    
        if (size + count > capacity) reserve(std::max(size + count, capacity * 2));
        for (size_t i = size; i-- > pos;) { data[i + count] = data[i]; }

        std::fill(data + pos, data + pos + count, value);
        size += count;
    }

    int erase(const size_t pos) {
        if (pos >= size) throw std::out_of_range("Index out of range");
    
        int removed = data[pos];
        for (size_t i = pos + 1; i < size; ++i) { data[i - 1] = data[i]; }
        --size;
        return removed;
    }

    const int& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    void print() const {
        if (empty()) {
            std::cout << "Vector is empty\n";
            return;
        }
        for (size_t i = 0; i < size; ++i) { std::cout << data[i] << " "; }
        std::cout << "(" << get_size() << " / " << get_capacity() << ")" << std::endl;
    }

    CustomVector(CustomVector&&) = delete;
    
    CustomVector& operator=(CustomVector&&) = delete;

    ~CustomVector() {
        delete[] data;
    }

private:
    void copy_from_another_vector(const CustomVector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        std::copy(other.data, other.data + size, data);
    }
};

int main() {
    system("cls");

    CustomVector v(10);
    v.print();
    v.clear();
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.print();

    v.insert(2, 5, 3);
    v.print();

    v.erase(1);
    v.print();

    v.reserve(100);
    v.print();

    v.shrink_to_fit();
    v.print();

    v.resize(2);
    v.print();

    std::cout << v.front() << std::endl;
    std::cout << v.back() << std::endl;
    v.print();

    v.clear();
    v.print();

    return 0;
}
