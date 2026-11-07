#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>

struct list_t;

void error(std::string str) __attribute__((noreturn));

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}

struct node_t {
    virtual node_t* eval() {
        return this;
    }

    virtual node_t* apply(list_t* list) {
        error("apply: this node cannot be applied");
    }

    virtual std::string to_string() {
        return "???";
    }

    virtual list_t* as_list() {
        error("as_list : this node is not a list");
    }
};

struct integer_t : node_t {
    uintptr_t  value;

    integer_t(uintptr_t v) : value {v} {}

    std::string to_string() override {
        return std::to_string(value);
    }
};

struct list_t : node_t {
    node_t** elements;
    size_t nb_elements;
    size_t capacity;

    list_t():
        elements {nullptr},
        nb_elements {0},
        capacity {0} {}

    list_t* as_list() override {
        return this;
    }

    size_t size() {
        return nb_elements;
    }

    node_t* at(size_t i) {
        if (i >= nb_elements) {
            error("i is too big");
        }
        return elements[i];
    }

    void set_at(size_t i, node_t* value) {
        if (i >= nb_elements) {
            error("i is is too big");
        }
        elements[i] = value;
    }

    void append(node_t* value) {
        if (nb_elements == capacity) {
            size_t new_capacity = (capacity == 0) ? 4 : capacity * 2;
            node_t** new_elements = new node_t*[new_capacity];
            for (size_t i = 0; i < nb_elements; i++) {
                new_elements[i] = elements[i];
            }
            capacity = new_capacity;
            elements = new_elements;
        }
        elements[nb_elements] = value;
        nb_elements ++;
    }

    std::string to_string() override {
        std::string result = "(";
        for (size_t i = 0; i < nb_elements; i++) {
            if (i>0) {
                result += " ";
            }
            result += elements[i]->to_string();
        }
        result += ")";
        return result;
    }
};

struct keryword_t {
    std::string id;

    keyword_t(std::string id): id {id} {}

    std::string to_string() {
        return "<"+id+">";
    }
}

int main() {
    list_t* ast = new list_t;

    ast->append(new integer_t { 1 });
    ast->append(new integer_t { 2 });
    ast->append(new integer_t { 3 });

    std::cout << ast->to_string() << std::endl; // should output (1 2 3)
}