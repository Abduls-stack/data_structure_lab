
#include<iostream>
#include<queue>
using namespace std;

class Patient{
public:
    string name;
    int id;
    int priority;
    Patient* left;
    Patient* right;

    Patient(string n,int i,int p){
        name=n;
        id=i;
        priority=p;
        left=NULL;
        right=NULL;
    }
};

class MaxHeap{
    Patient* heap[100];
    int size;

public:
    MaxHeap(){
        size=0;
    }

    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;

            if(heap[i]->priority>heap[parent]->priority){
                swap(heap[i],heap[parent]);
                i=parent;
            }
            else{
                break;
            }
        }
    }

    void insert(string name,int id,int priority){
        Patient* p=new Patient(name,id,priority);

        heap[size]=p;
        heapifyUp(size);
        size++;

        updatePointers();
    }

    void updatePointers(){
        for(int i=0;i<size;i++){
            heap[i]->left=(2*i+1<size)?heap[2*i+1]:NULL;
            heap[i]->right=(2*i+2<size)?heap[2*i+2]:NULL;
        }
    }

    void display(){
        if(size==0){
            cout<<"No patients available"<<endl;
            return;
        }

        queue<Patient*> q;
        q.push(heap[0]);

        while(!q.empty()){
            Patient* temp=q.front();
            q.pop();

            cout<<"Name: "<<temp->name
                <<" ID: "<<temp->id
                <<" Priority: "<<temp->priority<<endl;

            if(temp->left!=NULL)
                q.push(temp->left);

            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }

    void highestPriority(){
        if(size==0){
            cout<<"No patients available"<<endl;
            return;
        }

        cout<<"\nPatient with Highest Priority:\n";
        cout<<"Name: "<<heap[0]->name<<endl;
        cout<<"ID: "<<heap[0]->id<<endl;
        cout<<"Priority: "<<heap[0]->priority<<endl;
    }

    void heapifyDown(int i){
        while(true){
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<size && heap[left]->priority>heap[largest]->priority)
                largest=left;

            if(right<size && heap[right]->priority>heap[largest]->priority)
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

    void deletePatient(){
        if(size==0){
            cout<<"No patients available"<<endl;
            return;
        }

        cout<<"\nTreated Patient: "<<heap[0]->name<<endl;

        delete heap[0];

        heap[0]=heap[size-1];
        size--;

        if(size>0)
            heapifyDown(0);

        updatePointers();
    }

    void nextPatient(){
        if(size>0){
            cout<<"\nNext Patient for Treatment:\n";
            cout<<"Name: "<<heap[0]->name<<endl;
            cout<<"ID: "<<heap[0]->id<<endl;
            cout<<"Priority: "<<heap[0]->priority<<endl;
        }
    }

    ~MaxHeap(){
        for(int i=0;i<size;i++)
            delete heap[i];
    }
};

int main(){
    MaxHeap h;

    h.insert("Ali",101,5);
    h.insert("Ahmed",102,9);
    h.insert("Sara",103,3);
    h.insert("Usman",104,10);
    h.insert("Ayesha",105,7);
    h.insert("Hassan",106,8);

    cout<<"All Patients:\n";
    h.display();

    h.highestPriority();

    h.deletePatient();

    cout<<"\nUpdated Patient Heap:\n";
    h.display();

    h.nextPatient();

    return 0;
}

