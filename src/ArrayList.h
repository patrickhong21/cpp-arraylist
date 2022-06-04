#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <array>

template<class T>
class ArrayList {
private:
    T* data;
    int list_size;
    int capacity;
public:
    ArrayList();
    ~ArrayList();
    bool add(const T& element);
    void add(int index, const T& element);
    void clear();
    bool contains(T element) const;
    bool equals(const ArrayList<T>& other) const;
    const T& get(int index) const;
    int index_of(const T& element) const;
    bool is_empty() const;
    int last_index_of(const T& element) const;
    T remove(int index);
    bool remove_element(const T& element);
    T set(int index, T element);
    int size() const;
    T* to_array() const;

    bool operator==(const ArrayList<T>& other) const;
    T& operator[](const int i);
private:
    void reallocate();
    bool array_is_full();
};

#include "ArrayList.tpp"