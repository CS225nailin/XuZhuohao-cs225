#include <fstream>
#include <iostream>
using namespace std;

void write_file_based_on_2_keys(Person_Node** BP_tree, int BP_num, uint32_t* B_tree)
{
    ofstream outfile;
    outfile.open("Output_File.csv");
    for(int i = 0; i < BP_num; i++)
    {
        outfile<<BP_tree[i]->ID;
        outfile<<",";
        outfile<<BP_tree[i]->age;
        outfile<<",,";
        uint32_t temp_1 = B_tree[i];
        uint32_t temp_2 = B_tree[i];
        outfile<<(temp_1 << 7 >> 7);
        outfile<<",";
        outfile<<(temp_2 >> 25);
        outfile<<endl;
    }
   outfile.close();
}