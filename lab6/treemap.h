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
};