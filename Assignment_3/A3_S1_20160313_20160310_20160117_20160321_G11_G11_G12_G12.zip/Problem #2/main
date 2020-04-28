#include <iostream>

using namespace std;
template <class T>
class node
{
    public:
        T data;
        node* next;
};
template <class T>
node<T> *head;

template <class T>
class Stack
{
    private:
        int stSize;
    public:
        Stack()
        {
            head<T> =NULL;
            stSize=0;
        }

        void push (T value)
        {
            node<T> *new_node = new node<T>();
            new_node->data=value;
            if (head<T> != NULL)
            {
                new_node->next = head<T> ;
            }
            head<T> = new_node ;
            stSize+=1;
        }
        Stack (T value, int initialSize)
        {
            head<T> =NULL;
            stSize=0;
            for(int i=0;i<initialSize;i++)
                push(value);
        }
        ~Stack()
        {
            while(head<T> != NULL)
                pop();
        }
        T pop()
        {
            int counter=0;
            node<T> *deleted_node;
            if(head<T> == NULL)
            {
                cout<<"the stack is empty !\n";
                return -1;
            }
            stSize-=1;
            deleted_node=head<T>;
            head<T> =head<T> ->next;
            T newValue=deleted_node->data;
            delete(deleted_node);
            return newValue;
        }
        int stackSize()
        {
            return stSize;
        }
        T& top()
        {
            if(head<T> == NULL)
            {
                cout<<"the stack is empty!\n";

            }
            else

            return head<T> ->data;
        }
};
int main()
{
    Stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    cout<<"the stack size: "<<mystack.stackSize()<<endl;
    cout<<"the stack last element: "<<mystack.top()<<endl;
    int qVal=mystack.pop();
    cout<<"the deleted value: "<<qVal<<endl;
    cout<<"the stack size: "<<mystack.stackSize()<<endl;
    cout<<"the stack last element: "<<mystack.top()<<endl;
    cout<<"\n*************************************************\n";
    Stack<double> dblstack(10,10);
    cout<<"the stack size: "<<dblstack.stackSize()<<endl;
    cout<<"the stack last element: "<<dblstack.top()<<endl;
    qVal=dblstack.pop();
    cout<<"the deleted value: "<<qVal<<endl;
    cout<<"the stack size: "<<dblstack.stackSize()<<endl;
    cout<<"the stack last element: "<<dblstack.top()<<endl;
    return 0;
}
