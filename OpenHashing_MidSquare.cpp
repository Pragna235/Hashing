#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class SeperateHash {

private:

int n;
vector<vector<int> > v;

public:

SeperateHash(int n)
{
v = vector<vector<int> >(n);
this->n = n;
}



int hash_mid(int key) {
    int s = key * key;
    int nod = (int)log10(s)+1;
    int m=(int)(s/pow(10,nod/2))%10;
    return m;
}

void insert(int x)
{
v[hash_mid(x)].push_back(x);
}

void del(int x)
{
int i = hash_mid(x);
for (int j = 0; j < v[i].size(); j++) {
if (v[i][j] == x) {
v[i].erase(v[i].begin() + j);
cout << x << " deleted!" << endl;
return;

}
}

cout << "No Element Found!" << endl;
}
void displayHash()
{
for (int i = 0; i < v.size(); i++) {
cout << i;
for (int j = 0; j < v[i].size(); j++)
cout << " -> " << v[i][j];
cout << endl;
}
}
};


int main()
{

int arr[] = { 12, 3, 23, 4, 11,
32, 26, 33, 17, 19 };
SeperateHash obj(10);
for (int i = 0; i < 10; i++)
obj.insert(arr[i]);
cout << "Initial Hash:\n";
obj.displayHash();
cout << "\nRemoving 23 from Hash: ";
obj.del(23);
cout << endl;
cout << "Final Hash:\n";
obj.displayHash();
return 0;
}
