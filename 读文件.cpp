#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
//deque是啥
//一个队列把

void main()
{
   

    ifstream inFile("Data.csv", ios::in);
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    
    int number_data=0;
    string line;
    string field;
    while (getline(inFile, line)){
        number_data++;
    }
     int day[number_data];//={1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int ID[number_data];//={1,2,3,4,5,6,7,8,9,10,11,12,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int age[number_data];//={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    int risk[number_data];//={0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1};
    int waitmax[number_data];//={1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,23,23,23,24,24,24,25,25,25,26,26,26,27,27,27,28,28,28,29,29,29,30,30,30};
    string name[number_data];//={"czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","czx","dasd","ds","dsa","dsa","dsa","dsa"};
    string pro[number_data];//]={"teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","teacher","police","soider","soider","soider","soider","soider"};
    string where[number_data];//=

    number_data=0;
    while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
    {
        string field;
        istringstream sin(line); //将整行字符串line读入到字符串流sin中

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        day[number_data]=atoi(field.c_str());

        
        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        ID[number_data]=atoi(field.c_str());

        
        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        age[number_data]=atoi(field.c_str());

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        risk[number_data]=atoi(field.c_str());

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        waitmax[number_data]=atoi(field.c_str());

        getline(sin, field); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        name[number_data]=field.c_str() ;

        getline(sin, field); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        pro[number_data]=field.c_str(); 

        getline(sin, field); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        where[number_data]=field.c_str(); 

        number_data++;
    }
    inFile.close();
    cout << "共读取了：" << number_data << "行" << endl;
    cout << "读取数据完成" << endl;
}
