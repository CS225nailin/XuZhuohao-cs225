#ifndef BTREE_H
#define BTREE_H

#include "node.h"
using namespace std;

static const int m = 3;  
static const int key_max = 2*m-1;
static const int key_min = m - 1;
static const int child_max = key_max + 1;
static const int child_min = key_min + 1;

class BTnode
{
    friend class BTree;
public:
	  BTnode(void);
private:
    bool isleaf;  //Determine whether it is a leaf node
    int keyNum;   //Number of keywords in a node
    BTnode* parent;   //point to the parent node
    BTnode* pchild[child_max];   //subtree pointer array
    Person_Node* keyvalue[key_max];    //key array
};

class BTree
{
public:
    Person_Node* temp_array[10000];
    int temp_size = 0;
    BTree();
    bool _insert(Person_Node* value);  //return 1 if success, 0 if failed
    void SplitBlock(BTnode* node_parent,int child_index,BTnode* node_child);
    void Notfull_insert(BTnode* node,Person_Node* value);
    bool contain(Person_Node* value); //determine if the tree contain this node

    void _printpoint(BTnode* node,int count);
    void printpoint(void);

    bool _delete(Person_Node* value);
    BTnode* _find(BTnode* node,Person_Node* value);
    void MergeBlock(BTnode* node_parent,int child_index);
    Person_Node* getprev(BTnode* node);
    Person_Node* getnext(BTnode* node);
    void BTree_deletebalance(BTnode* node,Person_Node* value);
    void Inorder(BTnode* root);
private:
	BTnode* root;
};
#endif