#include<iostream>
using namespace std;

int HTable[100],TABLE_SIZE; //global variables
int hash_division(int key, int table_size) {
    return key % table_size;
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
    hkey=hash_division(value,TABLE_SIZE);


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
    int n;
    cout<<"Enter Table Size  = ";
    cin>>TABLE_SIZE;
    cout<<"Enter the number of Inputs: = ";
    cin>>n;
    LinearProbing lp;
    for (int i=0;i<n;i++)
    {
        lp.Insert();
    }
    lp.Display();
    return 0;

}




