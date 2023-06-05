#include <iostream>
#include<cmath>
using namespace std;
int hash_division(int key, int table_size) {
    return key % table_size;
}
int hash_mid(int key, int table_size) {
    int s = key * key;
    int nod = (int)log10(s)+1;
    int m=(int)(s/pow(10,nod/2))%10;
    return m;
}
int hash_digit(int key,int table_size)
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
    //return sum;


    }
    return sum;
}
int hash_mul(int key, int table_size) {

    double product = key * 0.1;
    double fractional_part = fmod(product,1);
    int index = floor(table_size * fractional_part);
    return index;
}
int main() {
    int num_inputs;
    cout << "Enter the number of inputs: ";
    cin >> num_inputs;
    int table_size;
    cout << "Enter the size of the hash table: ";
    cin >> table_size;
    int hash1[table_size];
    for (int i = 0; i < num_inputs; i++) {
        cout << "Enter key " << i + 1 << ": ";
        cin >> hash1[i];
    }
    for (int i = 0; i < num_inputs; i++) {
        int key = hash1[i];
        cout << "Key " << i + 1 << " :" << key <<"   ";
        cout << "Division : " << hash_division(key, table_size) <<"   ";
        cout << "Mid-square :" << hash_mid(key, table_size) <<"   ";
        cout << "Digit Folding : " << hash_digit(key, table_size) <<"   ";
        cout << "Multiplication : " << hash_mul(key, table_size) <<"   ";

        cout << endl;
    }

    return 0;
}
