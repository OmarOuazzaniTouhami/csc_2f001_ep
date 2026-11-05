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