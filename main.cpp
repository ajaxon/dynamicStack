#include <iostream>
#include <stdexcept>
#include "dstack.cpp"

using namespace std;



int main()
{

//cout<<"Enter a size for stack : "; cin >> len;
Stack s1;
try{
        s1.push(1);
        s1.display();
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.push(5);
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.display();
        s1.pop();
        s1.display();
        int i=0;
        while(i<1000000){
            s1.push(i);
            i++;
        }
        cout<<s1.Top();

} catch(overflow_error){
cerr<< "Illegal operation. Cannot push onto a full stack.";
return -1; }
catch(underflow_error){
cerr<< "Illegal operation. Cannot pop from an empty stack."; return -1;
}


}