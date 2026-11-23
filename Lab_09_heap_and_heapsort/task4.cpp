
#include<iostream>
#include<queue>
using namespace std;

class Medicine{
public:
    string name;
    int id;
    int expiry;
    Medicine* left;
    Medicine* right;

    Medicine(string n,int i,int e){
        name=n;
        id=i;
        expiry=e;
        left=NULL;
        right=NULL;
    }
};

class MinHeap{
    Medicine* heap[100];
    int size;

public:
    MinHeap(){
        size=0;
    }

    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;

            if(heap[i]->expiry<heap[parent]->expiry){
                swap(heap[i],heap[parent]);
                i=parent;
            }
            else{
                break;
            }
        }
    }

    void updatePointers(){
        for(int i=0;i<size;i++){
            heap[i]->left=(2*i+1<size)?heap[2*i+1]:NULL;
            heap[i]->right=(2*i+2<size)?heap[2*i+2]:NULL;
        }
    }

    void insert(string name,int id,int expiry){
        Medicine* m=new Medicine(name,id,expiry);

        heap[size]=m;
        heapifyUp(size);
        size++;

        updatePointers();
    }

    void display(){
        if(size==0){
            cout<<"No medicines available"<<endl;
            return;
        }

        queue<Medicine*> q;
        q.push(heap[0]);

        while(!q.empty()){
            Medicine* temp=q.front();
            q.pop();

            cout<<"Name: "<<temp->name
                <<" ID: "<<temp->id
                <<" Expiry: "<<temp->expiry<<endl;

            if(temp->left!=NULL)
                q.push(temp->left);

            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }

    void heapifyDown(int i){
        while(true){
            int smallest=i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<size && heap[left]->expiry<heap[smallest]->expiry)
                smallest=left;

            if(right<size && heap[right]->expiry<heap[smallest]->expiry)
                smallest=right;

            if(smallest!=i){
                swap(heap[i],heap[smallest]);
                i=smallest;
            }
            else{
                break;
            }
        }
    }

    void deleteNearestExpiry(){
        if(size==0){
            cout<<"No medicines available"<<endl;
            return;
        }

        cout<<"\nMedicine with Nearest Expiry:\n";
        cout<<"Name: "<<heap[0]->name<<endl;
        cout<<"ID: "<<heap[0]->id<<endl;
        cout<<"Expiry: "<<heap[0]->expiry<<endl;

        delete heap[0];

        heap[0]=heap[size-1];
        size--;

        if(size>0)
            heapifyDown(0);

        updatePointers();
    }

    ~MinHeap(){
        for(int i=0;i<size;i++)
            delete heap[i];
    }
};

int main(){
    MinHeap h;

    h.insert("Panadol",101,20261215);
    h.insert("Brufen",102,20261120);
    h.insert("Augmentin",103,20271010);
    h.insert("Disprin",104,20260515);
    h.insert("Calpol",105,20270125);
    h.insert("Caflam",106,20260910);

    cout<<"All Medicines:\n";
    h.display();

    h.deleteNearestExpiry();

    cout<<"\nUpdated Medicine Heap:\n";
    h.display();

    return 0;
}

