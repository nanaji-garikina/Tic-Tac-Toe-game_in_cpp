#include<bits/stdc++.h>
using namespace std;

void outputFunc(char ar[3][3])
{
    cout<<"-------------\n";
    cout<<"| "<<ar[0][0]<<" | "<<ar[0][1]<<" | "<<ar[0][2]<<" |\n";
    cout<<"-------------\n";
    cout<<"| "<<ar[1][0]<<" | "<<ar[1][1]<<" | "<<ar[1][2]<<" |\n";
    cout<<"-------------\n";
    cout<<"| "<<ar[2][0]<<" | "<<ar[2][1]<<" | "<<ar[2][2]<<" |\n";
    cout<<"-------------\n";
    cout<<endl;
}
void check(char ar[3][3],string s)
{
     if(ar[0][0]==ar[0][1] && ar[0][1]==ar[0][2] || ar[1][0]==ar[1][1] && ar[1][1]==ar[1][2] || ar[2][0]==ar[2][1] && ar[2][1]==ar[2][2] || ar[0][0]==ar[1][0] && ar[1][0]==ar[2][0] || ar[0][1]==ar[1][1] && ar[1][1]==ar[2][1] || ar[0][2]==ar[1][2] && ar[1][2]==ar[2][2] || ar[0][2]==ar[1][1] && ar[1][1]==ar[2][0] || ar[0][0]==ar[1][1] && ar[1][1]==ar[2][2])
     {
        outputFunc(ar);
         cout<<s<<" won the game\n";
         exit(1);
     }
}

void Box(char ar[3][3],int n,char c,string s)
{
    switch(n)
    {
        case 1:
            ar[0][0]=c;
            check(ar,s);
            break;
        case 2:
            ar[0][1]=c;
            check(ar,s);
            break;
        case 3:
            ar[0][2]=c;
            check(ar,s);
            break;
        case 4:
             ar[1][0]=c;
             check(ar,s);
             break;
        case 5:
             ar[1][1]=c;
             check(ar,s);
             break;
        case 6:
             ar[1][2]=c;
             check(ar,s);
             break;
        case 7:
             ar[2][0]=c;
             check(ar,s);
             break;
        case 8:
             ar[2][1]=c;
             check(ar,s);
             break;
        case 9:
             ar[2][2]=c;
             check(ar,s);
             break;
              
    }
}

int main()
{
 cout<<"Welcome to Tic-Tac-Toe!"<<endl;
 cout<<"-----------------------"<<endl;
 cout<<endl;
    int  c=1;
     char ar[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
              ar[i][j]= c+'0';
              c++;
        }
    }
    int n=9;
    string p1,p2;
    cout<<"Enter the 1st person name:\n";
    cin>>p1;
    cout<<"Enter the 2nd person name:\n";
    cin>>p2;
    char p1c;
    char p2c;
    cout<<endl;
    cout<<p1<<" Choose the X or O :\n";
    cin>>p1c;
    if(p1c=='x' || p1c=='X')
    {    
        p1c='X';
        p2c='O';
    }
    else{
        p1c='O';
        p2c='X';
    }
    string s="";
    while(n)
    {
        outputFunc(ar);
        if(n%2!=0)
        {
            cout<<p1<<" select a box:\n";
            int n1;
            cin>>n1;
            if(n1<1 || n1>9){ 
                cout<<"Invalid move. Try again."<<endl;
                n++;   
            }
           else if(s.find(n1+'0')!=string::npos)
            {
                cout<<p1<<" Please enter an unselected box number:\n";
               n++;
            }
            else{
                s+=n1+'0';
            Box(ar,n1,p1c,p1);
            }
        }
        else{
            cout<<p2<<" select a box:\n";
            int n2;
            cin>>n2;
            if(n2<1 || n2>9){ 
                cout<<"Invalid move. Try again."<<endl;
                n++;
                
            }
           else if(s.find(n2+'0')!=string::npos)
            {
                cout<<p2<<" Please enter an unselected box number:\n";
               n++;
            }
            else{
            s+=n2+'0';
            Box(ar,n2,p2c,p2);
            }
        }
        n--;
    }
    outputFunc(ar);
    cout<<"It is a draw.\n";
   return 0;
}