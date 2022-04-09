#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include "Fibheap.cpp"
#include "node.cpp"
#include "centralqueue.cpp"
#include "LinkedList.cpp"


using std::string;
using std::cout;
using namespace std;
void print_original(LinkedList* Local, int day,  CentralQueue<int>* Central);
void print_proffession_sorted();
void print_age_sorted();
void print_name_sorted();

void report_weekly_monthly(int day, LinkedList* Local, CentralQueue<int>* Central)
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
        }
        return;
    }
    else
    {
        return;
    }
}
    int i;
    void print_original(LinkedList* Local, int day,  CentralQueue<int>* Central)
        {
            cout<<"The list that peopcole have been treated"<<endl;
            
            
            int counter = 0;
            Node* temp = Local->head;
            Person_Node* temp_out;
            for(i = 0; i < Local->numb; i++)
            {
                int cured_day = temp->data->cureday;
            
                if(day - 7 <= cured_day&&cured_day <= day)
                {
                    Central->record_in_cure(temp->data);
                    counter++;
                }
            temp = temp->next;
            }
            
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_cure();
                cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->ID<<"  "<<temp_out->cureday<<endl;
            }



            counter = 0;
            cout<<"The list that people have registered"<<endl;            
            for(i = 0; i < Local->numb; i++)
            {
                temp = Local->head;
                int registed_day = temp->data->regday;

                if(day - 7 <= registed_day&&registed_day <= day)
                {
                    Central->record_in_reg(temp->data);
                    counter++;
                }
                temp= temp->next;
            }
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_reg();
                cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->risk<<"  "<<day - temp_out->regday<<endl;
            }

            counter = 0;
            cout<<"The list that people is queueing"<<endl;
            for(i = 0; i < Local->numb; i++)
            {
                temp = Local->head;
                int appointed_day = temp->data->appday;

                if(day - 7 <= appointed_day&&appointed_day <= day)
                {
                    Central->record_in_reg(temp->data);
                    counter++;
                }
                temp = temp->next;
            }
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_app();
                cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->risk<<"  "<<day - temp_out->regday<<endl;
            }
            return;
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
    LinkedList* Local = new LinkedList;
    
    int day[90]={1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int ID[90]={1,2,3,4,5,6,7,8,9,10,11,12,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int age[90]={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int risk[90]={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1};
    int waitmax[90]={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    string name[90]={"czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa"};
    string pro[90]={"teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider"};
    string where[90]={"A","C","B","C","A","C","B","C","A","C","B","C","C","A","C","B","C","A","C","B","C","A","C","B","C","C","A","C","B","C","A","C","B","C","A","C","B","C","C","A","C","B","C","A","C","B","C","A","C","B","C","C","A","C","B","C","A","C","B","C","A","C","B","C","C","A","C","B","C","A","C","B","C","A","C","B","C","C"};
    int numitems =0,date =1;
    Person_Node* test;
    while(date<=30){
        cout<<"----------today is day"<<date<<"---------"<<endl;
        for(int numitems=0;numitems<90;numitems++){
        	cout<<"numitems =="<<numitems<<endl;
	
      
        if(day[numitems]==date){
           	     Person_Node *sss=Local->search(ID[numitems]);
            
	        if( sss!= NULL)
	        {
	            sss->update(sss,date);
	            cout<<"update"<<endl;
	            
	        }
	        else  
	        {   
	           	Person_Node *pat=new Person_Node(day[numitems],ID[numitems],age[numitems],risk[numitems],waitmax[numitems],name[numitems],pro[numitems],where[numitems]);
	           
	            Local->insert(pat);//把person_node 加入local_p
	          Local->size_report();
              Local->display();
	           
	            
			}
            
            
           
        }
        
        
                   
     }
        LinkedList* today_people=Local->This_day(date);
        today_people->size_report();
        today_people->display();
        cout<<"get somebody3"<<endl;

        Node* somebody = today_people->head;
        cout<<"get somebody"<<endl;
        
        while(somebody != NULL){
        	cout<<"get somebody2"<<endl;
            
           Central->record_in(somebody->data);
           cout<<"record_in"<<endl;
           somebody = somebody -> next;
            cout<<"getnext"<<endl;
            
        }
        
        int counter=0;
        int max=3;// 记得改成80

        LinkedList* ddl_people=Local->DDL_day(date);
        Node* someone=ddl_people->head;
        
        for(int i=0;i<ddl_people->numb;i++){//e有问题
            
            Central->fib_heap-> decrease(Central->search_node(someone->data),-100);
            Central->record_out(date);
            someone = someone -> next;
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
            Person_Node *anybody=Local->search(operation2);
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
