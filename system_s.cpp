#include<iostream>
#include<windows.h>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

string line_num, t, alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUV", t_1, t_2, n_10_tim;
int start, en;
vector<string> s_line_vect;
vector<string> en_vect;
vector<string> num_10_vect;

string in_10(string str, int index)
{
    int num = 0;
    double nn = 0;
    string s_nn = "";
    if(index == 1)
    {
        for(int i = 0; i < str.length(); i++)
        {
            num += alpha.find(str[i]) * pow(start, (str.length() - (i + 1)));
        }
        return to_string(num);
    }
    if(index == 0)
    {
        for(int i = 0; i < str.length(); i++)
        {
            for(int b = 0; b < alpha.length(); b++)
            {
                if(str[i] == alpha[b])
                {
                    nn += b * pow(start, (-(i + 1)));
                }
            }
        }
        for(int i = 2; i < to_string(nn).length();i++)
        {
            s_nn += to_string(nn)[i];
        }
        return s_nn;
    }
    return "ERROR";
}

string in_en(string str, int index)
{
    if(index == 1)
    {
        int num = stoi(str);
        str = "";
        int ost = 0;
        while(num > 0)
        {
            ost = num % en;
            num = num / en;
            str = alpha[ost] + str;
        }
        return str;
    }
    if(index == 0)
    {
        double num = stod("0." + str);
        str = "";
        int i = 0;
        while((num != 1) && (i < 16))
        {
            i++;
            string tim = "";
            int cel = 0;
            num = num * en;
            for(int i = 0; i < to_string(num).find("."); i++)
            {
                tim += to_string(num)[i];
            }
            cel = stoi(tim);
            tim = "";
            str += alpha[cel];
            if(num > 1)
            {
                num = num - cel;
            }
        }
        return str;
    }
    return "ERROR";
}

int main()
{
    cout<<"Введите систему счисления вводимых чисел"<<endl;
    cin>>start;
    cout<<"Введите числа"<<endl;
    cin.ignore(1000, '\n');
    getline(cin, line_num);
    string tim = "";
    line_num = line_num + " ";
    for(int i = 0; i < line_num.length(); i++)
    {
        if(line_num[i] == ' ' && tim != "")
        {
            s_line_vect.push_back(tim);
            tim="";
        }
        else
        {
            tim+=line_num[i];
        }
    }
    cout<<"Введите необходимую систему счисления"<<endl;
    cin>>en;
    for(int i = 0; i < s_line_vect.size(); i++)
    {
        n_10_tim = "";
        if((s_line_vect[i].find(".") < s_line_vect[i].length()) || (s_line_vect[i].find(",") < s_line_vect[i].length()))
        {
            t_1 = "";
            t_2 = "";
            if((s_line_vect[i].find(".") < s_line_vect[i].length()))
            {
                t = ".";
            }
            else
            {
                t = ",";
            }
            int index_t = s_line_vect[i].find(t);
            for(int c = 0; c < s_line_vect[i].length(); c++)
            {
                if(c < index_t)
                {
                    t_1 += s_line_vect[i][c];
                }
                if(c > index_t)
                {
                    t_2 += s_line_vect[i][c];
                }
            }
            n_10_tim = in_10(t_1, 1);
            n_10_tim += t;
            n_10_tim += in_10(t_2, 0);
        }
        else
        {
            n_10_tim = in_10(s_line_vect[i], 1);
        }
        num_10_vect.push_back(n_10_tim);
    }
    
    for(int i = 0; i < num_10_vect.size(); i++)
    {
        n_10_tim = "";
        if((num_10_vect[i].find(".") < num_10_vect[i].length()) || (num_10_vect[i].find(",") < num_10_vect[i].length()))
        {
            t_1 = "";
            t_2 = "";
            if((num_10_vect[i].find(".") < num_10_vect[i].length()))
            {
                t = ".";
            }
            else
            {
                t = ",";
            }
            int index_t = num_10_vect[i].find(t);
            for(int c = 0; c < num_10_vect[i].length(); c++)
            {
                if(c < index_t)
                {
                    t_1 += num_10_vect[i][c];
                }
                if(c > index_t)
                {
                    t_2 += num_10_vect[i][c];
                }
            }
            n_10_tim = in_en(t_1, 1);
            n_10_tim += t;
            n_10_tim += in_en(t_2, 0);
        }
        else
        {
            n_10_tim = in_en(num_10_vect[i], 1);
        }
        en_vect.push_back(n_10_tim);
    }

    for(int i = 0; i < num_10_vect.size(); i++)
    {
        cout<<s_line_vect[i]<<"\t"<<num_10_vect[i]<<"\t"<<en_vect[i]<<endl;
    }
    return 0;
}
