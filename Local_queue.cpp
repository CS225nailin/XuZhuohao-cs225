//
// Created by Kejun Wu on 2022/4/8.
//

#include "Local_queue.h"

Local_queue::Local_queue() {
    q = new queue<Person_Node>;    //node that are in the register date
    e = new queue<Person_Node>;    //node that exceeds the ddl
    p = new queue<Person_Node>;    //input
    total = new queue<Person_Node>;  //total node
    return;
}

void Local_queue::deal(int date) //record all the patients, and be ready to pass them to central queue
{
    for(int i = 0; i<p->size(); i++){  //iterate the input queue
        Person_Node *A = new Person_Node;  //give a new space for this node
        *A = p->front();
        if(A->get_regday() == date){  //if that node/person's register day is this date
            p->pop();
            Person_Node *B;   
            B=A;  
            q->push(*B);      //push this node to q queue to give to central
            Person_Node *C;
            C = A;
            total->push(*C);  //store this node to database
        }
        else{
            p->pop();         //if not, give it back to p queue
            Person_Node *B;
            B=A;  
            p->push(*B);
        }
        
    }
    for(int i = 0; i<total->size(); i++){  //iterate the total queue
        Person_Node *A = new Person_Node;
        *A = p->front();
        if(A->lastday == date){  //if that node/person is at the ddl at this date
            p->pop();
            Person_Node *B;
            B=A;  
            e->push(*B);      //push this node to e queue to give to central
            Person_Node *C;
            C = A;
            total->push(*C);  //store this node to database
        }
        else{
            total->pop();         //if not at ddl, give it back to total queue
            Person_Node *B;
            B=A;
            total->push(*B);  
        }
    }
}

queue<Person_Node>* Local_queue::get_p(void)
{
    return p;
}


queue<Person_Node>* Local_queue::get_q(void)
{
    return q;
}

queue<Person_Node>* Local_queue::get_e(void)
{
    return e;
}

queue<Person_Node>* Local_queue::get_total(void)
{
    return total;
}

void Local_queue::search_id(int id){
    Person_Node a[p->size()];
    for (int i = 0; i < p->size(); i++)
    {
        a[i] = p->front();
        p->pop();
    }
    for(int i=0; i < p->size(); i++){
        if(a[i].ID == id){
            return a[i];
        }
    }
}



