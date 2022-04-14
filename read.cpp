#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    /*ofstream outFile("Data.csv", ios::out);
    ios::out;//如果没有文件，那么生成空文件；如果有文件，清空文件
    if (!outFile)
    {
      cout << "打开文件失败！" << endl;
     exit(1);
    }
    //写入3行数据
    for (int i = 0; i < 3; i++)
    {
      outFile << 12 << ",";
      outFile << 13 << ",";
      outFile << 14 << ",";
      outFile << "NaN" << endl;
    }
    outFile.close();
    cout << "写入数据完成" << endl;*/

    ifstream inFile("Data.csv", ios::in);
    if (!inFile)
    {
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    int i = 0;
    string line;
    string field;
    while (getline(inFile, line))//getline(inFile, line)表示按行读取CSV文件中的数据
    {
        string field;
        istringstream sin(line); //将整行字符串line读入到字符串流sin中

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout<<atoi(field.c_str())<<" ";//将刚刚读取的字符串转换成int

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout<<atoi(field.c_str())<<" ";//将刚刚读取的字符串转换成int

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout<<atoi(field.c_str())<<" ";//将刚刚读取的字符串转换成int

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout << atoi(field.c_str()) << " ";//将刚刚读取的字符串转换成int

        getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout << atoi(field.c_str()) << " ";//将刚刚读取的字符串转换成int

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout << field.c_str() <<" ";//将刚刚读取的字符串转换成int

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout << field.c_str()<<" ";//将刚刚读取的字符串转换成int

        getline(sin, field,','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
        cout << field.c_str() << endl;//将刚刚读取的字符串转换成int
        i++;
    }
    inFile.close();
    /*cout << "共读取了：" << i << "行" << endl;
    cout << "读取数据完成" << endl;*/
}