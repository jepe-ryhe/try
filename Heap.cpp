#include<iostream>
using namespace std;
template <class T>
class Heap{
public:
    T* heap;
    int size;
    int maxsize;
    Heap(T* array,int num,int max){
        heap = array;
        size = num;
        maxsize = max;
    }
    void build(){
        for(int i = size/2-1;i >= 0;i--){
            shift(i);
        }
    }
    void shift(int left){
        int i = left;
        int j = 2*i+1;
        T t = heap[i];
        while(j < size){
            if((j < size-1)&&(heap[j] < heap[j+1]))
                j++;
            if(t < heap[j]){
                heap[i] = heap[j];
                i = j;
                j = 2*j+1;
            }else
                break;
        }
        heap[i] = t;
    }
    void remove(){
        if(size == 0){
            return;
        }else{
            T t = heap[0];
            heap[0] = heap[size-1];
            size--;
            if(size > 1)
                shift(0);
            return;
        }
    }
    void insert(T t){
        if(size == maxsize){
            return;
        }else{
            heap[size] = t;
            size++;
            build();
        }
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout<<heap[i]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    int arr[11] = {20,12,35,15,10,80,30,17,2,1};
    Heap<int> h(arr,10,11);
    h.print();
    h.build();
    h.print();
    h.insert(31);
    h.print();
    h.remove();
    h.print();
}
