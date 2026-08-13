#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string sent="Today we have a DSA lab" ;
    stringstream s(sent);
    string currword;
    string longword;
    int max=0;
    while (s>>currword)
    {
      if (currword.length()> max)
      {
        max=currword.length();
        longword = currword;
      }
      
    }
    cout << "The longest one win is :"<<longword <<endl;
    cout<< "Count of letter is :" << max << endl;
    return 0;
    
}


