#ifndef BST_H
#define BST_H

typedef struct s_bst_node {
    void *data;
    struct s_bst_node *left;
    struct s_bst_node *right;
} bst_node;

typedef enum {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
} BST_TRAVERSAL;

boolean bst_is_full(bst_node *);
boolean is_bst(bst_node *, int (*compare)(const void *, const void *));
boolean bst_contains(bst_node *, void *, int (*compare)(const void *, const void *));

unsigned int bst_size(bst_node *);
unsigned int bst_height(bst_node *);
unsigned int bst_leafs_count(bst_node *);

bst_node *bst_insert(bst_node *, void *, size_t, int (*compare)(const void *, const void *));
bst_node *bst_remove(bst_node *, void *, size_t, int (*compare)(const void *, const void *));
void bst_reverse(bst_node **);

void bst_display_int(bst_node *, BST_TRAVERSAL);

#endif