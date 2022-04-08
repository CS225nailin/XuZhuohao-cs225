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
    for(int i = 0; i<this->p->size(); i++){  //iterate the input queue
        Person_Node *A = new Person_Node;  //give a new space for this node
        *A = this->p->front();
        if(A->get_regday() == date){  //if that node/person's register day is this date
            this->p->pop();
            Person_Node *B;   
            B=A;  
            this->q->push(*B);      //push this node to q queue to give to central
            Person_Node *C;
            C=A;
            this->total->push(*C);  //store this node to database
        }
        else{
            this->p->pop();         //if not, give it back to p queue
            Person_Node *B;
            B=A;  
            this->p->push(*B);
        }    
    }
    for(int i = 0; i<this->total->size(); i++){  //iterate the total queue
        Person_Node *A = new Person_Node;
        *A = this->p->front();
        if(A->lastday == date){  //if that node/person is at the ddl at this date
            this->p->pop();
            Person_Node *B;
            B=A;  
            this->e->push(*B);      //push this node to e queue to give to central
            Person_Node *C;
            C = A;
            this->total->push(*C);  //store this node to database
        }
        else{
            this->total->pop();         //if not at ddl, give it back to total queue
            Person_Node *B;
            B=A;
            this->total->push(*B);  
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

void Local_queue::search_id(int id){     //iterate the total queue database, find the node which has the same id 
    for(int i=0; i < this->total->size(); i++){  //iteration
        Person_Node *A;
        *A = this->total->front();     //get the node in the head of the queue
        if(this->total->front().ID == id){
            sameid = A;          //update the sameid person_node*, it is a class pointer
        }
        this->total->pop();           //pop the head node
        this->total->push(*A);        //push it to the back of the queue
    }
}