#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

template <class T>
struct avlnode
{
    T key;
    int height;
    avlnode *left;
    avlnode *right;
    avlnode *parent;
};

template <class T>
class AVL
{
    public:
    avlnode<T> *root;
    //Constructor
    AVL()
    {
        root=NULL;
    }
    int height(avlnode<T> *t)
    {
        return t == NULL ? -1 : t->height;
    }
    void LL(avlnode<T> *&t)
    {
        avlnode<T> *u=t->left;
        t->left=u->right;
        u->right=t;
        t->height=max(height(t->left),height(t->right))+1;
        u->height=max(height(u->left),height(u->right))+1;
        t=u;
    }
    void RR(avlnode<T> *&t)
    {
        avlnode<T> *u=t->right;
        t->right=u->left;
        u->left=t;
        t->height=max(height(t->left),height(t->right))+1;
        u->height=max(height(u->left),height(u->right))+1;
        t=u;
    }
    void LR(avlnode<T> *&t)
    {
        RR(t->left);
        LL(t);
    }
    void RL(avlnode<T> *&t)
    {
        LL(t->right);
        RR(t);
    }
    void insert(avlnode<T> *&t,T x)
    {
        if(t==NULL)
        {
            t=new avlnode<T>;
            t->key=x;
            t->height=0;
            t->left=NULL;
            t->right=NULL;
            t->parent=NULL;
        }
        else
        {
            if(x<t->key)
            {
                insert(t->left,x);
                t->left->parent=t;
                if(height(t->left)-height(t->right)==2)
                {
                    if(x<t->left->key)
                    {
                        LL(t);
                    }
                    else
                    {
                        LR(t);
                    }
                }
            }
            else if(x>t->key)
            {
                insert(t->right,x);
                t->right->parent=t;
                if(height(t->right)-height(t->left)==2)
                {
                    if(x>t->right->key)
                    {
                        RR(t);
                    }
                    else
                    {
                        RL(t);
                    }
                }
            }
            else
            {
                cout<<"\nThe Key is already present\n";
            }
        }
        t->height=max(height(t->left),height(t->right))+1;
    }
    void insert(T x)
    {
        insert(root,x);
    }
    avlnode<T>* inorder_suc(avlnode<T> *t)
    {
        avlnode<T> *p;
        while(t->left!=NULL)
        {
            t=t->left;
        }
        return t;
    }
    void del(avlnode<T> *&t,T x)
    {
        if(t==NULL)
        {
            cout<<"\nElement to be deleted is not present\n";
        }
        else if(x<t->key)
        {
            del(t->left,x);
        }
        else if(x>t->key)
        {
            del(t->right,x);
        }
        else if(t->left!=NULL && t->right!=NULL)
        {
            t->key=inorder_suc(t->right)->key;
            del(t->right,t->key);
        }
        else
        {
            avlnode<T> *u=t;
            if(t->left==NULL)
            {
                t=t->right;
            }
            else if(t->right==NULL)
            {
                t=t->left;
            }
            delete u;
        }
    }
    void del(T x)
    {
        del(root,x);
    }
    avlnode<T>* search(avlnode<T> *t,T x)
    {
        if(t==NULL)
        {
            cout << "Element Not Found";
            return NULL;
        }
        else if(x<t->key)
        {
            return search(t->left,x);
        }
        else if(x>t->key)
        {
            return search(t->right,x);
        }
        else
        {
            cout << "Element Found";
            return t;
        }
    }
    avlnode<T>* search(T x)
    {
        return search(root,x);
    }
    void inorder(avlnode<T> *t)
    {
        if(t==NULL)
        {
            return;
        }
        inorder(t->left);
        cout<<" "<<t->key<<" ";
        inorder(t->right);
    }
    void inorder()
    {
        inorder(root);
        cout<<endl;
    }

    void preorder(avlnode<T> *t)
    {
        if(t==NULL)
        {
            return;
        }
        cout<<" "<<t->key<<" ";
        preorder(t->left);
        preorder(t->right);
    }
    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

    void postorder(avlnode<T> *t)
    {
        if(t==NULL)
        {
            return;
        }
        postorder(t->left);
        postorder(t->right);
        cout<<" "<<t->key<<" ";
    }
   void postorder()
    {
        postorder(root);
        cout<<endl;
    }
};

