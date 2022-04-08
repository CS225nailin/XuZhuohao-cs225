#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "node.cpp"
#include "Local_queue.cpp"
#include "Fibheap.cpp"
#include "report_part.cpp"


using std::string;
using std::cout;
using namespace std;



int main(){
    CentralQueue<int>* Central = new CentralQueue<int>;
    Local_queue* Local = new Local_queue;
    
    int day[3]={1,1,2};
    int ID[3]={320011,320012,320013};
    int age[3]={18,19,50};
    int risk[3]={0,1,3};
    int waitmax[3]={3,6,9};
    string name[3]={"czx","dasd","ds"};
    string pro[3]={"teacher","police","soider"};
    string where[3]={"A","C","B"};
    int numitems =0,date =1;
    while(date<=30){
        cout<<'----------today is day'<<date<<'---------'<<endl;
        
        while(date==day[numitems]){
        

        if(Local->search_id(ID[numitems]) != NULL)

        {
            Local->search_id(ID[numitems])->update(Local->search_id(ID[numitems]),date);
        }
        else
        {
            Person_Node *pat=new Person_Node(day[numitems],ID[numitems],age[numitems],risk[numitems],waitmax[numitems],name[numitems],pro[numitems],where[numitems]);
            Local->get_p()->push(*pat);//把person_node 加入local_p
        }
        numitems++;
                   
        }
        Local->deal(date);
        for(int i=0;i<Local->get_q()->size();i++){//q有问题
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
            Central->record_out();
            counter++;
           
        }
        //find must be apptoday;
        
        for(int i=0;i<max-counter;i++){
            Central->record_out();
        }
        int operation;
        int operation2;
        
        cout<<"Do you want to withdraw? 1 for yes and others for no";
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
}