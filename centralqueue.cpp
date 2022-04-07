#include "FibHeap.h"

// following are functions of CentralQueue
// constructor, generate the 4 heaps
// fib_heap is for normal people, priority_heap is for those with priority letters,
// waiting_heap is for medium-risk people and withdraw, high_risk_heap is for high-risk people
template <class T> CentralQueue<T>::CentralQueue() {
    fib_heap = new FibHeap<T>;
   
    return;
}



// transfer the data from reg_node to fib_node
template <class T> void CentralQueue<T>::transfer_in(Reg_Node *reg_node, FibNode<T> *fib_node) {//xyxg
    fib_node->origin_node=reg_node;   //record the pointer of the origin personal node
    
    fib_node->appdate=reg_node->appdate;
    fib_node->cureday=reg_node->cureday;
    fib_node->p=reg_node->p;
    fib_node->name=reg_node->name;
    fib_node->ID=reg_node->ID;
    fib_node->profession=reg_node->profession;
    fib_node->risk=reg_node->risk;
	fib_node->age=reg_node->age;
	fib_node->regday=reg_node->regday;
	fib_node->person_state=reg_node->person_state;
	fib_node->withdraw=reg_node->withdraw;
	fib_node->place=reg_node->place;

	fib_node->priority=reg_node->priority;
	fib_node->age_priority=reg_node->age_priority;
/**
	int cureday; // 治疗的日子 预约的日子+1
int appday; // 最晚排上预约的日子
private:
//information to calculate the priority
string p;
string name;
int ID;
int profession;
int risk; //  0 1 2 3 no low midium high
int age;
int regday; // 来登记的日子
//other information
int person_state;// 排队预约治疗 0 1 2 3 
bool withdraw; // 退出+14
string place;
//all kinds of priorities 
int priority;
int age_priority;
**/
    
 
    
}

// transfer the data from fib_node to reg_node
template <class T> void CentralQueue<T>::transfer_out(FibNode<T> *fib_node) {//4.6 am 4.40
   
    Reg_Node *reg_node=fib_node->origin_node;//shengming yige fib_node(personal node)
    reg_node->appdate=fib_node->appdate;
    reg_node->cureday=fib_node->cureday;
    reg_node->p=fib_node->p;
    reg_node->name=fib_node->name;
    reg_node->ID=fib_node->ID;
    reg_node->profession=fib_node->profession;
    reg_node->risk=fib_node->risk;
	reg_node->age=fib_node->age;
	reg_node->regday=fib_node->regday;
	reg_node->person_state=fib_node->person_state;
	reg_node->withdraw=fib_node->withdraw;
	reg_node->place=fib_node->place;

	reg_node->priority=fib_node->priority;
	reg_node->age_priority=fib_node->age_priority;
   
   	 
	

    //need a appoint day
    fib_node->appdate=date;
    
    fib_node->cureday=date+1; // if the person ever withdrew, stat = withdraw
}

// transfer the data from local registry to center
// the input is *Reg_Node. call this function will generate a node in the FibHeap
template <class T> void CentralQueue<T>::record_in(Reg_Node *reg_node) {
    if (reg_node == nullptr) {return;}
    
    FibNode<int> *fib_node = new FibNode<int>(0);
    transfer_in(reg_node, fib_node);
    
   
    fib_node->key = fib_node->priority; // the key in the fib_heap is priority
    fib_heap->insert(fib_node);
   
}

// pop a minimum node. (no) it will return a pointer to the node.
// (no) if there is no node, it will return a NULL pointer

template <class T> Reg_Node *CentralQueue<T>::record_out() {
    FibNode<T> *fib_node = nullptr;
    fib_node = fib_heap->removeMin();
    //XYXG change the heal_day
   
    
    
  
    /**
    if (fib_node == nullptr) {
        Reg_Node *reg_node = nullptr;
        return reg_node;
    }**/
    
    // transfer the data from the fibonacci node to the registry node
    transfer_out(fib_node);
    
    
     /**
    if (fib_node != nullptr) {delete fib_node;} // release the space
    return reg_node; // considering ptr == NULL
    **/
}

// search the node with key and ID . return a pointer to the node; if not find, return NULL
template <class T> void CentralQueue<T>::search_node(Reg_Node *reg_node) {
    FibNode<T> *root_node;
    FibNode<T> *fib_node;
   
    int key, ID;
    ID = reg_node->ID;
   
    
    // search the node in the fib_heap
   
    key = reg_node->priority; // the priority should not change!!
    root_node = fib_heap->min;
    fib_node = fib_heap->id_search(root_node, key, ID);
    
    
    
   
    return fib_node;
}

// the priority change due to profession should be done after this function!!
//no need
template <class T> void CentralQueue<T>::change_profession(Reg_Node *reg_node) {
    FibNode<T> *fib_node = nullptr;
    FibHeap<T> *heap = nullptr;
    // search the node in the heap
    search_node(reg_node, &heap, &fib_node);
    // not find
    if (fib_node == nullptr) {return;}
    
    int old_profession = fib_node->profession;
    fib_node->profession = reg_node->profession;
    
    reg_node->standard_priority = (reg_node->profession - 1) * 28 + (reg_node->age_group - 1) * 4 +fib_node->risk;
    if (old_profession <= fib_node->profession) {return;}
    fib_node->priority = reg_node->standard_priority;
    heap->decrease(fib_node, fib_node->priority);
    return;
}

//no need
template <class T> void CentralQueue<T>::withdraw_heap(Reg_Node *reg_node) {
    FibNode<T> *fib_node = nullptr;
    FibHeap<T> *heap = nullptr;
    // search the node in the heap
    search_node(reg_node, &heap, &fib_node);
    if (fib_node == nullptr) {return;}
    
    // change the status to withdraw, and remove the node
    fib_node->stat = withdraw;
    heap->remove(fib_node);
    return;
}

//no need
template <class T> int CentralQueue<T>::waiting_number() {
    return priority_heap->keyNum + fib_heap->keyNum + waiting_heap->keyNum + high_risk_heap->keyNum;
}
//no need
template <class T> void CentralQueue<T>::build_array(Reg_Node *a, FibNode<T> *root, int n) {
    //int len = waiting_number();
    FibNode<T> *tmp = root;    // temporary node
    //FibNode<T> *p = nullptr;    // target node

    if (root == nullptr)
        return; // protect the stability

    do
    {
        //ptr[n] = &root;
        a[n].name = root->name;
        a[n].profession = root->profession;
        a[n].age_group = root->age_group;
        a[n].risk = root->risk;
        a[n].queTime = date - root->Reg_Day;
        n++;
        
        if (root->child != nullptr){
            build_array(a, root->child, n);
            
            //break;
        }
        tmp = tmp->right;
        if (tmp != nullptr) {
            a[n].name = root->name;
            a[n].profession = root->profession;
            a[n].age_group = root->age_group;
            a[n].risk = root->risk;
            a[n].queTime = date - root->Reg_Day;
            n++;
        }
        
    } while (tmp != root);

    return;
}

template <class T> void CentralQueue<T>::sort(Reg_Node *a) {

    //static FibNode<T> *ptr = new FibNode<T>[len];
    // int len = waiting_number();
    // Reg_Node a[len];
    build_array(a, priority_heap->min, 0);
    build_array(a, fib_heap->min, priority_heap->keyNum);
    build_array(a, waiting_heap->min, priority_heap->keyNum + fib_heap->keyNum);
    build_array(a, high_risk_heap->min, priority_heap->keyNum + fib_heap->keyNum + waiting_heap->keyNum);
    
    return;
}

