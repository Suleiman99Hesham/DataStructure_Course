#include <iostream>

using namespace std;

template <class T>
class node
{
    public:
        T data;
        node *next;
};


template <class T>
node<T> *head;
template <class T>
node<T> *tail;


template <class T>
class Queue
{
    private:
        int qSize;
    public:
        Queue()
        {
            head<T> = NULL;
            tail<T> = NULL;
            qSize=0;
        }
        Queue(T value,int initialSize)
        {
            head<T> = NULL;
            tail<T> = NULL;
            qSize=0;
            while(initialSize--)
                push(value);
        }
        ~Queue()
        {
            node<T> *new_node;

            while(head<T> != NULL)
            {
                new_node = head<T>;
                head<T> = head<T> ->next;
                delete new_node;
            }
            tail<T> =NULL;
            qSize=0;
        }
        void push(T value)
        {
            node<T> *new_node;
            new_node = new node<T> ;
            new_node->data = value;
            new_node->next = NULL;
            if(tail<T> == NULL)
                head<T> = new_node;
            else
                tail<T> -> next = new_node;
            tail<T> = new_node;
            qSize++;
        }
        void pop(T& value)
        {
            node<T> *new_node;
            new_node = head<T>;
            value = head<T> ->data;
            head<T> = head<T> ->next;
            if(head<T> == NULL)
                tail<T> = NULL;
            qSize--;
            delete new_node;
        }
        int Q_size()
        {
            return qSize;
        }
        T Front()
        {
            if(!Q_size())
                throw "Queue is Empty!!\n";
            return head<T> ->data;
        }
};

int main()
{
    try
    {
        Queue<int> myqueue;
        myqueue.push(1);
        myqueue.push(2);
        myqueue.push(3);
        myqueue.push(4);
        myqueue.push(5);
        cout<<"the queue size: "<<myqueue.Q_size()<<endl;
        cout<<"the queue first element: "<<myqueue.Front()<<endl;
        int dVal;
        myqueue.pop(dVal);
        cout<<"the deleted value: "<<dVal<<endl;
        cout<<"the queue size: "<<myqueue.Q_size()<<endl;
        cout<<"the queue first element: "<<myqueue.Front()<<endl;
        cout<<"\n*************************************************\n";
        Queue<double> dblqueue(10,10);
        cout<<"the queue size: "<<dblqueue.Q_size()<<endl;
        cout<<"the queue first element: "<<dblqueue.Front()<<endl;
        double d2Val;
        dblqueue.pop(d2Val);
        cout<<"the deleted value: "<<d2Val<<endl;
        cout<<"the queue size: "<<dblqueue.Q_size()<<endl;
        cout<<"the queue first element: "<<dblqueue.Front()<<endl;
    }
    catch(...)
    {
        cout<<"ERROR..!\n";
    }

    return 0;
}
