//
// Created by Kejun Wu on 2022/4/8.
//

#include <iostream>
#include <queue>
#include "node.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Local_queue
{
private:
    queue<Person_Node>* q; // fifo queue.
    queue<Person_Node>* p; // database queue
    queue<Person_Node>* total;
    queue<Person_Node>* e;
    int FIFO();
public:
    void deal(int date); //process and record the status, date, and time for all the patients in queue.
    void agesort(void);
    void search_id(int id);
    int tell(int date, Person_Node node);
    /* queue库里的：
    q.empty()       //若队列为空 返回true 否则返回false
    q.size()        //返回元素个数
    q.pop()         //删除队首元素(不返回值)
    q.front()       //返回FIFO队列中队首元素的值(不删除元素)
    q.back()        //返回FIFO队列中队尾元素的值(不删除元素)
    q.push()        //在FIFO队列的队尾压入一个新的元素
    */
    queue<Person_Node>* get_q();
    queue<Person_Node>* get_p();
};
