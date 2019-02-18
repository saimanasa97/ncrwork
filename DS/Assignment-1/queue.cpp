#include<iostream>
using namespace std;

struct __queue__{
int frnt;
int rear;
int Size;
int *q;
};
class _queue_{
    struct __queue__ que;
public:
    _queue_(int);
    void enqueue(int);
    int dequeue();
    int rear();
    int top();
    void display();
    bool overflow();
    bool underflow();
    ~_queue();

};
_queue_::_queue(int n){
    que.top = que.rear = -1;
    que.Size=n;
    que.q= new int[n];
    }
void _queue_::enqueue(int ele){
    if(rear==-1 && frnt==-1){
        rear++;
        frnt++;
    }
    que.q[que.rear++]=ele;
}
int _queue_::dequeue(){

}
void _queue_::display(){
for(i=que.frnt;i>=que.rear;i--)
    cout<<que.q[i]<<" ";
cout<<endl;
}
bool _queue_::overflow(){
return que.rear==que.Size-1;
}
bool _queue_::underflow(){
return que.rear==que.frnt==-1;
}
_queue_::~_queue(){
delete [] que.q;
}
