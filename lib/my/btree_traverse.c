/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** btree traversal functions
*/

#include "my.h"

void btree_apply_prefix(btree_t *root, long long int (*applyf)(char *))
{
    if (!root || !applyf)
        return;
    applyf(root->data);
    btree_apply_infix(root->left, applyf);
    btree_apply_infix(root->right, applyf);
}

void btree_apply_infix(btree_t *root, long long int (*applyf)(char *))
{
    if (!root || !applyf)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->data);
    btree_apply_infix(root->right, applyf);
}

void btree_apply_postfix(btree_t *root, long long int (*applyf)(char *))
{
    if (!root || !applyf)
        return;
    btree_apply_postfix(root->left, applyf);
    btree_apply_postfix(root->right, applyf);
    applyf(root->data);
}
