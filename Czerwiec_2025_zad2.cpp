#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int nwd(int a, int b)
{
    while(b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool kkk(int a, int b, long long c)
{
    if(a + b < c)
    {
        return true;
    }
    return false;
}

int main()
{
    ifstream file("liczby1.txt");
    //ifstream file("liczby1_przyklad.txt");
    ofstream out_file("wyniki2_2.txt");

    string temp_string, temp_to_len, max_string;
    int str_length, str_int, ilosc = 0, max_kkk = 0;
/*
    while(!file.eof())
    {
        getline(file, temp_string);
        stringstream ss(temp_string), ss2(temp_string);
        ss>>str_int;
        ss2>>temp_to_len;
        str_length = temp_to_len.length();
        cout<<"str_int "<<str_int<<endl;
        int temp = 1, liczba_a = 0, liczba_b = 0;
        for(int i = 0; i < str_length/2; i++)
        {
            cout<<"for"<<endl;
            liczba_b = liczba_b + temp * (str_int % 10);
            str_int = str_int / 10;
            temp = temp * 10; 
        }
        liczba_a = str_int;

        if(nwd(liczba_a, liczba_b) == 1)
        {
            cout<<"nwd"<<endl;
            out_file<<liczba_a<<liczba_b<<endl;
            ilosc++;
        }
    }
    out_file<<endl<<endl<<ilosc;
*/




    //Podpunkt 3
    ifstream file2("liczby2.txt");
    ofstream out_file2("wyniki2_3.txt");
    while(getline(file2, temp_string))
    {
        stringstream ss(temp_string), ss2(temp_string);;
        ss>>str_int;
        ss2>>temp_to_len;
        int temp = 1, liczba_a = 0, liczba_b = 0, temp_kkk = 0, str_length = 0;
        long long liczba_c;
        liczba_c = str_int * str_int;
        int x = liczba_c;
        while(x > 0)
        {
            x = x / 10;
            str_length++;
        }
        for(int i = 0; i < str_length; i++)
        {
            liczba_b = liczba_b + temp * (liczba_c % 10);
            liczba_c = liczba_c / 10;
            temp = temp * 10; 
            if(kkk(liczba_c, liczba_b, str_int))
            {
                temp_kkk++;
            }
        }

        if(temp_kkk > max_kkk)
        {
            max_kkk = temp_kkk;
            max_string = temp_to_len;
        }
    }
    
    out_file2<<max_kkk<<"  "<<max_string<<endl;

    return 0;
}