#ifndef __BST_H__
#define __BST_H__

#include <functional>

template <typename T> struct Node {
  T element;
  Node *left = nullptr;
  Node *right = nullptr;
  int height = 1;
};

template <typename T> class Bst {
  Node<T> *root;
  int n;

private:
  void deleteAll(Node<T> *node) {
    if (node != nullptr) {
      deleteAll(node->left);
      deleteAll(node->right);
      delete node;
    }
  }
  int height(Node<T> *node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  int getBalance(Node<T> *node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  Node<T>* rightRotate(Node<T> *y) {
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
  }

  Node<T>* leftRotate(Node<T> *x) {
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
  }

  void insert(Node<T> *&node, T elem) {
    if (node == nullptr) {
      node = new Node<T>{.element = elem};
      return;
    }

    if (elem <= node->element)
      insert(node->left, elem);
    else
      insert(node->right, elem);

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Casos de balanceo
    if (balance > 1 && elem <= node->left->element)
      node = rightRotate(node);

    if (balance < -1 && elem > node->right->element)
      node = leftRotate(node);

    if (balance > 1 && elem > node->left->element) {
      node->left = leftRotate(node->left);
      node = rightRotate(node);
    }

    if (balance < -1 && elem <= node->right->element) {
      node->right = rightRotate(node->right);
      node = leftRotate(node);
    }
  }
  void inOrder(Node<T> *node, std::function<void(T)> proc) {
    if (node != nullptr) {
      inOrder(node->left, proc);
      proc(node->element);
      inOrder(node->right, proc);
    }
  }

public:
  Bst() : root(nullptr), n(0) {}
  ~Bst() { deleteAll(root); }

  void insert(T elem) { insert(root, elem); }
  int height() { return height(root); }
  void inOrder(std::function<void(T)> proc) { inOrder(root, proc); }
};

#endif
