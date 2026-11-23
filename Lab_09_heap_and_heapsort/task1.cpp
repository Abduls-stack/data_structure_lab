
#include<iostream>
#include<queue>
using namespace std;

class Student{
public:
    string name;
    int roll;
    int marks;
    Student* left;
    Student* right;

    Student(string n,int r,int m){
        name=n;
        roll=r;
        marks=m;
        left=NULL;
        right=NULL;
    }
};

class MaxHeap{
    Student* heap[100];
    int size;

public:
    MaxHeap(){
        size=0;
    }

    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;

            if(heap[i]->marks>heap[parent]->marks){
                swap(heap[i],heap[parent]);
                i=parent;
            }
            else{
                break;
            }
        }
    }

    void insert(string name,int roll,int marks){
        Student* s=new Student(name,roll,marks);

        heap[size]=s;
        heapifyUp(size);
        size++;

        for(int i=0;i<size;i++){
            heap[i]->left=(2*i+1<size)?heap[2*i+1]:NULL;
            heap[i]->right=(2*i+2<size)?heap[2*i+2]:NULL;
        }
    }

    void display(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        queue<Student*> q;
        q.push(heap[0]);

        cout<<"\nLevel Order Traversal:\n";

        while(!q.empty()){
            Student* temp=q.front();
            q.pop();

            cout<<"Name: "<<temp->name
                <<" Roll: "<<temp->roll
                <<" Marks: "<<temp->marks<<endl;

            if(temp->left!=NULL)
                q.push(temp->left);

            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }

    void heapifyDown(int i){
        while(true){
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<size && heap[left]->marks>heap[largest]->marks)
                largest=left;

            if(right<size && heap[right]->marks>heap[largest]->marks)
                largest=right;

            if(largest!=i){
                swap(heap[i],heap[largest]);
                i=largest;
            }
            else{
                break;
            }
        }
    }

    void deleteHighest(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        cout<<"\nDeleted Student: "<<heap[0]->name
            <<" Marks: "<<heap[0]->marks<<endl;

        delete heap[0];

        heap[0]=heap[size-1];
        size--;

        if(size>0)
            heapifyDown(0);

        for(int i=0;i<size;i++){
            heap[i]->left=(2*i+1<size)?heap[2*i+1]:NULL;
            heap[i]->right=(2*i+2<size)?heap[2*i+2]:NULL;
        }
    }

    ~MaxHeap(){
        for(int i=0;i<size;i++)
            delete heap[i];
    }
};

int main(){
    MaxHeap h;

    h.insert("Ali",101,85);
    h.insert("Ahmed",102,92);
    h.insert("Sara",103,78);
    h.insert("Usman",104,95);
    h.insert("Ayesha",105,88);
    h.insert("Hassan",106,90);

    cout<<"Original Max Heap:";
    h.display();

    h.deleteHighest();

    cout<<"\nUpdated Max Heap:";
    h.display();

    return 0;
}

