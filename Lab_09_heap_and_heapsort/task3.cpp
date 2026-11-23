
#include<iostream>
using namespace std;

class Order{
public:
    int id;
    string name;
    int amount;
    Order* left;
    Order* right;

    Order(int i,string n,int a){
        id=i;
        name=n;
        amount=a;
        left=NULL;
        right=NULL;
    }
};

class MaxHeap{
    Order* heap[100];
    int size;
    int sorted[100];
    int count;

public:
    MaxHeap(){
        size=0;
        count=0;
    }

    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;

            if(heap[i]->amount>heap[parent]->amount){
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

    void insert(int id,string name,int amount){
        Order* o=new Order(id,name,amount);

        heap[size]=o;
        heapifyUp(size);
        size++;

        updatePointers();
    }

    void heapifyDown(int i){
        while(true){
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<size && heap[left]->amount>heap[largest]->amount)
                largest=left;

            if(right<size && heap[right]->amount>heap[largest]->amount)
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

    void heapSort(){
        while(size>0){
            sorted[count]=heap[0]->amount;
            count++;

            delete heap[0];

            heap[0]=heap[size-1];
            size--;

            if(size>0)
                heapifyDown(0);

            updatePointers();
        }
    }

    void displaySorted(){
        cout<<"\nOrders in Ascending Order:\n";

        for(int i=count-1;i>=0;i--){
            cout<<sorted[i]<<" ";
        }

        cout<<endl;
    }

    ~MaxHeap(){
        for(int i=0;i<size;i++)
            delete heap[i];
    }
};

int main(){
    MaxHeap h;

    h.insert(101,"Ali",5000);
    h.insert(102,"Ahmed",2500);
    h.insert(103,"Sara",7000);
    h.insert(104,"Usman",1500);
    h.insert(105,"Ayesha",4000);
    h.insert(106,"Hassan",6000);

    h.heapSort();

    h.displaySorted();

    return 0;
}

