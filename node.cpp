#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "node.h"
using std::cout;
using std::cin;
using std::string;
Person_Node::Person_Node(int day,int ID1,int age1, int risklevel, int waiting_max,string n,string p1,string where){
      regday=day;
      ID=ID1;
      age=age1;
      risk=risklevel;
      name=n;
      appday=regday+waiting_max;
      place=where;
      p=p1;
      priority=get_priority();
      age_priority=get_agepriority();
      person_state=0;
      withdraw=false;//如果二次出现且没有被治疗过withdraw=TRUE 表示已经
}
Person_Node::get_priority(){
    //优先级规则 职业，年龄（老的优先），risk
    int agl;
    if(age<=12){
        agl=1;
    }else if(age>12 && age<=18){
        agl=2;
    }else if(age<=35 && age>18){
        agl=3;
    }else if(age<=50 && age>35){
        agl=4;
    }else if(age<=65 && age>50){
        agl=5;
    }else if(age<=75 && age>65){
        agl=6;
    }else{
        agl=7;
    }
    // soider,police,fireman,doctor,teacher,official,engineer,waiter 
    int pl; 
    if(p=="waiter"){
        pl=1;
    }
    else if(p=="engineer"){
        pl=2;
    }else if(p=="official"){
        pl=3;
    }else if(p=="teacher"){
        pl=4;
    }else if(p=="doctor"){
        pl=5;
    }else if(p=="fireman"){
        pl=6;
    }else if(p=="police"){
        pl=7;
    }else if(p=="soilder"){
        pl=8;
    }
    int p=10*pl+agl;
    p=-p;
    if(risk==3){
        p+=90;
    }
    return p;
}
Person_Node::get_agepriority(){
     int agl;
    if(age<=12){
        agl=1;
    }else if(age>12 && age<=18){
        agl=2;
    }else if(age<=35 && age>18){
        agl=3;
    }else if(age<=50 && age>35){
        agl=4;
    }else if(age<=65 && age>50){
        agl=5;
    }else if(age<=75 && age>65){
        agl=6;
    }else{
        agl=7;
    }
    return agl;
}
Person_Node::get_regday(){
    return regday;
}
Person_Node::get_hospital(){
    if (place=="A"|| place=="B"){
        hospital=1;
    }else if(place=="C"|| place=="D"){
        hospital=2;
    }else if(place=="E"){
        hospital=3;
    }else if(place=="F"){
        hospital=4;
    }
    return hospital;
}
/*template<class T>Person_Node<T>::lastday(int date){
    return date+regtime;
}*/