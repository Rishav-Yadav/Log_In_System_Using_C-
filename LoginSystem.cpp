#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
void SignUp()
{ char username[20];
ofstream fout("accounts.txt");
cout<<"\n Create A New Account:";
cout<<"\n Enter Username For Your Account:";
cin.ignore();
cin.getline(username,20);
cout<<"\n Enter A Strong Password Containing Symbols#@,Capital Letters:";
 char password[20];
  int i=0; char a;
   for(i=0;;)
   {
    a=getch();
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||a=='@'||a=='#'||a==' ')
        {password[i]=a;
        i++;
        cout<<"*";}
    if(a=='\r')
        {password[i]='\0';
         break;}
    if(a=='\b'&&i>=1)
        {cout<<"\b \b";
        --i;}
   }

cout<<"\n Your Account Has Been Successfully Created and Registered On database:";

fout<<username<<endl;
fout<<endl<<(password)<<endl;
}


void LogIn()
{ string word;char username[20];
    int flag1=0,flag2=0;
    ifstream fin("accounts.txt");
    cout<<"\n Log In:";
    cout<<"\n Enter Username:";
  cin.ignore();
  cin.getline(username,20);
    cout<<"\n Enter Password:";
   char password[20];
  int i=0; char a;
   for(i=0;;)
   {
    a=getch();
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||a=='@'||a=='#'||a==' ')
        {password[i]=a;
        i++;
        cout<<"*";}
    if(a=='\r')
        {password[i]='\0';
         break;}
    if(a=='\b'&&i>=1)
        {cout<<"\b \b";
        --i;}
   }

    while(getline(fin,word))
    { if(username==word)
            flag1=1;
        if(password==word)
        flag2=1;

    }
    if(flag1==1&&flag2==1)
        cout<<"\n Logged In Successfully";
    else
        cout<<"\n Either Username Or Password is wrong:";

}

int main()
{int choice;
    char ch='y';
    while(ch=='y'||ch=='Y')
    {cout<<"You Want TO:";
    cout<<"\n1.Log In";
    cout<<"\n2.Sign Up: ";
    cin>>choice;
    switch(choice)
    {
    case 1:LogIn();
        break;
    case 2:SignUp();
        break;
        default:cout<<"\n Your Choice is not valid!";}
        cout<<"\n Press Y or y To Recreate Account Or Re Log in:";
        cin>>ch;

}
}
