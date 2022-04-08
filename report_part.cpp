#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "node.cpp"
#include "Local_queue.h"
#include "centralqueue.cpp"

void print_original(Local_queue* Local, int day,  CentralQueue<int>* Central);
void print_proffession_sorted();
void print_age_sorted();
void print_name_sorted()


void report_weekly_monthly(int day, Local_queue* Local, CentralQueue<int>* Central)
{
    if (day%7 == 0)
    {
        int sort_selection;
        // First of all, we ask the controller to choose which kind of sort for the report
        // he wants.

        cout<<"It is the time for making weekly report, Please choose the mode"<<endl;
        cout<<"1 : not sort at all"<<endl;
        cout<<"2 : sort by profession category"<<endl;
        cout<<"3 : sort by age group"<<endl;
        cout<<"4 : sort by name"<<endl;

        cin>>sort_selection;
        switch (sort_selection)
        {
        case 1:
            print_original(Local,day,Central);
            break;
        case 2:
            print_proffession_sorted();
            break;
        case 3:
            print_age_sorted();
            break;
        case 4:
            print_name_sorted();
            break;
        default: cout<<"Wrong input! Please restart the program and choose what you want again!";
            break;
        }
    }
    else
    {
        return;
    }
}
int i;
        void print_original(Local_queue* Local, int day,  CentralQueue<int>* Central)
        {
            Person_Node *cured;
            int counter;
            cout<<"The list that peopcole have been treated"<<endl;
            for(i = 0; i < Local->get_total()->size(); i++)
            {
                int cured_day = Local->get_total()->front().cureday;
                cured = &(Local->get_total()->front());
                Local->get_total()->push(Local->get_total()->front());
                Local->get_total()->pop();
                if(day - 7 <= cured_day <= day)
                {
                    Central->record_in_cure(cured);
                    counter++;
                }
            }
            for(i = 0; i < counter; i++)
            {
                cured = Central->record_out_cure();
                cout<<cured->profession<<"  "<<cured->age<<"  "<<cured->risk<<"  "<<day - cured->regday<<endl;
            }
            Person_Node *registed;
            counter = 0;
            cout<<"The list that people have registered"<<endl;
            for(i = 0; i < Local->get_total()->size(); i++)
            {
                int registed_day = Local->get_total()->front().regday;
                registed = &(Local->get_total()->front());
                Local->get_total()->push(Local->get_total()->front());
                Local->get_total()->pop();
                if(day - 7 <= registed_day <= day)
                {
                    Central->record_in_reg(registed);
                    counter++;
                }
            }
            for(i = 0; i < counter; i++)
            {
                registed = Central->record_out_reg();
                cout<<registed->profession<<"  "<<registed->age<<"  "<<registed->risk<<"  "<<day - registed->regday<<endl;
            }

            counter = 0;
            Person_Node* appointed;
            cout<<"The list that people is queueing"<<endl;
            for(i = 0; i < Local->get_total()->size(); i++)
            {
                int appointed_day = Local->get_total()->front().appday;
                appointed = &(Local->get_total()->front());
                Local->get_total()->push(Local->get_total()->front());
                Local->get_total()->pop();
                if(day - 7 <= appointed_day <= day)
                {
                    Central->record_in_reg(appointed);
                    counter++;
                }
            }
            for(i = 0; i < counter; i++)
            {
                registed = Central->record_out_app();
                cout<<appointed->profession<<"  "<<appointed->age<<"  "<<appointed->risk<<"  "<<day - appointed->regday<<endl;
            }
        }

        void print_proffession_sorted()
        {
cout<<"暂不支持";}
/*
            //用斐波那契堆排序
            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }
            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }
            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }
            
            
        }
*/
        void print_age_sorted()
        {
cout<<"暂不支持";}
/*
            //用斐波那契堆排序
            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }
            cout<<"The list that people have registered"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }
            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }
        }
*/
        void print_name_sorted()
        {
            cout<<"暂不支持";}
            /*
            //用姓名排序
            
            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }
            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }
            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }
            
        }
int cureday; // 治疗的日子 预约的日子+1
int appday; // 最晚排上预约的日子
int regday; // 来登记的日子
// day >= cureday 得到结论 cured
// day == appday 得到结论 已注册
//  REGDAY <=DAY < APPDAY => 排队说
*/