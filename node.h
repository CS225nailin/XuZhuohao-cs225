#ifndef node_h
#define node_h
#include <string>
using std::string;
// consider 8 kinds of professions 
// soider,police,fireman,doctor,teacher,official,engineer,waiter 
class Person_Node{
template <class X> friend class CentralQueue; // note the X here
template <class Y> friend class FibHeap;

public:
Person_Node(int day=0,int ID1=0,int age1=0, int risklevel=0, int waiting_max=0 ,string n="Null", string p1="Null",string where="x");
int get_priority();
int get_Person_state(); // 
int get_agepriority();
int get_regday();
int get_hospital();
int lastday;
int stateupdate(); // 更新state
int cureday=1001; // 治疗的日子 预约的日子+1
int appday=1000; // 最晚排上预约的日子
int regday;
void update(Person_Node *patient,int day);


private:
//information to calculate the priority
int hospital;
string name;
int ID;
int profession;
int risk; //  0 1 2 3 no low midium high
int age;

//other information
int person_state;// 排队预约治疗 0 1 2 3 
bool withdraw; // 退出+14
string place;
string p;
//all kinds of priorities 
int priority;
int age_priority;
//useless imformation
/*
string name;
string wechat;
string phonenumber;
string email;
string Birthday;*/
//node connection
Person_Node *person_prev; // brother node
Person_Node *person_next; // brother node
Person_Node *person_down; // kid node 
Person_Node *person_up;   // parent node
};
#endif 
