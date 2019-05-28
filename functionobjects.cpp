#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
template <class ForwIter>
void print(ForwIter first, ForwIter last, const string& title)
{
cout << title << endl;
while (first != last)
cout << *first++ << '\t';
cout << endl;
}
int main()
{
int data[3] = { 9, 10, 11 };
print(data, data + 3, "Original values");
transform(data, data + 3, data, bind2nd(multiplies<int>(), 2));
print(data, data + 3, "New values");
}

