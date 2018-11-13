#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
   char fname[5];
   char lname[5];
   cout << "Enter your fname: ";
   cin.getline(fname,10);
   cout << "Your fname is " << fname << endl;
   cout << "Enter your lname: ";
   cin.getline(lname,10);
   cout << "Your lname is " << lname << endl;
   return 0;
}