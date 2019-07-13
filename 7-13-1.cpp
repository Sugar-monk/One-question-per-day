/*************************************************************************
 *文件名: mail.cpp
 *作者: bean
 *邮箱: 17331372728@163.com
 * 创建时间: Sat 13 Jul 2019 04:28:13 AM PDT
 * 备注:
 *************************************************************************/
#include<iostream>
#include<string>
#include<pthread.h>
#include<vector>
using namespace std;

bool Find(string str, vector<string> buff)
{
    int size = buff.size();
    for(int i = 0; i < size; ++i)
    {
        if(str.compare(buff[i]) == 0)
            return true;
    }

    return false;
}


int main(int argc, char* argv[])
{
    string str;
    vector<string> buff;
    bool flag = true;
    int a = 0;

    while(a++==0 && getline(cin, str))
    {
        string tmp;
        int size = str.size();
        for(int i = 0; i < size; ++i)
        {
            if(str[i] == '"' && flag)
            {
                flag = false;
            }
            else if(str[i] == '"' && !flag)
            {
                flag = true;
            }
            else if(str[i] == ',' && flag )
            {
                buff.push_back(tmp);
                tmp.erase();
            }
            else
            {
                tmp += str[i];
            }
        }
        buff.push_back(tmp);
        getline(cin, tmp);
        if(Find(tmp, buff))
        {
            cout <<"Ignore" << endl;
        }
        else
            cout << "Important!" << endl;
    }
    return 0;
}

