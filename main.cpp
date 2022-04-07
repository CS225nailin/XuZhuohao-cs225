#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "node.cpp"
using std::string;
using std::cout;
using namespace std;
int main(){
    CentralQueue<int>* Central = new CentralQueue<int>;
    local_queue* Local = new local_queue;
    int day[3]={1,1,2};
    int ID[3]={320011,320012,320013};
    int age[3]={18,19,50};
    int risk[3]={0,1,3};
    int waitmax[3]={3,6,9};
    string name[3]={"czx","dasd","ds"};
    string pro[3]={"teacher","police","soider"};
    string where[3]={"A","C","B"};
    int numitems=0,date=1;
    while(date<=30){
        while(date==day[numitems]){
        if//（相同ID）
        {
            //update
        }
        else
        {
            Person_Node *pat=new person_Node(Person_Node *pat=new person_Node(day[numitems],numitemsD[numitems],age[numitems],rnumitemssk[numitems],wanumitemstmax[numitems],name[numitems],pro[numitems],where[numitems]);
            Local->get_p()->push(*pat);//把person_node 加入local
        }
        numitems++;
                   
        }
        for(i=0;/**size**/;i++){
            /*loacl的操作 提供pointer*/
            Central->record_in(/*local给的pointer*/);
        }
        int counter=0;
        //find must be apptoday;
        for
        for(i=0;/*max-counter*/;i++){
            Central->record_out();
        }
        //print "是否withdraw 0 for yes 1 for no"
        //if 0 go on
        //if 1 ,enter id
        //check if this id in central , if so , withdraw ,else print "not found"

        report_weekly_monthly(date);
        date++;

	    

    }
}

