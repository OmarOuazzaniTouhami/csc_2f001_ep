template <class K, class V>
struct treemap_t {
    struct pair_t {
        K key;
        V value;
    };

    struct node_t : pair_t {
        node_t* parent;
        node_t* left;
        node_t* right;

        node_t(node_t* parent) : 
            parent {parent},
            left {nullptr},
            right {nullptr} {}
    };

    node_t* root;
    treemap_t() : root{nullptr} {}

    node_t* lookup(node_t** pcur, node_t* parent, const K* key, bool create) {
        if (*pcur == nullptr) {
            if (!create) {
                return nullptr;
            }
            *pcur = new node_t{parent};
            (*pcur)->key = *key;
        }
        node_t* cur = *pcur;
        if (*key == cur->key) {
            return cur;
        } else if (*key < cur->key) {
            return lookup(&cur->left, cur, key, create);
        } else {
            return lookup(&cur->right, cur, key, create);
        }
    }

    void set_at(const K key, const V value) {
        node_t* node = lookup(&root, nullptr, &key, true);
        node->value = value;
    }

    V at(const K key) {
        node_t* node = lookup(&root, nullptr, &key, false);
        if (node == nullptr) {
            std::cout << "The Node does not exists" << std::endl;
            exit(1);
        }
        return node->value;
    }

    void display_r(node_t* cur, std::string prefix) {
        if (cur == nullptr) {
            return;
        }
        display_r(cur->left, prefix + "  ");
        std::cout << prefix << "(" << cur->key << ", " << cur->value << ")" << std::endl;
        display_r(cur->right, prefix + "  ");
    }

    void display() {
        display_r(root, "");
    }

    struct iterator_t {
        node_t* cur;

        iterator_t(node_t* root): cur {root} {
            if (cur != nullptr) {
                while (cur->left != nullptr) {
                    cur = cur->left;
            }
            }
        }

        void next() {
            if (cur->right != nullptr) {
                cur = cur->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
            } else {
                while (cur->parent != nullptr && cur == cur->parent->right) {
                    cur = cur->parent;
                }
                cur = cur->parent;
            }
        }
    };

};
