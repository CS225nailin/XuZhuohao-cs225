#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Local_queue.cpp"
#include "Fibheap.cpp"
#include "node.cpp"
#include "centralqueue.cpp"
using std::string;
using std::cout;
using namespace std;
void print_original(Local_queue* Local, int day,  CentralQueue<int>* Central);
void print_proffession_sorted();
void print_age_sorted();
void print_name_sorted();

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
            for(i = 0; i < (Local->get_total())->size(); i++)
            {
                int cured_day = (Local->get_total())->front().cureday;
                cured = &((Local->get_total())->front());
                (Local->get_total())->push((Local->get_total())->front());
                (Local->get_total())->pop();
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
            for(i = 0; i < (Local->get_total())->size(); i++)
            {
                int registed_day = (Local->get_total())->front().regday;
                registed = &((Local->get_total())->front());
                (Local->get_total())->push((Local->get_total())->front());
                (Local->get_total())->pop();
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
            for(i = 0; i < (Local->get_total())->size(); i++)
            {
                int appointed_day = (Local->get_total())->front().appday;
                appointed = &(Local->get_total()->front());
                (Local->get_total())->push((Local->get_total())->front());
                (Local->get_total())->pop();
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
int main(){
    CentralQueue<int>* Central = new CentralQueue<int>;
    Local_queue* Local = new Local_queue;
    
    int day[12]={1,1,1,1,1,2,2,2,3,3,3,3};
    int ID[12]={320011,320012,320013,320014,1,2,3,4,5,6,7,8};
    int age[12]={18,19,50,20,18,19,50,20,18,19,50,20};
    int risk[12]={0,1,1,1,0,1,1,1,0,1,1,1};
    int waitmax[12]={3,6,9,4,3,6,9,4,3,6,9,4};
    string name[12]={"czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa"};
    string pro[12]={"teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider"};
    string where[12]={"A","C","B","C","A","C","B","C","A","C","B","C"};
    int numitems =0,date =1;
    while(date<=30){
        cout<<"----------today is day"<<date<<"---------"<<endl;
        while(day[numitems]==date){
            cout<<Local->get_total()->size()<<endl;
            Person_Node *sss=Local->search_id(ID[numitems]);
            
        if( sss!= NULL)
        {cout<<"up2"<<endl;
            sss->update(sss,date);
            cout<<"update"<<endl;
        }
        else
        {    cout<<"input2"<<endl;
            Person_Node *pat=new Person_Node(day[numitems],ID[numitems],age[numitems],risk[numitems],waitmax[numitems],name[numitems],pro[numitems],where[numitems]);
            cout<<"input1"<<endl;
            Local->get_p()->push(*pat);//把person_node 加入local_p
            cout<<"input"<<endl;
        }
        numitems++;
        cout<<numitems<<endl;
                   
        }
        Local->deal(date);
        cout<<"deal"<<endl;
        for(int i=0;i<Local->get_q()->size();i++){
            
            Person_Node* somebody=&(Local->get_q()->front());
            
            Local->get_q()->pop();
            
           Central->record_in(somebody);
            
            
        }
        
        int counter=0;
        int max=1;// 记得改成80
        
        for(int i=0;i<Local->get_e()->size();i++){//e有问题
            Person_Node* someone=&(Local->get_e()->front());
            Local->get_e()->pop();
            Central->fib_heap-> decrease(Central->search_node(someone),-100);
            Central->record_out(date);
            counter++;
           
        }
        //find must be apptoday;
        
        for(int i=0;i<max-counter;i++){
            
            Central->record_out(date);
            cout<<"record_out"<<endl;
        }
        int operation;
        int operation2;
        
        cout<<"Do you want to withdraw? 1 for yes and others for no"<<endl;
        cin>>operation;
        while(operation == 1){
           
            cout<<"Please enter the id";
            cin>>operation2;
            FibNode<int> *anyone;
            Person_Node *anybody=Local->search_id(operation2);
            if(anybody == NULL){
                cout<<"You enter an id that does not exist"<<endl;
                cout<<"Do you still want to withdraw some people? 1 for yes and others for no"<<endl;
                cin>>operation;
                continue;
                
            }
            anybody->withdraw=true;
            anybody->regday=-1;

            anyone=Central->search_node(anybody); 
            if(anyone==NULL){
                cout<<"Do you still want to withdraw some people? 1 for yes and others for no"<<endl;
                cin>>operation;
                continue;
                }
            Central->fib_heap->removeNode(anyone);
            
            cout<<"Do you still want to withdraw some people? 1 for yes and others for no"<<endl;
            cin>>operation;
        }
        
        //print "是否withdraw 0 for yes 1 for no"
        //if 0 go on
        //if 1 ,enter id
        //check if this id in central , if so , withdraw ,else print "not found"

        report_weekly_monthly(date,Local,Central);
        date++;
    }
    return 0;
}
