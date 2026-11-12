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
};