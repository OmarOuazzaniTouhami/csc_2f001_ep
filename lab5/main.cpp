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

struct list_t;
struct frame_t;

struct node_t {
    virtual node_t* eval(frame_t* frame) {
        return this;
    }

    virtual node_t* apply(list_t* list, frame_t* frame) {
        error("apply: this node cannot be applied");
    }

    virtual std::string to_string() {
        return "???";
    }

    virtual list_t* as_list() {
        error("as_list : this node is not a list");
    }

    virtual uintptr_t int_value() {
        error("int_value: this node is not an integer");
    }

    virtual bool is(std::string id) {
        return false;
    }
};

struct integer_t : node_t {
    uintptr_t  value;

    integer_t(uintptr_t v) : value {v} {}

    std::string to_string() {
        return std::to_string(value);
    }

    uintptr_t int_value() override {
        return value;
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

    node_t* eval(frame_t* frame) override {
        if (nb_elements == 0)
            error("eval: cannot evaluate an empty list");
        return elements[0]->eval(frame)->apply(this, frame);
    }
};

struct keyword_t : node_t {
    std::string id;

    keyword_t(std::string id): id {id} {}

    std::string to_string() {
        return "<"+id+">";
    }
};

struct add_t : keyword_t {
    node_t* apply(list_t* list, frame_t* frame) override {
        uintptr_t sum = 0;
        for (size_t i = 1; i < list->size(); i++)
            sum += list->at(i)->eval(frame)->int_value();
        return new integer_t { sum };
    }

    add_t(): keyword_t("+") {}
};

struct symbol_t : node_t {
    std::string id;

    bool is(std::string id) {
        if (this->id == id) {
            return true;
        }
        return false;
    }

    std::string to_string() {
        return id;
    }

    symbol_t(std::string id) : id {id} {}
};

struct frame_t : list_t {
    void set(node_t* sym, node_t* value) {
        for (size_t i = 0; i < size(); i++) {
            list_t* entry = at(i)->as_list();
            if (sym->is(entry->at(0)->to_string())) {
                entry->set_at(1, value);
                return;
            }
        }
        list_t* entry = new list_t;
        entry->append(sym);
        entry->append(value);
        append(entry);
    }

    node_t* get(node_t* sym) {
        for (size_t i = 0; i < size(); i++) {
            list_t* entry = at(i)->as_list();
            if (sym->is(entry->at(0)->to_string()))
                return entry->at(1);
        }
        error("get: unknown symbol " + sym->to_string());
    }
};


int main() {
    frame_t* frame = new frame_t;

    // (<+> 1 2)
    list_t* inner = new list_t;
    inner->append(new add_t);
    inner->append(new integer_t { 1 });
    inner->append(new integer_t { 2 });

    // (<+> (<+> 1 2) 3)
    list_t* ast = new list_t;
    ast->append(new add_t);
    ast->append(inner);
    ast->append(new integer_t { 3 });

    std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
    return 0;
}
