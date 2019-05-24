    
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;
class record
{
    public: char ssn[20],name[20],phone[20];
}


rec[20],found[20];

int i,no,num,total,tempnum=0,stempnum=0,stotal,count;


char emp_no[5],rt_name[20];
int ssn=0;

void sortrecord()
{
    int i,j;
    record temp;
    for(i=0;i<no-1;i++)
    for(j=0;j<no-i-1;j++)
    if(strcmp(rec[j].name,rec[j+1].name)>0)
    {
        temp=rec[j];
        rec[j]=rec[j+1];
        rec[j+1]=temp;
    }
}
void indexfile()
{
    fstream index,index2;
    int i;

    index.open("secindex.txt",ios::in |ios::app);
    index2.open("record.txt",ios::in |ios::app);
    for(i=tempnum;i<total;i++)
    {
        index<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<i<<"\n";
        index2<<i<<"|"<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<
        rec[i].phone<<"\n";
    }
    index.close();
    index2.close();
}

void retrieve_record(char*index)
{
    fstream file;
    char phone[20],ssn[20],name[20],ind[5];
    file.open("record.txt",ios::in);
    for(i=0;i<total;i++)
    {
        file.getline(ind,20,'|');
        file.getline(name,20,'|');
        file.getline(ssn,20,'|');
        file.getline(phone,20,'\n');
        
        if(strcmp(index,ind)==0)
        {
            cout<<index<<" is the index\n";
            cout<<"ssn\t\tNAME\t\tphone\n";
            cout<<ssn<<"\t\t"<<name<<"\t\t"<<phone<<"\t\t"<<"\n";
            return;
            
        }
    }
    file.close();
}
void retrieve_details()
{
    fstream file;
    char phone[20],ssn[20],name[20],ind[5];
    char chssn[20],index[20][20];
    file.open("secindex.txt",ios::in);
    int k=0;
    cout<<"inside retruieve details\n";
    for(i=0;i<total;i++)
    {
        cout<<"inside for";
        file.getline(name,20,'|');
        file.getline(ssn,20,'|');
        file.getline(ind,4,'\n');
        if(strcmp(name,rt_name)==0)
        {
            cout<<"inisde if\n";
            strcpy(found[k].name,name);
            strcpy(found[k].ssn,ssn);
            strcpy(index[k],ind);
        }
        else
        {
            cout<<"inside else\n";
            strcpy(found[k].ssn,"null");
        }
        k++;
    }
    cout<<"value of k is"<<k<<"\n";
    file.close();
    if(k==1)
    {
        retrieve_record(index[0]);
        return;
    }
    else
    {
        
        cout<<"choose the books ssn\n";
        for(int i=0;i<k;i++)
        {
            if(strcmp(found[i].ssn,"null"))
            {
                cout<<"ssn:"<<found[i].ssn<<"\tNAME:"<<found[i].name<<endl;
            }
        }
    }
    cin>>chssn;
    for(i=0;i<k;i++)
    {
        if(strcmp(chssn,found[i].ssn)==0)
        {
            cout<<"inside comparing the ssn\n";
            retrieve_record(index[i]);
            return;
        }
    }
    cout<<"invalid entry\n";
    return;
}
void delete_record(char*indx)
{
    char phone[20],ssn[20],name[20],cost[20],ind[5];
    fstream file1,file2;
    char index[20][20];
    file2.open("record.txt",ios::in);
    for(i=0;i<total;i++)
    {
        file2.getline(ind,4,'|');
        file2.getline(name,20,'|');
        file2.getline(ssn,20,'|');
        file2.getline(phone,20,'\n');
        

        strcpy(index[i],ind);
        strcpy(rec[i].ssn,ssn);
        strcpy(rec[i].name,name);
        strcpy(rec[i].phone,phone);
        
    }
    int flag=-1;
    for(i=0;i<total;i++)
    {
        if(strcmp(index[i],indx)==0)
        flag=i;
    }
    if(flag==-1)
    {
        cout<<"error\n";
        return;
    }
    if(flag==(total-1))
    {
        total = total - 1;
        tempnum--;
        cout<<"record deleted\n";
        cout<<total;
        return;
    }
    for(i=flag;i<total;i++)
    {
        rec[i]=rec[i+1];
    }
    total = total - 1;
    tempnum--;
    cout<<"record deleted\n";
    file2.close();
    cout<<total;
    file1.open("secindex.txt",ios::out);
    file2.open("record.txt",ios::out);
    for(i=0;i<total;i++)
    {
        file1<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<i<<"\n";
        file2<<i<<"|"<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<rec[i].phone<<"\n";
    }
    file1.close();
    file2.close();
}
void display()
            {

            char phone[20],ssn[20],name[20],cost[20],ind[5];
            fstream file;
            file.open("record.txt",ios::in);
            cout<<"Index No.\t\tNAME\t\tPHONE\n";
            
            

            for(i=0;i<total;i++)
            {
                file.getline(ind,4,'|');
               file.getline(name,20,'|');
                file.getline(ssn,20,'|');
                file.getline(phone,20,'\n');
        

            //strcpy(index[i],ind);
            strcpy(rec[i].ssn,ssn);
             strcpy(rec[i].name,name);
            strcpy(rec[i].phone,phone);
        
                
                cout<<rec[i].ssn<<"\t\t"<<rec[i].name<<"\t\t"<<rec[i].phone<<"\n";
            }
            }
void delete_index(char*nam)
{
    fstream file;
    char phone[20],ssn[20],name[20],cost[20],ind[5];
    char chssn[20],index[20][20];
    int i,k=0;
    file.open("secindex.txt",ios::in);
    for(i=0;i<total;i++)
    {
        file.getline(name,20,'|');
        file.getline(ssn,20,'|');
        file.getline(ind,4,'\n');
        if(strcmp(nam,name)==0)
        {
            strcpy(found[k].name,name);
            strcpy(found[k].ssn,ssn);
            strcpy(index[k],ind);
        }
        else
        {
            strcpy(found[k].ssn,"null");
        }
        k++;
    }
    file.close();
    if(k==1)
    {
        delete_record(index[0]);
        return;
    }
    else
    {
        cout<<"choose the books ssn\n";
        for(i=0;i<k;i++)
        {
            if(strcmp(found[i].ssn,"null"))
            {
                cout<<"ssn:"<<found[i].ssn<<"\t"<<"NAME:"<<found[i].name<<endl;
            }
        }
    }
    cin>>chssn;
    for(i=0;i<k;i++)
    {
        if(strcmp(chssn,found[i].ssn)==0)
        {
            delete_record(index[i]);
            return;
        }
    }
    cout<<"invalid entry\n";
    return;
}
void update_record(char*index)
{
    fstream file,file1,file2;
    char phone[20],ssn[20],name[20],cost[20],ind[5];
    file.open("record.txt",ios::in);
    for(i=0;i<total;i++)
    {
        file.getline(ind,20,'|');
        file.getline(name,20,'|');
        file.getline(ssn,20,'|');
        file.getline(phone,20,'|');
        
        if(strcmp(index,ind)==0)
        {
            cout<<"Enter the New Name:";
            cin>>rec[i].name;
            cout<<"New ssn:";
            cin>>rec[i].ssn;
            cout<<"New phone:";
            cin>>rec[i].phone;
            

            sortrecord();

            file1.open("secindex.txt",ios::out);
            file2.open("record.txt",ios::out);
            for(i=0;i<total;i++)
            {
                file1<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<i<<"\n";
                file2<<i<<"|"<<rec[i].name<<"|"<<rec[i].ssn<<"|"<<
                rec[i].phone<<"\n";
            }
            file1.close();
            file2.close();
        }
    }
    file.close();
}
void update_index(char*nam)
{
    fstream file;
    char phone[20],ssn[20],name[20],cost[20],ind[5];
    char chssn[20],index[20][20];
    int i,k=0;
    file.open("secindex.txt",ios::in);
    for(i=0;i<total;i++)
    {
        file.getline(name,20,'|');
        file.getline(ssn,20,'|');
        file.getline(ind,4,'\n');
        if(strcmp(nam,name)==0)
        {
            strcpy(found[k].name,name);
            strcpy(found[k].ssn,ssn);
            strcpy(index[k],ind);
        }
        else
        {
            strcpy(found[k].ssn,"null");
        }
        k++;
    }
    file.close();
    if(k==1)
    {
        update_record(index[0]);
        return;
    }
    else
    {
        cout<<"choose the books ssn\n";
        for(i=0;i<k;i++)
        {
            if(strcmp(found[i].ssn,"null"))
            {
                cout<<"ssn:"<<found[i].ssn<<"\t"<<"NAME:"<<found[i].name<<endl;
            }
        }
    }
    cin>>chssn;
    for(i=0;i<k;i++)
    {
        if(strcmp(chssn,found[i].ssn)==0)
        {
            update_record(index[i]);
            return;
        }
    }
    cout<<"invalid entry\n";
    return;
}
int main()
{
    fstream file1;
    string buffer;
    char rt_ssn[20],contact_name[20],contact_ssn[20];
    char new_ssn[20];
    char phone[20],name[20],ind[5];
    int i,j,flag,flag1,flag2,flagsame,choice;
    int temp=0;
    int ssn=0;
    fstream file;
    file.open("record.txt",ios::in);
     buffer.erase();
    while(!file.eof())
        {
            getline(file,buffer);
            tempnum++;
        }
        file.close();
        tempnum--;
    total=tempnum;
    cout<<total;
   // student s1;
    cout<<"\t\t-----------------------------------------\n";
    cout<<"\t\tWelcome to Contact Management System\n";
    cout<<"\t\t-----------------------------------------\n\t\tThis project is done by Shreya and  Sanjana\n";
    for(;;)
    {
        cout<<"\nChoose the option\n1:Add\n2:Search\n3:Delete\n4:Display\n5:Update\n6:Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the no of Contacts\n";
            cin>>no;
            flagsame = 0;
            count = 0;
            total = total + no;
            for(i=tempnum;i<total;i++)
            {
                cout<<"Enter the Name:";
                cin>>rec[i].name;
                cout<<"ssn:";
                ssn++;
                //cin>>rec[i].ssn;
                cout<<"ssn is\t"<<ssn;
                cout<<"Enter the displayed ssn:";
                cin>>rec[i].ssn;
              // rec[i].ssn=ssn;
                flagsame = 0;
                for(j=0;j<i;j++)  //checking for similar ssn
                {
                    if(strcmp(rec[i].ssn,rec[j].ssn)==0)
                    {
                        cout<<"\n Error!! Same ssn found\n";
                        flagsame = 1;
                    }
                }
                if(flagsame)
                {
                    total = total - no;
                    total = total + count;
                    break;
                }
                cout<<"phone:";
                cin>>rec[i].phone;
                
            
                count = count + 1;
            }
            sortrecord();
            indexfile();
            if(flagsame)
            {
                tempnum = tempnum - no;
                tempnum = tempnum + count;
            }
            else
            {
                tempnum = tempnum + no;
            }
            break;
            case 2:cout<<"Enter the name of the person to be searched\n";
            cin>>contact_name;
    
            file1.open("secindex.txt",ios::in);
            if(!file1)
            {
                cout<<"file creation error\n";
                exit(0);
            }
            flag1=0;
            for(i=0;i<total;i++)
            {
                file1.getline(rt_name,20,'|');
                file1.getline(contact_ssn,20,'|');
                file1.getline(emp_no,4,'\n');
                //cout<<"inside case\n";
                if(strcmp(contact_name,rt_name)==0)
                {
                    retrieve_details();
                    flag1=1;
                    break;
                }
            }
            if(!flag1)
                cout<<"record search failed\n";
            file1.close();
            break;
            case 3:cout<<"Enter the name of the person to be deleted\n";
            cin>>contact_name;
            file1.open("secindex.txt",ios::in);
            if(!file1)
            {
                cout<<"file creation error\n";
                exit(0);
            }
            flag=0;
            for(i=0;i<total;i++)
            {
                file1.getline(rt_name,20,'|');
                file1.getline(contact_ssn,20,'|');
                file1.getline(ind,4,'\n');
                if(strcmp(contact_name,rt_name)==0)
                {
                    delete_index(rt_name);
                    flag=1;
                    break;
                }
            }
            if(!flag)
                cout<<"deletion failed\n";
            file1.close();
            break;
            case 4:
            
        display();
            break;
            case 5:
            cout<<"Enter the name of the CONTACT to be updated\n";
            cin>>contact_name
    ;
            file1.open("secindex.txt",ios::in);
            if(!file1)
            {
                cout<<"file creation error\n";
                exit(0);
            }
            flag2=0;
            for(i=0;i<total;i++)
            {
                file1.getline(rt_name,20,'|');
                file1.getline(contact_ssn,20,'|');
                file1.getline(ind,4,'\n');
                if(strcmp(contact_name,rt_name)==0)
                {
                    update_index(rt_name);
                    flag2=1;
                    break;
                }
            }
            if(!flag2)
                cout<<"updation failed\n";
            file1.close();
            break;
            case 6:
            exit(0);
            break;
            default:cout<<"invalid choice\n";
            exit(0);
            break;
            
            

        }
    }
}