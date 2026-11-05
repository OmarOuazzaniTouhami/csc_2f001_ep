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
};

int main() {
    node_t* ast = new integer_t { 3 };
    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
}