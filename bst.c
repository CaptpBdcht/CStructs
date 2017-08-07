#include "includes.h"

bst_node *create_node(void *element, size_t size) {
    bst_node *node = malloc(sizeof *node);
    if (!node) perror("bst_insert: node");

    node->data = malloc(size);
    if (!node->data) perror("bst_insert: node->data");
    memcpy(node->data, element, size);
    
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst_node *bst_max(bst_node *node) {
    if (!node) return NULL;
    while (node->right) node = node->right;
    return node;
}

/* end Utils */

boolean bst_is_full(bst_node *node) {
    if (!node) return 1;
    if ((node->left && !node->right) || (node->right && !node->left)) return 0;
    return bst_is_full(node->left) & bst_is_full(node->right);
}

boolean is_bst(bst_node *node, int (*compare)(const void *, const void *)) {
    if (!node) return 1;  
    if (node->left && compare(node->left->data, node->data) >= 0) return 0;
    if (node->right && compare(node->right->data, node->data) < 0) return 0;
    return is_bst(node->left, compare) & is_bst(node->right, compare);
}

boolean bst_contains(bst_node *node, void *element, int (*compare)(const void *, const void *)) {
    if (!node) return 0;
    if (compare(element, node->data) == 0) return 1;
    if (compare(element, node->data) < 0) return bst_contains(node->left, element, compare);
    return bst_contains(node->right, element, compare);
}

unsigned int bst_size(bst_node *node) {
    return (!node) ? 0 : 1 + bst_size(node->left) + bst_size(node->right);
}

unsigned int bst_height(bst_node *node) {
    if (!node || (!node->left && !node->right)) return 0;
    return 1 + maxInt(bst_height(node->left), bst_height(node->right));
}

unsigned int bst_leafs_count(bst_node *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return bst_leafs_count(node->left) + bst_leafs_count(node->right);
}

bst_node *bst_insert(bst_node *node, void *element, size_t size, int (*compare)(const void *, const void *)) {
    if (!node)
        return create_node(element, size);

    if (compare(element, node->data) < 0)
        node->left = bst_insert(node->left, element, size, compare);
    else 
        node->right = bst_insert(node->right, element, size, compare);

    return node;
}

bst_node *bst_remove(bst_node *node, void *element, size_t size, int (*compare)(const void *, const void *)) {
    if (!node) return NULL;

    if (compare(element, node->data) < 0)
        node->left = bst_remove(node->left, element, size, compare);
    else if (compare(element, node->data) > 0)
        node->right = bst_remove(node->right, element, size, compare);
    else if (!node->left)
        return node->right;
    else if (!node->right)
        return node->left;
    else {
        bst_node *max = bst_max(node->left);
        memcpy(node->data, max->data, size);
        memcpy(max->data, element, size);

        node->left = bst_remove(node->left, element, size, compare);
    }

    return node;
}

void bst_reverse(bst_node **node) {
    if (!node || !(*node))
        return;

    bst_node *tmp = (*node)->left;
    (*node)->left = (*node)->right;
    (*node)->right = tmp;

    bst_reverse(&((*node)->left));
    bst_reverse(&((*node)->right));
}

void bst_display_int(bst_node *node, BST_TRAVERSAL traversal_mode) {
    if (!node) return;

    if (traversal_mode == PRE_ORDER) printf("%d ", *(int*)node->data);
    bst_display_int(node->left, traversal_mode);
    if (traversal_mode == IN_ORDER) printf("%d ", *(int*)node->data);
    bst_display_int(node->right, traversal_mode);
    if (traversal_mode == POST_ORDER) printf("%d ", *(int*)node->data);
}
