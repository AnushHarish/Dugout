

#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
//#include<conio.h>
//#include<process.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int flag=0;
fstream in;
class players
{
public: int flag;
    char n[20],a[20],name[20],role[20];
    
};
players rec[10];
int k;
int h(int m)
{   int r,q;
    r=m%10;
    q=m/10;
    k=(q+r+7)%10;
    return k;
}
void insert()
{
    int no,k,m;
    char n[20],a[20],name[20],role[20];
    cout<<"\nEnter no of players to inserted: \n";
    cin>>no;
    for(int i=0;i<no;i++)
    {
        cout<<"Enter jersy number ";
        cin>>n;
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter age ";
        cin>>a;
        cout<<"\nEnter role ";
        cin>>role;
        m=atoi(n);
        k=h(m);
        if(rec[k].flag==0)
        {
            strcpy(rec[k].n,n);
            strcpy(rec[k].name,name);
            strcpy(rec[k].a,a);
            strcpy(rec[k].role,role);
            //cout<<rec[k].n<<rec[k].name<<rec[k].a<<rec[k].role;
            rec[k].flag=1;
        }
        else
        {
            for(int j=k+1;j%10<10;j++)
            {
                if(rec[j%10].flag==0)
                {
                    strcpy(rec[j%10].n,n);
                    strcpy(rec[j%10].name,name);
                    strcpy(rec[j%10].a,a);
                    strcpy(rec[j%10].role,role);
                    rec[j%10].flag=1;
                    break;
                }
            }
        }
    }
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(int i=0;i<10;i++)
    {
        if(rec[i].flag==0)
            f1<<"#"<<"\n";
        else
            f1<<rec[i].n<<"|"<<rec[i].name<<"|"<<rec[i].a<<"|"<<rec[i].role<<"\n";
    }
    f1.close();
}
void unpack()
{
    int i=0;
    in.open("abc.txt",ios::in);
    while(!in.eof())
    {
        in.getline(rec[i].n,20,'|');
        in.getline(rec[i].name,20,'|');
        in.getline(rec[i].a,20,'|');
        in.getline(rec[i].role,20,'\n');
        i++;
    }
    
    in.close();
}
void deleting()
{
    int k,m,i,f=0;
    char n[20];
    cout<<endl;
    cout<<"Enter jersey no:";
    cin>>n;
    m=atoi(n);
    k=h(m);
    unpack();
    for(i=0;i<10;i++)
    {
        if(strcmp(rec[k%10].n,n)==0)
        {
            rec[k%10].flag=0;
            strcat(rec[k%10].n,"0");
            cout<<"\n player removed ";
            f=1;
        }
        k=k+1;
    }
    if(f!=1)
    {
        
        cout<<"\n player not found \n";
    }
    fstream f1;
    f1.open("abc.txt",ios::out);
    for(int i=0;i<10;i++)
    {
        if(rec[i].flag==0)
            f1<<"#"<<"\n";
        else
            f1<<rec[i].n<<"|"<<rec[i].name<<"|"<<rec[i].a<<"|"<<rec[i].role<<"\n";
    }
    f1.close();
    
}
void disp()
{
    
    cout<<"The players details: \n";
    cout<<"jersey no    "<<"player name    "<<"age    "<<"role\n";
    for(int i=0;i<10;i++)
    {
        if(rec[i].flag==1)
            
        cout<<rec[i].n<<"\t\t\t\t"<<rec[i].name<<"\t\t\t"<<rec[i].a<<"\t\t"<<rec[i].role<<"\n";
    }
    
}
void search()
{
    int m,k,i,f=0;
    char n[20];
    cout<<endl;
    cout<<"Enter jersey no:";
    cin>>n;
    m=atoi(n);
    k=h(m);
    unpack();
    for(i=0;i<10;i++)
    {
        if((strcmp(rec[k%10].n,n))==0)
        {
            cout<<"player details:    \n";
            cout<<"jersey no    "<<"player name    "<<"age    "<<"role\n";
            cout<<rec[k].n<<"\t\t\t\t"<<rec[k].name<<"\t\t\t"<<rec[k].a<<"\t\t"<<rec[k].role<<"\n";
            f=1;
        }
        k=k+1;
    }
    if(f!=1)
        cout<<"\nplayer not found \n";
    return;
}
void modify()
{
    
    int cm,k,m,f=0;
    char n[20] ,name1[20],a1[20],role1[20];
    cout<<endl;
    cout<<"Enter jersey no:";
    cin>>n;
    m=atoi(n);
    k=h(m);
    unpack();
    while(1)
    {
        
        if((strcmp(rec[k%10].n,n))==0)
        {
            
            cout<<"1.player name\n2.age\n3.role\n4.exit\nEnter ur choice:";
            cin>>cm;
            switch(cm)
            {
                case 1:cout<<"enter new name : ";
                    cin>>name1;
                    strcpy(rec[k].name,name1);
                    break;
                case 2:cout<<"enter new age : ";
                    cin>>a1;
                    strcpy(rec[k].a,a1);
                    break;
                case 3:cout<<"enter new role : ";
                    cin>>role1;
                    strcpy(rec[k].role,role1);
                    break;
                case 4: break;
                default : cout<<"invalide choice";
            }
            
            cout<<"\nAfter modification details    :\n";
            cout<<"jersey no    "<<"player name    "<<"age    "<<"role\n";
            cout<<rec[k].n<<"\t\t\t\t"<<rec[k].name<<"\t\t\t"<<rec[k].a<<"\t\t"<<rec[k].role<<"\n";
            f=1;
            break;
        }

        
        
    }
    k=k+1;
    
    fstream f2;
    f2.open("abc.txt",ios::out);
    for(int i=0;i<10;i++)
    {
        if(rec[i].flag==0)
            f2<<"#"<<"\n";
        else
            f2<<rec[i].n<<"|"<<rec[i].name<<"|"<<rec[i].a<<"|"<<rec[i].role<<"\n";
    }
    f2.close();
    if(f!=1)
        cout<<"\n Not found \n";
}
void cle()
{
    for(int l=0;l<10;l++)
    {
        rec[l].flag=0;
        
    }
}

int main()
{
    int c,ch,co;
    char password[5]="rcb";
    char code[20];
    cle();
loop:    while(1)
{
    cout<<"\n\t\t\tWELCOME TO RCB DUGOUT\n";
    cout<<"1.ADMIN\n2.PLAYER\n\nEnter choice       :";
    cin>>c;
    if(c==1)
    {
        cout<<"\nEnter password      :";
        cin>>code;
        if(strcmp(password,code)==0)
        {
            while(1)
            {
                cout<<" \n 1.Add player\n 2.remove player \n 3.display\n 4.search\n 5.modify\n 6.pre menu\n\nEnter choice :    ";
                cin>>ch;
                switch(ch)
                {
                    case 1: insert();break;
                    case 2: deleting();break;
                    case 3: disp();break;
                    case 4: search();break;
                    case 5: modify();break;
                    case 6: goto loop;
                    default:cout<<"invalid";break;
                }
            }
            
        }
        else
        {
            cout<<"\nIncorrect password\n";
            goto loop;
        }
    }
    
    
    else if(c==2)
    {
        while(1)
        {
            
            cout<<"\n\n 1.SCHEDULE\n 2.VIEW TEAM\n 3.PRE MENU\n\n Enter ur choice:";
            cin>>co;
            switch(co)
            {
                case 1:
                {
                    char ca;
                    const char *fileName="table.txt";
                    ifstream file;
                    file.open(fileName,ios::in);
                    if(!file)
                    {
                        cout<<"Error in opening file!!!"<<endl;
                        return -1;
                    }
                    while (!file.eof())
                    {
                        file >> noskipws >> ca;
                        cout << ca;
                    }
                    file.close();
                }
                    break;
                case 2: disp();break;
                case 3: goto loop;
                default:cout<<"invalid";break;
                    
            }
        }
    }
    else
        
        cout<<"Invalide choice\n";
    return 0;
    
    return 0;
}
}
