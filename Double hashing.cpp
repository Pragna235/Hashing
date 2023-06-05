#include<iostream>

using namespace std;

#define TABLE_SIZE 10

class DoubleHashing{

 int Htable[TABLE_SIZE];

 int Probing[TABLE_SIZE];

 public:

 DoubleHashing()

 {

     for(int i=0;i<TABLE_SIZE;i++)

        Htable[i]=NULL,Probing[i]=NULL;

 }

    void insrt();

    void del();

    void display();

    void srch();

};



void DoubleHashing::insrt()

{

    int hkey,value,index,i;

    cout<<"Enter the value to be inserted";

    cin>>value;

    hkey=(2*value+3)%TABLE_SIZE;

    if(Htable[hkey]==NULL)

        Htable[hkey]=value,Probing[hkey]=1;

    else

    {    int v=(3*value+1)%TABLE_SIZE;

        for(i=0;i<TABLE_SIZE;i++)

        {

             index=(hkey+v*i)%TABLE_SIZE;

             if(Htable[index]==NULL)

             {   Probing[index]=++i;

                 Htable[index]=value;

                 break;

             }

        }



    }

    if(i==TABLE_SIZE)

        cout<<"The Hash Table is full the given element cannot be inserted"<<endl;

}



void DoubleHashing::del()

{   int hkey,value,index,i;

    cout<<"Enter the element to be deleted";

    cin>>value;

    hkey=(2*value+3)%TABLE_SIZE;

    if(Htable[hkey]==value)

        Htable[hkey]=NULL;

    else

    {   int v=(3*value+1)%TABLE_SIZE;

        for(i=0;i<TABLE_SIZE;i++)

        {

            index=(hkey+v*i)%TABLE_SIZE;

            if(Htable[index]==value)

            {

              Htable[index]=NULL;

              break;

            }



        }

    }

    if(i==TABLE_SIZE)

        cout<<"The given value is not present in the has table"<<endl;

}



void DoubleHashing::display()

{

    cout<<"INDEX    VALUE   PROBING"<<endl;

    for(int i=0;i<TABLE_SIZE;i++)

    cout<<i<<"        "<<Htable[i]<<"     "<<Probing[i]<<endl;



}



void DoubleHashing::srch()

{

    int hkey,value,index,i;

    cout<<"Enter the element to be searched";

    cin>>value;

    hkey=(2*value+3)%TABLE_SIZE;

    if(Htable[hkey]==value)

       cout<<"The given value is present at "<<hkey<<" position in the hash table"<<endl;

    else

    {  int v=(3*value+1)%TABLE_SIZE;

        for(i=0;i<TABLE_SIZE;i++)

        {

            index=(hkey+v*i)%TABLE_SIZE;

            if(Htable[index]==value)

            {

                cout<<"The given value is present at the "<<index<<" position of the Hash Table"<<endl;

                break;

            }

        }

    }

    if(i==TABLE_SIZE)

        cout<<"The given element is not present in the Hash Table"<<endl;



}





int main()

{

    DoubleHashing a;

    int choice=1;

        cout<<"1.Insertion"<<endl<<"2.Deletion"<<endl<<"3.Search"<<endl<<"4.Display"<<endl<<"0 to end"<<endl;

    while(choice)

    {cout<<"Enter your choice"<<endl;

     cin>>choice;

      switch(choice)

      {

            case 1:a.insrt();

                    break;

            case 2:a.del();

                    break;

            case 3:a.srch();

                    break;

            case 4:a.display();

                    break;



      }

    }

 return 0;



}
