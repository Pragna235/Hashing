#include <iostream>
#include<math.h>
using namespace std;
#define TABLE_SIZE 10

class QuadraticProbing

{
    int HTable[TABLE_SIZE];
    public:
        QuadraticProbing()
        {

            int i;
            for(i=0;i<10;i++)
                HTable[i]=NULL;
            }

        void Insert();
        void Search();
        void Display();
        void Delete();

};



void QuadraticProbing :: Insert()

{
    int value, index, i, flag=0, hkey;
    cout << "\nEnter the value to insert into the hash table " << endl;
    cin >> value;
    hkey = value % TABLE_SIZE;

    if(HTable[hkey] == NULL)
        HTable[hkey] = value;

    else

    {
        for(i=1;i <= TABLE_SIZE;i++)
            {
                index = (hkey + i*i )% TABLE_SIZE;
                if(HTable[index] == NULL)
                    {

               HTable[index] = value;
               break;

            }

        }

        if(i > TABLE_SIZE)
            cout << "\nElement cannot be inserted, Table Full." << endl;

    }

}



void QuadraticProbing :: Search()

{

    int value, index, i, flag = 0, hkey;
    cout << "\nEnter search element : " << endl;
    cin >> value;
    hkey = value % TABLE_SIZE;

    if (HTable[hkey] == value)
        cout << value << " is found at index " << hkey << endl;

    else
        {
        for(i=1; i <= TABLE_SIZE; i++)
        {
            index = (hkey + i*i) % TABLE_SIZE;
            if(HTable[index] == value)
            {
                cout << value << " is found at index " << index << endl;
                break;
                }

      }

      if(i > TABLE_SIZE)
        cout << "Sorry, " << value << " is not found in the Hash Table" << endl;

    }

}



void QuadraticProbing :: Delete()

{

    int value, index, i, flag = 0, hkey;
    cout << "\nEnter value to delete from Hash Table : " << endl;
    cin >> value;
    hkey = value % TABLE_SIZE;

    if (HTable[hkey] == value)

    {
        HTable[hkey] = NULL;
        cout << value << " deleted from the Hash Table" << endl;
    }

    else
        {
            for(i=1; i <= TABLE_SIZE ; i++)
            {
                index = (hkey + i*i) % TABLE_SIZE;
    if(HTable[index] == value)
        {
            HTable[index] = NULL;
            cout << value << " deleted from the Hash Table" << endl;
            break;

          }

      }

      if(i > TABLE_SIZE)
        cout << "Sorry Deletion not possible. " << value << " is not found in the Hash Table" << endl;

    }

}



void QuadraticProbing :: Display()

{

    int i;
    cout << "\n    HASH TABLE" <<  endl;
    cout << "Index\t\tValue" << endl;
    for(i=0;i< TABLE_SIZE; i++)
        cout << i << "\t\t" << HTable[i] << endl;

}



int main()

{
    QuadraticProbing QP;
    int choice;
    while(1)

    {
        cout << "\nQUADRATIC PROBING MENU\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit" << endl;
        cout << "What's your choice : ";
        cin >> choice;
        switch(choice)

        {

            case 1:

                    QP.Insert();

                    break;

            case 2:

                    QP.Display();

                    break;

            case 3:

                    QP.Search();

                    break;

            case 4:

                    QP.Delete();

                    break;

            case 5:

                    cout << "\nHappy Learning..!! Bye Bye...\n\n";

                    exit(0);



            default: cout << "\n Sorry, You have entered wrong choice..!! " << endl << "\nTry again..!! or Exit";

        }

    }

    return 0;

}







