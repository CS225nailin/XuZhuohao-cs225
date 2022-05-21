#include <fstream>
#include <iostream>
using namespace std;

void write_file_based_on_2_keys(Person_Node** BP_tree, int BP_num, Person_Node** B_tree)
{
    ofstream outfile;
    outfile.open("Output_File.csv");
    for(int i = 0; i < BP_num; i++)
    {
        outfile<<BP_tree[i]->ID;
        outfile<<",";
        outfile<<BP_tree[i]->age;
        outfile<<",,";
        outfile<<B_tree[i]->ID;
        outfile<<",";
        outfile<<B_tree[i]->age;
        outfile<<"/n";
    }
   outfile.close();
}