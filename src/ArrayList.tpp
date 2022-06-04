#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList() {
    data = new T[10];
    capacity = 10;
    list_size = 0;
}

template<class T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template<class T>
bool ArrayList<T>::add(const T& element) {
    if (array_is_full()) {
        reallocate();
    }
    data[list_size++] = element;
    return true;
}

template<class T>
void ArrayList<T>::add(int index, const T& element) {
    // can be equal but not greater
    // if equal, this method has the same effect as the one-arg add method
    if (index > list_size) {
        std::stringstream ss;
        ss << "Index: " << index << ", Size: " << list_size;
        throw std::invalid_argument(ss.str());
    }
    if (index >= 0 && index <= list_size) {
        if (array_is_full()) { // ?
            reallocate();
        }
    }
    // shift to right making space for element
    for (int i = list_size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    list_size++;
}

template<class T>
void ArrayList<T>::clear() {
    delete[] data;
    data = new T[capacity];
    list_size = 0;
}

template<class T>
bool ArrayList<T>::contains(T element) const {
    for (int i = 0; i < list_size; i++) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

template<class T>
bool ArrayList<T>::equals(const ArrayList<T>& other) const {
    return *this == other;
}

template<class T>
const T& ArrayList<T>::get(int index) const {
    if (index >= 0 && index < list_size) {
        return data[index];
    }
    std::stringstream ss;
    ss << "Index " << index << " out of bounds for length " << list_size;
    throw std::invalid_argument(ss.str());
}

template<class T>
int ArrayList<T>::index_of(const T& element) const {
    for (int i = 0; i < list_size; i++) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

template<class T>
bool ArrayList<T>::is_empty() const {
    return list_size == 0;
}

template<class T>
int ArrayList<T>::last_index_of(const T& element) const {
    for (int i = list_size - 1; i >= 0; i--) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

template<class T>
T ArrayList<T>::remove(int index) {
    T removed = data[index];

    if (index >= 0 && index < list_size) {
        for (int i = index; i < list_size; i++) {
            data[i] = data[i + 1];
        }
        list_size--;
        return removed;
    }

    std::stringstream ss;
    ss << "Index " << index << " out of bounds for length " << list_size;
    throw std::invalid_argument(ss.str());
}

template<class T>
bool ArrayList<T>::remove_element(const T& element) {
    for (int i = 0; i < list_size; i++) {
        if (data[i] == element) {
            remove(i);
            return true;
        }
    }
    return false;
}

template<class T>
T ArrayList<T>::set(int index, T element) {
    T old_element;
    if (index >= 0 && index < list_size) {
        old_element = data[index];
        data[index] = element;
        return old_element;
    }
    std::stringstream ss;
    ss << "Index " << index << " out of bounds for length " << list_size;
    throw std::invalid_argument(ss.str());
}

template<class T>
int ArrayList<T>::size() const {
    return list_size;
}

template<class T>
T* ArrayList<T>::to_array() const {
    T* temp = new T[list_size];
    for (int i = 0; i < list_size; i++) {
        temp[i] = data[i];
    }
    return temp;
}

template<class T>
void ArrayList<T>::reallocate() {
    capacity = (capacity * 3) / 2 + 1;
    T* temp = new T[capacity];

    for (int i = 0; i < list_size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
}

template<class T>
bool ArrayList<T>::array_is_full() {
    return list_size == capacity;
}

template<class T>
bool ArrayList<T>::operator==(const ArrayList<T> &other) const {
    if (list_size != other.list_size) {
        return false;
    }
    for (int i = 0; i < list_size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

// this can get and set
template<class T>
T& ArrayList<T>::operator[](const int index) {
    if (index >= 0 && index < list_size) {
        return data[index];
    }
    std::stringstream ss;
    ss << "Index " << index << " out of bounds for length " << list_size;
    throw std::invalid_argument(ss.str());
}

template<class T>
std::ostream& operator<<(std::ostream& ostr, const ArrayList<T>& lst) {
    ostr << "[";
    for (int i = 0; i < lst.size(); i++) {
        ostr << lst.get(i);
        if (i != (lst.size() - 1)) {
            ostr << ", ";
        }
    }
    ostr << "]";
    return ostr;
}
