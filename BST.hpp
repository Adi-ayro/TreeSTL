#include <iostream>

template <class T>
class BST
{
  struct node{
    T value;
    struct node* right;
    struct node* left;
  };

  public:
    BST();
    ~BST();
    void insert(T val);
    void preorder();
    void inorder();
    void postorder();
    int size();
    bool search(T val);
  
  private:
    struct node* root;
    int treeSize;
    void insert(struct node** node, T val);
    bool search(struct node* node, T val);
    void preorder(struct node* node);
    void inorder(struct node* node);
    void postorder(struct node* node);
    void deleteTree(struct node* node);
};

template <class T>
BST<T>::BST(){
  this->root = NULL;
  this->treeSize = 0;
}

template <class T>
BST<T>::~BST(){
  deleteTree(this->root);
}

template <class T>
int BST<T>::size(){
  return this->treeSize;
}

template <class T>
  void BST<T>::insert(T val){
  insert(&(this->root), val);
}

template <class T>
void BST<T>::insert(struct node** node, T val){

  if(*node == NULL) {
  struct node* tmp = new struct node;
  tmp->value = val;
  tmp->left=NULL;
  tmp->right = NULL;
  *node = tmp;
  
  this->treeSize++;
  }else{
  if(val > (*node)->value){
    insert(&(*node)->right, val);
  }else{
    insert(&(*node)->left, val);
  }
  }
}

template <class T>
void BST<T>::inorder(){
  inorder(this->root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::inorder(struct node* node){
  if(node != NULL){
    inorder(node->left);
    std::cout << node->value << ", ";
    inorder(node->right);
  }
}

template <class T>
void BST<T>::preorder(){
  preorder(this->root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::preorder(struct node* node){
  if(node != NULL) {
    std::cout << node->value << ", ";
    inorder(node->left);
    inorder(node->right);
  }
}

template <class T>
void BST<T>::postorder(){
  postorder(this->root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::postorder(struct node* node){
  if(node != NULL){
    inorder(node->left);
    inorder(node->right);
    std::cout << node->value << ", ";
  }
}


template <class T>
void BST<T>::deleteTree(struct node* node){
  if(node != NULL){
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

template <class T>
bool BST<T>::search(T val){
  return search(this->root, val);
}

template <class T>
bool BST<T>::search(struct node* node, T val){
  if(node == NULL){
    return false;
  }else{
    if(val == node->value){
     return true;
    }
    if(val > node->value){
      return search(node->right, val);
    }else{
      return search(node->left, val);
    }
  }

}
