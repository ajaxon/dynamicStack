#include <iostream>
#include <stdexcept>


using namespace std;

class Stack
{
private:
    int *p;
    int top,length,size;

public:
    Stack();
    Stack(int,int,int);
    ~Stack();

    void push(int);
    int pop();
    void display();
    int Top();
    void resizeStack(int);
    bool isEmpty(); 
    bool isFull(); 
};




Stack::Stack()
{
    top=-1;
    length=0;
  
    p=new int[1];
    size=1;
}

Stack::~Stack()
{
    delete [] p;
}


void Stack::push(int elem)
{

        
        if(this->isFull() ){
            
            size = 2*size;
            int * temp = new int[size];
            for(int i=0;i<length;i++){
                temp[i]=p[i];
            }
            this->~Stack();
            p = temp;

            
            p[++top]=elem;
            length++;
            


         

        }else{
        
        p[++top]=elem;
        length++;

    }
    
}
int Stack::pop()
{
    if(this->isEmpty())
    {
       throw underflow_error("Can't pop from an empty stack");
    }
    if(length==(size/4)){
        
        size = size/2;
        
        
            int * temp = new int[size];
            for(int i=0;i<length;i++){
                temp[i]=p[i];
            }
            this->~Stack(); //free the memory p is pointing at
            p = temp;    


    }

    int ret=p[top];
    top--;
    length--;

    return ret;
}

void Stack::resizeStack(int size){

    int * temp = new int[size];
            for(int i=0;i<length;i++){
                temp[i]=p[i];
            }
            this->~Stack();
            this->p = temp;
}

bool Stack::isEmpty(){
    return length==0;
}
bool Stack::isFull(){
    return length==size;
}

int Stack::Top()
{
    int ret = p[top];
    return ret;
}

void Stack::display()
{
    cout << size << ": ";
    
    for(int i = 0; i <= top; i++)
        cout<<p[i]<<" ";
    cout<<endl;
}



