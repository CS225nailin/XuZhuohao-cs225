//
// Created by Kejun Wu on 2022/4/8.
//

#include "Local_queue.h"

Local_queue::Local_queue() {
    q = new queue<Person_Node>;
    e = new queue<Person_Node>;
    p = new queue<Person_Node>;
    total = new queue<Person_Node>;
    return;
}

void Local_queue::deal(int date) //process and record the status, date, and time for all the patients in queue.
{
    for(int i = 0; i<p->size(); i++){
        Person_Node temp = p->front();
        if(temp.regday = date){
            q->push(temp);
        }
        if(temp.lastday = date){
            q->pop();
            e->push(temp);
        }
    }
    total.push(temp);
}

queue<Person_Node>* Local_queue::get_p(void)
{
    return p;
}


queue<Person_Node>* Local_queue::get_q(void)
{
    return q;
}

// search the exact person recursively, according to the key and ID; if not find, return NULL
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

int Local_queue::tell(int date, Person_Node node){
    if(node.appday == date){
        return 1;
    }
    q->push(node);
    return 0;

}
