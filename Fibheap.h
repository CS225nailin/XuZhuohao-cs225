// This file contains the definition of three classes: CentralQueue, FibNode, FibHeap

#ifndef _FIB_HEAP_H
#define _FIB_HEAP_H

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "node.h"


using namespace std;
template <class T> class FibNode;
template <class T> class FibHeap;

// CentralQueue is the class that other files need to call
// central queue contains four FibHeap, and some other functions
template <class T> class CentralQueue {
     // friend void test(); // !!
public:
    CentralQueue();
    
    // these are the functions needed in other files
    //X void set_date(int date); // date = the date of tomorrow. Those people with medium risk or withdraw may released.
    void record_in(Person_Node *reg_node); // transfer the data from local registry to center
    void record_in_reg(Person_Node *reg_node);
    void record_in_app(Person_Node *reg_node);
    void record_in_cure(Person_Node *reg_node);
    void record_out(int date); // pop a "minimum" node
    Person_Node *record_out_reg();
    Person_Node *record_out_app();
    Person_Node *record_out_cure();
    //X void change_profession(Person_Node *reg_node);
  
    //X int waiting_number(); // return the number of people waiting in the heaps
    
    //X void sort(Person_Node *a);
    // void fetch(vector<Person_Node> *a);
    
//private:
    //X int date; // tomorrow's date
    void transfer_in(Person_Node *reg_node, FibNode<T> *fib_node); // transfer the data from reg_node to fib_node
    void transfer_out( FibNode<T> *fib_node); // transfer the data from fib_node to reg_node
    FibNode<T>* search_node(Person_Node *reg_node); // search a node
    
    //X void build_array(Person_Node *a, FibNode<T> *root, int n);
   //  void build_vecotr(vector<Person_Node> *a, FibNode<T> *root, int n);
    
    FibHeap<T> *fib_heap; // the central queue
    FibHeap<T> *reg_heap;
    FibHeap<T> *app_heap;
    FibHeap<T> *cure_heap;
   
};

// FibNode is the node in the Fibonacci Heap
template <class T> class FibNode {
    template <class X> friend class CentralQueue; // note the X here
    template <class Y> friend class FibHeap;
    // friend void test(); // !
public:
	Person_Node *origin_node; // the  pointer of personal node
    T key; // sorting is based on key value
    int degree;
    FibNode<T> *left;
    FibNode<T> *right;
    FibNode<T> *child; // the first child of the node
    FibNode<T> *parent;
    bool marked; // whether the first child is deleted or not

    FibNode(T value):key(value), degree(0), marked(false),
        left(nullptr),right(nullptr),child(nullptr),parent(nullptr) {
        key    = value;
        degree = 0;
        marked = false;
        left   = this;
        right  = this;
        parent = nullptr;
        child  = nullptr;
    }
    
	int cureday; // 娌荤枟鐨勬棩瀛?棰勭害鐨勬棩瀛?1
int appday; // 鏈€鏅氭帓涓婇绾︾殑鏃ュ瓙
private:
//information to calculate the priority
string p;
string name;
int ID;
int profession;
int risk; //  0 1 2 3 no low midium high
int age;
int regday; // 鏉ョ櫥璁扮殑鏃ュ瓙
//other information
int person_state;// 鎺掗槦棰勭害娌荤枟 0 1 2 3 
bool withdraw; // 閫€鍑?14
string place;
//all kinds of priorities 
int priority;
int age_priority;
};

// Fibonacci Heap
template <class T> class FibHeap {
    template <class X> friend class CentralQueue; // note the X here
    // friend void test(); // !!
public:
    FibHeap();
    ~FibHeap();

    void insert(FibNode<T> *node); // insert a node into the root list
    FibNode<T>* removeMin(); // remove the min node from the heap
    void remove(FibNode<T> *node); // remove the node
    FibNode<T>* extractMin(); // remove the node with the minimum key, return a pointer to the node
    
    FibNode<T>* id_search(FibNode<T>* root, T key, int ID); // search the node according to key and id
    void decrease(FibNode<T> *node, T key); // Decrease the value of node node in the Fibonacci heap to key
    
    bool minimum(T *pkey); // Get the minimum key value in the Fibonacci heap and save it to the pkey; success returns true, otherwise returns false.


public:
    int keyNum;         // the number of nodes in the heap
    int maxDegree;      // the maximum degree
    FibNode<T> *min;    // a pointer to the minimum node
    FibNode<T> **cons;    // the memory area of the maximum degree
    
public:
    void removeNode(FibNode<T> *node); // remove node from the double link list
    void addNode(FibNode<T> *node, FibNode<T> *root); // add node to the left of the root
    void link(FibNode<T>* node, FibNode<T>* root); // list node to the root list
    void makeCons(); // Create the space required for consolidate
    void consolidate(); // Merge trees of the same degree left and right in the root-linked table of the Fibonacci heap
    void renewDegree(FibNode<T> *parent, int degree); // update the degree
    void cut(FibNode<T> *node, FibNode<T> *parent); // Strip the node from the parent's child links and make the node a member of the root list
    void cascadingCut(FibNode<T> *node) ; // do cascading cut to the node
};



#endif