#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "Fibheap.cpp"
#include "node.cpp"
#include "centralqueue.cpp"
#include "LinkedList.cpp"
#include "Btree.cpp"
#include "B+_node.cpp"
#include "B+tree.cpp"

#include "report.cpp"




using std::string;
using std::cout;
using namespace std;
void print_original();
void print_proffession_sorted();
void print_age_sorted(LinkedList* Local, int day,  CentralQueue<int>* Central);
void print_name_sorted();

void report_weekly_monthly(int day, LinkedList* Local, CentralQueue<int>* Central, int withdraw)
{
    if (day%30 == 0)
    {
        int total_number = 0,total_number_waiting = 0; // Initialize the counter to be used in weekly report.
         int total_number_appointment=0;
         int total_waiting_time=0;
         float averagewaiting; // average waiting time.
        Node* temp_pointer = Local->head; // Initialize the pointer to be the head of the linked-list.
        while(temp_pointer != NULL) // Going through all the elements.
        {
            total_number++; // First, add the total number.
            if(temp_pointer->data->appday==10000&&temp_pointer->data->withdraw==0){
                total_number_waiting++; // Then, the waiting people added.
            }
            if(temp_pointer->data->appday!=10000){
                total_number_appointment++; // Finally, the appointment people added.
                total_waiting_time+=temp_pointer->data->waitingday;
            }
            temp_pointer = temp_pointer->next; // Update the pointer to the next element.
            
        }
        averagewaiting=float(total_waiting_time)/float(total_number_appointment); // Calculate average waiting time.


        

        cout<<"----------In this month----------"<<endl;
        cout<<"The number people registered this month is "<<total_number<<endl;
        cout<<"The number people are waiting in total is "<<total_number_waiting<<endl;
        cout<<"The number of the appointment people had made this month is "<<total_number_appointment<<endl;
        cout<<"The average waiting time is "<<averagewaiting<<endl;
        cout<<"The number of people who withdrew their registration is "<<withdraw<<endl;
        cout<<endl<<endl<<endl<<endl;
    }
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
        cout<<"-------------------"<<"weekly report"<<"-------------------"<<endl;

        cin>>sort_selection;
        switch (sort_selection)
        {
        case 1:
            print_original(); // This operation has not been created. But it is quite easy.
            break;
        case 2:
            print_proffession_sorted();
            break;
        case 3:
            print_age_sorted(Local,day,Central); // We use age sort to prove that we have ideas to just print sorted patients.
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
    void print_age_sorted(LinkedList* Local, int day,  CentralQueue<int>* Central)
        {
            cout<<"The list that peopcole have been treated"<<endl<<endl;
            cout<<"profession"<<" "<<"age"<<" "<<"ID"<<" "<<"waiting day"<<endl;
            
            
            int counter = 0;
            Node* temp = Local->head;
            Person_Node* temp_out; // Set a temp pointer to let us know the people's node we are in.
            for(i = 0; i < Local->numb; i++)
            {
                int cured_day = temp->data->cureday; // Got the cured day.
            
                if(day - 7 <= cured_day&&cured_day <= day)
                {
                    Central->record_in_cure(temp->data); // Using a fib heap to record this kind of people and sort it.
                    counter++;
                }
            temp = temp->next;
            }
            
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_cure(); // Poping every elements in the heap out. And print it.
                if(temp_out!=NULL)
                {
                cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->ID<<" "<<temp_out->waitingday<<endl;
                }
            }


            temp = Local->head;
            counter = 0;
            cout<<"The list that people have queueing"<<endl<<endl;
            cout<<"profession"<<" "<<"age"<<" "<<"ID"<<" "<<"waiting day"<<endl;     
            for(i = 0; i < Local->numb; i++)
            {
                
                int registed_day = temp->data->regday;
                int app_day=temp->data->appday;

                if(day - 7 <= registed_day&& registed_day <= day && day<app_day)
                {
                    Central->record_in_reg(temp->data); // Just like above we record every this kind of people in a fib heap.
                    counter++;
                }
                temp= temp->next;
            }
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_reg(); // Print them all out.
                 if(temp_out!=NULL){
                cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->ID<<"  "<< day-temp_out->regday<<endl;
                 }
            }
            temp = Local->head;//123
            counter = 0;
            cout<<"The list that people is registered with a appointentment"<<endl<<endl;
            cout<<"profession"<<" "<<"age"<<" "<<"ID"<<" "<<"waiting day"<<endl;
            for(i = 0; i < Local->numb; i++)
            {
                // The third part has nothing different than above except the read data we need.
                int appointed_day = temp->data->appday;

                if(appointed_day == day)
                {
                    Central->record_in_app(temp->data);
                    counter++;

                }

                temp = temp->next;
            }
            cout<<counter<<"is counter"<<endl;
            for(i = 0; i < counter; i++)
            {
                temp_out = Central->record_out_app();
                if(temp_out!=NULL){
                    cout<<temp_out->p<<"  "<<temp_out->age<<"  "<<temp_out->ID<<"  "<< temp_out->waitingday-1<<endl;
                }
              
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
        void print_original()
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
    //initiallize
    int withdraw_counter = 0;
    CentralQueue<int>* Central = new CentralQueue<int>;
    LinkedList* Local = new LinkedList;
    CBPlusTree<int,Person_Node*>* Blackpink= new CBPlusTree<int,Person_Node*>;
    B_Tree<uint32_t>* Btree = new B_Tree<uint32_t>;
    
   
    
     int day[1000];//={1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int ID[1000];//={1,2,3,4,5,6,7,8,9,10,11,12,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int age[1000];//={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int risk[1000];//={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1};
    int waitmax[1000];//={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    string name[1000];//={"czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa"};
    string pro[1000];//]={"teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider"};
    string where[1000];//=

    //following part is used to read the csv file


    ifstream inFile("data.csv", ios::in);
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    
    int number_data=0;
    string line;
    string field;
     while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
    {
        
        string field;
        //string fields;
        istringstream sin(line); //将整行字符串line读入到字符串流sin中
        /*		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
		}
        day[number_data-1]=atoi( Trim(fields[0])); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
		ID[number_data-1]=atoi( Trim(fields[1]));
        age[number_data-1]=atoi( Trim(fields[2]));
        risk[number_data-1]=atoi( Trim(fields[3]));
        waitmax[number_data-1]=atoi( Trim(fields[4]));

        name[number_data-1]= Trim(fields[5]));
        pro[number_data-1]=Trim(fields[6]));
        where[number_data-1]=Trim(fields[7]));*/


        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        day[number_data]=atoi(field.c_str());

        
        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        ID[number_data]=atoi(field.c_str());
       //cout<<atoi(field.c_str())<<endl;

        
        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        age[number_data]=atoi(field.c_str());

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        risk[number_data]=atoi(field.c_str());

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        waitmax[number_data]=atoi(field.c_str());

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        name[number_data]=field.c_str() ;
        // cout<<field.c_str()<<endl;

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        pro[number_data]=field.c_str(); 
        // cout<<field.c_str()<<endl;

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        where[number_data]=field.c_str(); 
         //cout<<field.c_str()<<endl;

        
        number_data++;
    }
     cout << "total" << number_data << "lines" << endl;
  
   
    inFile.close();
  

    int numitems =0,date =1;
    Person_Node* test;
    while(date<=30){
        cout<<"----------today is day"<<date<<"---------"<<endl;
      
        	
	//bulid new node for new patient or update the information for old patient
      
        while(day[numitems]==date){
           	     Person_Node *sss=Local->search(ID[numitems]);
            
	        if( sss!= NULL)
	        {
	            sss->update(sss,date);
	          
	            
	        }
	        else  
	        {   
	           	Person_Node *pat=new Person_Node(day[numitems],ID[numitems],age[numitems],risk[numitems],waitmax[numitems],name[numitems],pro[numitems],where[numitems]);
	           
	            Local->insert(pat);//把person_node 加入local_p
	        //   Local->size_report();
            //   Local->display();
	           
	            
			}
            numitems++;
            
           
        }
        
        //following part is used to put today's patient in the fib_heap
                   
     
        LinkedList* today_people=Local->This_day(date);
        //today_people->size_report();
        //today_people->display();
        

        Node* somebody = today_people->head;
        
        
        while(somebody != NULL){
        	
            
           Central->record_in(somebody->data);
          
           somebody = somebody -> next;
            
            
        }
        
        
        int counter=0;
        int max=19;

        //folowing part is used to check whether get a patient's dll(waiting_max_Day) 

        LinkedList* ddl_people=Local->DDL_day(date);
        Node* someone=ddl_people->head;
        
        for(int i=0;i<ddl_people->numb;i++){
            
            Central->fib_heap-> decrease(Central->search_node(someone->data),-100);
            Person_Node* Rikka;
            Rikka=Central->record_out(date);
            if(Rikka!=NULL)
            {Blackpink->insert(Rikka->ID,Rikka);

            Btree->insert(((Rikka->age)<<25) + Rikka->ID);}

            someone = someone -> next;
            counter++;
           
        }
        //find must be apptoday;

        //following part is used to pop the smallest element in the fibheap
        
        for(int i=0;i<max-counter;i++){
            
            Person_Node* Rikka;
            Rikka=Central->record_out(date);
            if(Rikka!=NULL)
            {Blackpink->insert(Rikka->ID,Rikka);

            Btree->insert(((Rikka->age)<<25) + Rikka->ID);}
        }


         //following part is used to withdraw
        int operation;
        int operation2;
        

        cout<<"Do you want to withdraw? 1 for yes and others for no"<<endl;
        cin>>operation;
        while(operation == 1){
           withdraw_counter++;
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


        //following part is used to report
        report_weekly_monthly(date,Local,Central,withdraw_counter);
        date++;    
        int num123=Blackpink->getnum();
        /*cout<<num123<<endl;*/
        Person_Node** BP_tree = Blackpink->report();
       /* Btree->Inorder(Btree->root);*/
       //Btree->Inorder(Btree->root);
       Btree->display();
       Btree->num = 0;
       //cout<<Btree->rep[0];
       write_file_based_on_2_keys(BP_tree, num123, Btree->rep);
    }
    return 0;
}
