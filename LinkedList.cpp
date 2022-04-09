#include <iostream>
using namespace std;
#include "node.h"

// Making a node struct containing a data int and a pointer
// to another node
struct Node { 
    Person_Node* data; 
    Node *next; 
};

class LinkedList
{
    public:
    // Head pointer
    Node* head;
    int numb;


    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
      numb = 0;
    }

    // inserting elements (At start of the list)
    void insert(Person_Node* val)
    {
      // make a new node
      Node* new_node = new Node;
      new_node->data = val;
      new_node->next = NULL;

      // If list is empty, make the new node, the head
      if (head == NULL)
        head = new_node;
      // else, make the new_node the head and its next, the previous
      // head
      else
      {
        new_node->next = head;
        head = new_node;
      }
      numb++;
    }

    // loop over the list. return true if element found
    Person_Node* search(int id)
    {
      Node* temp = head;
      while(temp != NULL)
      {
        if (temp->data->ID == id)
          return temp->data;
        temp = temp->next;
      }
      return NULL;
    }

    LinkedList* This_day(int date)
    {  LinkedList* temp=new LinkedList();
      Node* temp_ptr = this->head;
      if (head->data->regday == date)
      {
        temp->insert(head->data);
      }
      
      while (temp_ptr->next != NULL)
      {
        if(temp_ptr->next->data->regday == date)
        {
          temp->insert(temp_ptr->next->data);
        }
        temp_ptr = temp_ptr->next;
      }
      return temp;
    }

    LinkedList* DDL_day(int date)
    {LinkedList* temp=new LinkedList();
     
      Node* temp_ptr = head;
      if (this->head->data->lastday == date)
      {
        temp->insert(this->head->data);
      }
      
      while (temp_ptr->next != NULL)
      {
        if(temp_ptr->next->data->lastday == date)
        {
          temp->insert(temp_ptr->next->data);
        }
        temp_ptr = temp_ptr->next;
      }
      return temp;
    }
    
/*    void remove(int val)
    {
      // If the head is to be deleted
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
        // else print, value not found
        cout << "Value not found!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      Node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if (temp->next->data == val)
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not found" << endl;
    }
*/
    void display()
    {
      Node* temp = head;
      cout <<"display1"<<endl;
      
      while(temp != NULL)
      { cout <<"display2"<<endl;
        cout << temp->data->ID << " ";
         cout <<"display3"<<endl;
        temp = temp->next;
         cout <<"display4"<<endl;
      }
       cout <<"display5"<<endl;
      cout << endl;
      return;
    }

    void size_report()
    {
      cout<<"Now there are "<<numb<<"elements in the queue"<<endl;
    }
};
