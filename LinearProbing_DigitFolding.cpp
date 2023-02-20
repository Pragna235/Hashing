#include<iostream>
using namespace std;

int HTable[100],TABLE_SIZE; //global variables
int hash_digit(int key,int table_size) //linear probing using digit-folding method
{
    int sum=0;
    while(key>0)
    {
        sum=sum+key%10;
        key=key/10;
    }
    while(sum>table_size)
    {
        key=sum;
        sum=0;
        while(key>0)
    {
        sum=sum+key%10;
        key=key/10;
    }
    return sum;


    }
}

class LinearProbing
{
public:

    void Insert();
    void Display();
};
void LinearProbing::Insert()
{
    int value, index, i = 0, flag=0, hkey;
    cout<<"Enter the value to insert in the hash table = ";
    cin>>value;
    hkey=hash_digit(value,TABLE_SIZE);


    if(HTable[hkey]==NULL)
        HTable[hkey]=value;
    else
    {
        for(i=1;i<TABLE_SIZE;i++)
        {
            index=(hkey+i)%(TABLE_SIZE);

            if(HTable[index]==NULL)
            {

                HTable[index]=value;

                break;
            }
        }
        if(i==TABLE_SIZE) //if the hash table is full
            cout<<"Can't be inserted!"<<endl;
    }
}

void LinearProbing::Display()
{
    int i;
    cout<<"\nHash Table"<<endl;
    cout<<"Index \tValue"<<endl;
    for(i=0;i<TABLE_SIZE;i++)
    {
        cout<<i<<"\t"<<HTable[i]<<endl;
    }
}

int main() //driver code
{
    cout<<"Enter Table Size  = ";
    cin>>TABLE_SIZE;
    LinearProbing lp;
    for (int i=0;i<TABLE_SIZE;i++)
    {
        lp.Insert();
    }
    lp.Display();
    return 0;

}




