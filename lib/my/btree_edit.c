/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** btree modification functions
*/

#include "my.h"

btree_t *btree_create_node(char *data)
{
    btree_t *node = 0;

    while (!node)
        node = malloc(sizeof(btree_t));
    node->left = 0;
    node->right = 0;
    node->data = my_strdup(data);
    return node;
}

void btree_insert_data(btree_t *root, char *data, int (*cmpf)())
{
    if (!root || !data || !cmpf)
        return;
    btree_t *newnode = btree_create_node(data);

    if (cmpf(data, root->left->data) >= 0) {
        newnode->left = root->left;
        root->left = newnode;
    } else {
        newnode->right = root->right;
        root->right = newnode;
    }
}

size_t btree_level_count(btree_t const *root)
{
    if (!root)
        return 0;

    return 1 + MIN(btree_level_count(root->left), \
                    btree_level_count(root->right));
}

void btree_destroy(btree_t *root)
{
    if (!root)
        return;
    free(root->data);
    btree_destroy(root->left);
    btree_destroy(root->right);
    free(root);
}
