#include "ArrayList.h"

#include <iostream>

void test_add() {
    std::cout << "TEST ADD" << std::endl;
    ArrayList<int> a;
    std::cout << "List is empty: " << a << std::endl;

    std::cout << "\nAdding 0..." << std::endl;
    std::cout << "Return value of a.add(0): " << (a.add(0) ? "true" : "false") << std::endl;
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nAdding 1..." << std::endl;
    a.add(1);
    std::cout << "New list: " << a << std::endl;
}

void test_add_index() {
    std::cout << "TEST ADD INDEX" << std::endl;
    ArrayList<int> a;
    std::cout << "List is empty: " << a << std::endl;

    std::cout << "\nAdding 0 at index 1 (illegal)..." << std::endl;
    try {
        a.add(1,0);
    } catch (std::exception& e) {
        std::cout << "Exception was caught." << std::endl;
    }
    std::cout << "List is still empty: " << a << std::endl;

    std::cout << "\nAdding 0 at index 0 (legal)... Same effects as first add method." << std::endl;
    a.add(0, 0);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.add(2, 2022)..." << std::endl;
    a.add(2,2022);
    std::cout << "New list: " << a << std::endl;
}

void test_clear() {
    std::cout << "TEST CLEAR" << std::endl;
    ArrayList<int> a;
    std::cout << "List is empty: " << a << std::endl;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.clear()..." << std::endl;
    a.clear();
    std::cout << "New list: " << a << std::endl;
}

void test_contains() {
    std::cout << "TEST CONTAINS" << std::endl;
    ArrayList<int> a;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.contains(1)..." << std::endl;
    std::cout << "Result: " << (a.contains(1) ? "true" : "false") << std::endl;

    std::cout << "\nCalling a.contains(0)..." << std::endl;
    std::cout << "Result: " << (a.contains(0) ? "true" : "false") << std::endl;
}

void test_equals() {
    std::cout << "TEST EQUALS" << std::endl;
    ArrayList<int> a;
    ArrayList<int> b;

    std::cout << "List a is empty: " << a << std::endl;
    std::cout << "List b is empty: " << b << std::endl;
    std::cout << "\nCalling a.equals(b)..." << std::endl;
    std::cout << "Result: " << (a.equals(b) ? "true" : "false") << std::endl;

    std::cout << "\nAdding 1 to list a..." << std::endl;
    a.add(1);
    std::cout << "List a: " << a << std::endl;
    std::cout << "\nCalling a.equals(b)..." << std::endl;
    std::cout << "Result: " << (a.equals(b) ? "true" : "false") << std::endl;
}

void test_index_of() {
    std::cout << "TEST INDEX_OF" << std::endl;
    ArrayList<int> a;

    std::cout << "\nCalling a.index_of(5)..." << std::endl;
    std::cout << "Result: " << a.index_of(5) << std::endl;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.index_of(2)..." << std::endl;
    std::cout << "Result: " << a.index_of(2) << std::endl;
}

void test_is_empty() {
    std::cout << "TEST IS_EMPTY" << std::endl;
    ArrayList<int> a;

    std::cout << "List is empty: " << a << std::endl;
    std::cout << "\nCalling a.is_empty()..." << std::endl;
    std::cout << "Result: " << (a.is_empty() ? "true" : "false") << std::endl;

    std::cout << "\nAdding 1..." << std::endl;
    a.add(1);
    std::cout << "New list: " << a << std::endl;
    std::cout << "\nCalling a.is_empty()..." << std::endl;
    std::cout << "Result: " << (a.is_empty() ? "true" : "false") << std::endl;

}

void test_last_index_of() {
    std::cout << "TEST LAST_INDEX_OF" << std::endl;
    ArrayList<int> a;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.last_index_of(2)..." << std::endl;
    std::cout << "Result: " << a.last_index_of(2) << std::endl;

    std::cout << "\nCalling a.add(2, 2)..." << std::endl;
    a.add(2, 2);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.last_index_of(2)..." << std::endl;
    std::cout << "Result: " << a.last_index_of(2) << std::endl;
}

void test_remove() {
    std::cout << "TEST REMOVE" << std::endl;
    ArrayList<int> a;

    std::cout << "\nCalling a.remove(0) (illegal)..." << std::endl;
    try {
        a.remove(0);
    } catch (std::exception& e) {
        std::cout << "Caught exception" << std::endl;
    }

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.remove(2)..." << std::endl;
    std::cout << "Return value: " << a.remove(2) << std::endl;
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.remove(0)..." << std::endl;
    std::cout << "Return value: " << a.remove(0) << std::endl;
    std::cout << "New list: " << a << std::endl;
}

void test_remove_element() {
    std::cout << "TEST REMOVE_ELEMENT" << std::endl;
    ArrayList<int> a;

    std::cout << "\nNew list: " << a << std::endl;
    std::cout << "Calling a.remove_element(5)..." << std::endl;
    std::cout << "Return value: " << (a.remove_element(5) ? "true" : "false") << std::endl;
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.remove_element(2)..." << std::endl;
    std::cout << "Return value: " << (a.remove_element(2) ? "true" : "false") << std::endl;
    std::cout << "New list: " << a << std::endl;

}

void test_set() {
    std::cout << "TEST SET" << std::endl;
    ArrayList<int> a;

    std::cout << "\nCalling a.set(0, 1) (illegal)..." << std::endl;
    try {
        a.set(0, 1) ;
    } catch (std::exception& e) {
        std::cout << "Caught exception" << std::endl;
    }

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.set(1, 2022)..." << std::endl;
    std::cout << "Return value: " << a.set(1, 2022) << std::endl;
    std::cout << "New list: " << a << std::endl;
}

void test_to_array() {
    std::cout << "TEST TO_ARRAY" << std::endl;
    ArrayList<int> a;

    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a.to_array()..." << std::endl;
    int* temp = a.to_array();

    std::cout << "Printing array contents: ";
    for (int i = 0; i < a.size(); i++) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

void test_operator_get_set() {
    std::cout << "TEST operator[]" << std::endl;
    ArrayList<int> a;
    std::cout << "\nAdding 1, 2, 3..." << std::endl;
    a.add(1);
    a.add(2);
    a.add(3);
    std::cout << "New list: " << a << std::endl;

    std::cout << "\nCalling a[0]..." << std::endl;
    std::cout << a[0] << std::endl;

    std::cout << "\nCalling a[0] = 2022" << std::endl;
    a[0] = 2022;
    std::cout << "New list: " << a << std::endl;
}

void separator() {
    std::cout << "=====================================" << std::endl;
}

int main() {
    separator();
    test_add();

    separator();
    test_add_index();

    separator();
    test_clear();

    separator();
    test_contains();

    separator();
    test_equals();

    separator();
    test_index_of();

    separator();
    test_is_empty();

    separator();
    test_last_index_of();

    separator();
    test_remove();

    separator();
    test_remove_element();

    separator();
    test_set();

    separator();
    test_to_array();

    separator();
    test_operator_get_set();

    return 0;
}
