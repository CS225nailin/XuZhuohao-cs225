#include "Btree.h"

using namespace std;

BTnode::BTnode(void)
{
    keyNum = 0;  
    parent = nullptr;   
    isleaf = true;     
	int i;
	for (i = 0;i < child_max;i++)
	{
		pchild[i] = nullptr;  //intial the child pointer array
	}
	for (i = 0;i < key_max;i++)
	{
		keyvalue[i] = 0; // initial the keyvalue array
	}
}


BTree::BTree(void)
{
   root = nullptr;
   return;
}


bool BTree::_insert(Person_Node* value)
{
   cout<<"BTREE INSERT"<<endl;
   if (contain(value))
   {  //determine whether the tree has the same key
      return false;
   }
   else
   {
      if (root == nullptr)
      {
      	root = new BTnode();
      }
      if (root->keyNum == key_max)
      {
         BTnode* newnode = new BTnode();
         newnode->pchild[0] = root;
         newnode->isleaf = false;
         SplitBlock(newnode,0,root);
         root = newnode;  //update the root node
      }
      Notfull_insert(root,value);
      return true;
   }
}
 
void BTree::SplitBlock(BTnode* node_parent,int child_index,BTnode* node_child)
{
   BTnode* node_right = new BTnode();
   node_right->isleaf = node_child->isleaf;
   node_right->keyNum = key_min;
   int i;

   for (i = 0;i < key_min;i++)
   {
      node_right->keyvalue[i] = node_child->keyvalue[i+child_min];
   }
   if (!node_child->isleaf)
   {  //determine if the node is leaf node
      for (i = 0;i < child_min;i++)
      {
         node_right->pchild[i] = node_child->pchild[i+child_min];
         node_child->pchild[i+child_min]->parent = node_right->pchild[i];
      }
   }
   node_child->keyNum = key_min;  //update the key of the child node
   for (i = node_parent->keyNum;i > child_index;i--)
   {  //Move the parent keyword and child pointer back
      node_parent->keyvalue[i] = node_parent->keyvalue[i-1];
      node_parent->pchild[i+1] = node_parent->pchild[i];
      node_child->pchild[i]->parent = node_parent->pchild[i+1];
   }
   node_parent->keyNum++;  //update the key number of the parent node
   node_parent->pchild[child_index+1] = node_right;
   node_right->parent = node_parent->pchild[child_index+1];
   node_parent->keyvalue[child_index] = node_child->keyvalue[key_min];
   return;
}

void BTree::Notfull_insert(BTnode* node,Person_Node* value)
{  //
   int node_keynum = node->keyNum;
   if (node->isleaf)
   {  //if leaf node
      while (node_keynum > 0 && value->age < node->keyvalue[node_keynum-1]->age)
      {
      	node->keyvalue[node_keynum] = node->keyvalue[node_keynum-1];
      	--node_keynum;
      }
      	node->keyvalue[node_keynum] = value;

      	node->keyNum++;
   }
   else
   {  
      while (node_keynum > 0 && value->age < node->keyvalue[node_keynum-1]->age)
      {
      	--node_keynum;
      }
      BTnode* node_child = node->pchild[node_keynum];
      if (node_child->keyNum == key_max)
      {
      	SplitBlock(node,node_keynum,node_child);
      	if (value->age > node->keyvalue[node_keynum]->age)
      	{
      	  	node_child = node->pchild[node_keynum+1];
      	}
      }
      Notfull_insert(node_child,value);
   }
}

bool BTree::contain(Person_Node* value)
{
   if (_find(root,value) != nullptr) return true;
   return false;
}


BTnode* BTree::_find(BTnode* node,Person_Node* value)
{
   if (node == nullptr)
   {
   	return nullptr;
   }
   else
   {
      int i;
      for (i = 0; i < node->keyNum ;i++)
   	{
   	   if (value->age <= node->keyvalue[i]->age)
         {
            break; 
         }
   	}
      if (i < node->keyNum && value->age == node->keyvalue[i]->age)
      {
         return node;
      }
      else
      {
         if (node->isleaf) return nullptr;
         else return _find(node->pchild[i],value);
      }
   }
}


bool BTree::_delete(Person_Node* value)
{
   if (!contain(value))
   {
      return false;
   }
   if (root->keyNum == 1)
   {
      if (root->isleaf)
      {
         delete root;
         root = nullptr;
         return true;
      }
      else
      {
         BTnode* node_child1 = root->pchild[0];
         BTnode* node_child2 = root->pchild[1];
                
         if (node_child1->keyNum == key_min && node_child2->keyNum == key_min)
         {
            MergeBlock(root,0);
            delete root;
            root = node_child1;
         }
      }
   }
   BTree_deletebalance(root,value);
    return true;
}


void BTree::MergeBlock(BTnode* node_parent,int child_index)
{
   BTnode* node_child1 = node_parent->pchild[child_index];
   BTnode* node_child2 = node_parent->pchild[child_index+1];
   
   node_child1->keyvalue[key_min] = node_parent->keyvalue[child_index];
   node_child1->keyNum = key_max;
   int i;
   for (i = 0;i < key_min;i++)
   {
      node_child1->keyvalue[child_min+i] = node_child2->keyvalue[i];
   }
   
   if (!node_child1->isleaf)
   {
      for (i = 0; i < child_min;i++)
      {
         node_child1->pchild[i+child_min] = node_child2->pchild[i];
      }
   }

   node_parent->keyNum--;
   for (i = child_index;i <  node_parent->keyNum;i++)
   {
      node_parent->keyvalue[i] = node_parent->keyvalue[i+1];
       
      node_parent->pchild[i+1] = node_parent->pchild[i+2];
   }
   delete node_child2;
   node_child2 = nullptr;
}

Person_Node* BTree::getprev(BTnode* node)
{
   while (!node->isleaf)
   {
      node = node->pchild[node->keyNum];
   }
   node->keyNum--;
   return node->keyvalue[node->keyNum-1];
}

Person_Node* BTree::getnext(BTnode* node)
{

   while (!node->isleaf)
   {
      node = node->pchild[0];
   }
   return node->keyvalue[0];
}

void BTree::BTree_deletebalance(BTnode* node,Person_Node* value)
{
   int i;
     
   for(i = 0;i < node->keyNum && value->age > node->keyvalue[i]->age;i++)
   {}
     
   if (i < node->keyNum && value->age == node->keyvalue[i]->age)
   {
      
      if (node->isleaf)
      {
         node->keyNum--;
           
         for (;i < node->keyNum;i++)
         {
            node->keyvalue[i] = node->keyvalue[i+1];
         }
         return;
      }
      else
      {
          
         BTnode* node_left = node->pchild[i];
          
         BTnode* node_right = node->pchild[i+1];
         if (node_left->keyNum >= child_min)
         {
            Person_Node* prev_replace = getprev(node_left);
             
            BTree_deletebalance(node_left,prev_replace);
             
            node->keyvalue[i] = prev_replace;
            return;
         }
         else if (node_right->keyNum >= child_min)
         {
            Person_Node* next_replace = getnext(node_right);
        
            BTree_deletebalance(node_right,next_replace);
           
            node->keyvalue[i] = next_replace;
            return;
         }
         else
         {
            
         MergeBlock(node,i);
           
         BTree_deletebalance(node_left,value);
         }
      }
   }
   else
   {
       
      BTnode* node_child = node->pchild[i];
      BTnode*  node_left = nullptr;
      BTnode*  node_right = nullptr;
      if (node_child->keyNum == key_min)
      {  
          
         if (i >0)
         {
            node_left = node->pchild[i-1];
         }
         if (i <= node->keyNum-1)
         {
            node_right = node->pchild[i+1];
         }
         int j;
           
         if (node_left && node_left->keyNum >= child_min)
         {   
                
            for (j = node_child->keyNum;j > 0; j--)
            {
               node_child->keyvalue[j] = node_child->keyvalue[j-1];
            }
            node_child->keyvalue[0] = node->keyvalue[i-1];
               
            if (!node_left->isleaf)
            {
                
               for (j = node_child->keyNum+1;j > 0;j--)
               {
                  node_child->pchild[j-1]->parent = node_child->pchild[j]->parent;
                  node_child->pchild[j] = node_child->pchild[j-1];
 
               }
               node_left->pchild[node_left->keyNum]->parent =  node_child->pchild[0];
               node_child->pchild[0] = node_left->pchild[node_left->keyNum];
            }
            node_child->keyNum++;
            node->keyvalue[i-1] = node_left->keyvalue[node_left->keyNum-1];
            node_left->keyNum--;
         }
         else if (node_right && node_right->keyNum >= child_min)
         {
               
            node_child->keyvalue[node_child->keyNum] = node->keyvalue[i];
            node_child->keyNum++;
               
            node->keyvalue[i] = node_right->keyvalue[0];
            node_right->keyNum--;
               
            for (j = 0;j < node_right->keyNum;j++)
            {
               node_right->keyvalue[j] = node_right->keyvalue[j+1];
            }
            if (!node_right->isleaf)
            {
               node_right->pchild[0]->parent = node_child->pchild[node_child->keyNum]->parent;
               node_child->pchild[node_child->keyNum] = node_right->pchild[0];
               for (j = 0;j < node_right->keyNum+1;j++)
               {
                  node_right->pchild[j+1]->parent = node_right->pchild[j]->parent;
                  node_right->pchild[j] = node_right->pchild[j+1];
 
               }
                 
            }
         }
         else if (node_left)
         {
            
            MergeBlock(node,i-1);
           
            node_child = node_left;
         }
         else if (node_right)
         {
            
            MergeBlock(node,i);
         }
      }
      BTree_deletebalance(node_child,value);
   }
}

void BTree::Inorder(BTnode* root){
   if(root != NULL){
      Inorder(root->pchild[0]);
      for(int i = 1; i <= child_max;i++){
         temp_array[temp_size] = root->keyvalue[i-1];
         temp_size++;
         Inorder(root->pchild[i]);
      }
   }
}