#include "edx-io.hpp" 
#include <fstream>
#include <string> 
#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Node{
    Node* left;
    Node* right;
    Node* parent;
    int value;
} Node;

int getCount(Node* node){
    int depth = 1;
    int depthLeft = 0;
    if (node->left != nullptr) depthLeft = getCount(node->left);
    int depthRight = 0;
    if (node->right != nullptr) depthRight = getCount(node->right);
    return depth + depthLeft + depthRight;
}

int deleteNode(Node *node, int value, bool isRight){
    if (node->value == value){
        if (isRight){
            node->parent->right = nullptr;
        } else {
            node->parent->left = nullptr;
        }
        return getCount(node);
    } else{
        if (value < node->value){
            if (node->left != nullptr) return deleteNode(node->left,value, false);
        } else {
            if (node->right != nullptr) return deleteNode(node->right,value, true);
        }

    }
    return 0;
}

int main() {
    int n;
    io >> n;
    Node *nodes = new Node[n];
    for (int i = 0; i < n; ++i) {
        nodes[i].right = nullptr;
        nodes[i].left = nullptr;
        nodes[i].parent = nullptr;
    }
    for (int i = 0; i < n; ++i) {
        int k,l,r;
        io >> k >> l >> r;
        nodes[i].value = k;
        if (l != 0){
            nodes[i].left = &(nodes[l - 1]);
            nodes[l-1].parent = &(nodes[i]);
        }
        if (r != 0){
            nodes[i].right = &(nodes[r - 1]);
            nodes[r-1].parent = &(nodes[i]);
        }
    }
    int n2;
    io >> n2;
    int count = n;
    for (int i = 0; i < n2; ++i) {
        int value;
        io >> value;
        count -= deleteNode(nodes,value,true);
        io << count << '\n';
    }

    return 0;
}