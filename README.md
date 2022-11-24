# Data Structure Project

## STL like Implementation for Advanced Trees in C++

Standard Template Library is one of the most useful libraries in C++.  It is widely used to implement various useful Data Structures like Stack, Queue, Map’s, etc.  It also allows us to use those data structures with many data types like int, double, float and also char and strings

One Key Structure missing from those is Trees. Trees are useful in many use cases: From more efficient searching features to Games, Software and Databases. Despite their usefulness, They are mostly missing from STL.

To solve that issue, Our Team will be implementing STL for Trees. We will be making 4 main libraries for 

Binary Search Trees (BST)

B-Tree

Red Black Tree

Adelson-Velskii Landis Tree (AVL Tree)

To make it actually useful across multiple use cases we have made their implementations using C++ Templates to insure they can support multiple data types.

## Use Guide

The Whole Setup has been Divided into 4 Modules (One for each Tree) To use any module you can just add them to your C++ Folder and you are ready to go

Compatible With: C++ 11 and Further

Supported OS: Windows, Linux, macOS and other Cloud configurations

# Documentation

## Binary Search Tree

```cpp
#include "BST.hpp"

int main(){
  BST<int> tree; // Uses int datatype

  tree.insert(5);  // Insert elements in Tree
  tree.insert(4);
  tree.insert(7);
  tree.insert(10);
  tree.insert(1);
  tree.insert(2);

  tree.postorder(); // PostOrder Traversal
  tree.inorder();   // InOrder Traversal 
  tree.preorder();  // PreOrder Traversal

  std::cout << "Tree size: " << tree.size() << std::endl; // Tells Size of Tree

  BST<char> tee; // Similar Implementation can be done using any Datatype

  tee.insert('z');
  tee.insert('0');
  tee.insert('9');
  tee.insert('a');
  tee.insert('A');
  tee.insert('Z');

  std::cout << "Contains 9? : "<< ((tee.search('9'))? "true" : "false" ) << std::endl;

  tee.postorder();
  tee.inorder();
  tee.preorder();

  std::cout << "Tree size: " << tee.size() << std::endl;
}
```

## B-Tree

```cpp
#include "Btree.hpp"

int main(){
BTree<float> t(4);  // BTree<datatype> obj(order)
	t.insert(1.9);    // Insertion
	t.insert(3.7);
	t.insert(7);
	t.insert(10.11);
	t.insert(11);
	t.insert(13);
	t.insert(14);
  t.insert(16);
  
  t.traverse();    // Display all elements
  t.remove(10.11); // Remove Elements
  cout << endl;
  t.traverse();
  cout << endl;
  cout << t.search(69); // Search For element
}
```

## Adelson-Velskii Landis Tree (AVL Tree)

```cpp
#include "AVLtree.hpp"

int main(){

AVL<char> a;
  a.insert('a');
  a.insert('b');
  a.insert('c');
  a.insert('d');
  a.preorder();
  a.del('b');
  cout << endl << "After Deletion:" << endl;
  a.preorder();
  cout << endl << "After Searching d" << endl;
  a.search('d');
  cout << endl << "After Searching d" << endl;
  a.search('z');
  cout << endl;
  a.postorder();
  cout << endl;
  a.inorder();

AVL<int> b;
  b.insert(5);
  b.insert(6);
  b.insert(7);
  b.insert(8);
  b.preorder();
  b.del(7);
  cout << endl << "After Deletion:" << endl;
  b.preorder();
  cout << endl << "After Searching 6" << endl;
  b.search(6);
  cout << endl << "After Searching 69" << endl;
  b.search(69);
  cout << endl;
  b.postorder();
  cout << endl;
  b.inorder();
}
```

## Red Black Tree

```cpp
#include "RBTree.hpp"  

int main(){
  RBTree<double> bst;
	bst.insert(8.96);
	bst.insert(18.45);
	bst.insert(5.45);
	bst.insert(15.78);
	bst.insert(17.69);
	bst.insert(25.69);
	bst.deleteNode(25.69);
	bst.prettyPrint();
  bst.preorder();
  cout << endl;
  bst.inorder();
  cout << endl;
  bst.postorder();
}
```
