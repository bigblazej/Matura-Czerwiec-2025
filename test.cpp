#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //string s = "fs@dx+cd50450505VfF^&x50";

    ifstream file("dane.txt");
    int ilosc = 0, ilosc_roz_liczb = 1, najm_roz_liczb = 10;
    string s, s_4;

    //int_arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    int int_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(!file.eof())
    {
        getline(file, s);
        int length = s.length();


        //Podpunkt 1
        for(int i = 0; i < length - 2; i++)
        {
            if(!isdigit(s[i]) && isdigit(s[i + 1]) && isdigit(s[i + 2]))
            {
                if(s[i + 1] == '5' && s[i + 2] == '0')
                {
                    ilosc++;
                }   
            }
        }

        //Podpunkt 2
        for(int i = 0; i < length; i++)
        {
            if(isdigit(s[i]))
            {
                int_arr[s[i] - '0']++;
            }
        }

        //Podpunkt 3
        cout<<"Podpunkt 3: "<<endl;
        for(int i = 0; i < length - 10; i++)
        {
            if(!isdigit(s[i]) && isdigit(s[i + 1]) && isdigit(s[i + 2]) && isdigit(s[i + 3]) && isdigit(s[i + 4]) && isdigit(s[i + 5]) && isdigit(s[i + 6]) && isdigit(s[i + 7]) && isdigit(s[i + 8]) && isdigit(s[i + 9]) && !isdigit(s[i + 10]))
            {
                if(s[i + 1] == '5')
                {
                    for(int j = 1; j < 10; j++)
                    {
                        cout<<s[i + j];
                    }
                    cout<<endl;
                }   
            }
        }

        //Podpunkt 4
        for(int i = 0; i < length - 10; i++)
        {
            ilosc_roz_liczb = 1;
            if(!isdigit(s[i]) && isdigit(s[i + 1]) && isdigit(s[i + 2]) && isdigit(s[i + 3]) && isdigit(s[i + 4]) && isdigit(s[i + 5]) && isdigit(s[i + 6]) && isdigit(s[i + 7]) && isdigit(s[i + 8]) && isdigit(s[i + 9]) && !isdigit(s[i + 10]))
            {
                if(s[i + 1] != s[i + 2] && s[i + 1] != s[i + 3] && s[i + 1] != s [i + 4] && s[i + 1] != s [i + 5] && s[i + 1] != s [i + 6] && s[i + 1] != s [i + 7] && s[i + 1] != s [i + 8] && s[i + 1] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 2] != s[i + 3] && s[i + 2] != s [i + 4] && s[i + 2] != s [i + 5] && s[i + 2] != s [i + 6] && s[i + 2] != s [i + 7] && s[i + 2] != s [i + 8] && s[i + 2] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 3] != s [i + 4] && s[i + 3] != s [i + 5] && s[i + 3] != s [i + 6] && s[i + 3] != s [i + 7] && s[i + 3] != s [i + 8] && s[i + 3] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 4] != s [i + 5] && s[i + 4] != s [i + 6] && s[i + 4] != s [i + 7] && s[i + 4] != s [i + 8] && s[i + 4] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 5] != s [i + 6] && s[i + 5] != s [i + 7] && s[i + 5] != s [i + 8] && s[i + 5] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 6] != s [i + 7] && s[i + 6] != s [i + 8] && s[i + 6] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 7] != s [i + 8] && s[i + 7] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }
                if(s[i + 8] != s [i + 9])
                {
                    ilosc_roz_liczb++;
                }

                if(ilosc_roz_liczb < najm_roz_liczb)
                {
                    s_4 = "";
                    for(int j = 1; j < 10; j++)
                    {
                        s_4 = s_4 + s[i + j];
                    }
                    najm_roz_liczb = ilosc_roz_liczb;
                }
                else
                {
                    if(ilosc_roz_liczb == najm_roz_liczb)
                    {
                        s_4 = s_4 + " ";
                        for(int j = 1; j < 10; j++)
                        {   
                            s_4 = s_4 + s[i + j];
                        }
                    }
                }
            }
        }
    }

    cout << "Podpunkt 1: "<< ilosc << endl<<"Podpunkt 2: "<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<i<<" "<<int_arr[i]<<endl;
    }
    cout<<"Podpunkt 4: "<<s_4<<endl;
    return 0;
}