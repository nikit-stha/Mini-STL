#include <iostream>

template <typename T>
class vector{
    int Capacity;
    int Size;

    T* data;

    void resize(){
        int oldCapacity = this->Capacity;
        this->Capacity *= 2;
        T* newData = new T[Capacity];

        for(int i = 0 ; i < oldCapacity ; i++){
            newData[i] = this->data[i];
        }

        T* temp = this->data;
        this->data = newData;

        delete[] temp;
    }

    int partition(int start, int end){
        int pivotElement = data[end];
        int idx = start - 1;

        for(int i = start ; i < end ; i++){
            if(this->data[i] <= pivotElement){
                idx++;
                std::swap(data[idx], data[i]);
            }
        }
        swap(this->data[++idx], this->data[end]);
        return idx;
    }

    void quickSortHelper(int start, int end){
        if(start >= end)
            return;
        
        int pivot = partition(start, end);
        quickSortHelper(start, pivot - 1);
        quickSortHelper(pivot + 1, end);
    }

    public:
        vector();
        vector(int Capacity);
        vector(int Capacity, T value);
        
        template<typename... Args>
        vector(Args... args);

        void push_back(const T &value);
        void pop_back();
        void push_front(T value);
        void pop_front();
        bool empty();
        int size();
        int capacity();
        void insert(T value, int index);
        void remove(int index);
        void sort();
        void sort(int start, int end);
        void reverse();
        void reverse(int start, int end);

        T operator[](int index);
        vector<T> operator+(vector &other);

        T* begin();
        T* end();
};

template <typename T>
vector<T>::vector(){
    this->Capacity = 1;
    this->Size = 0;

    this->data = new T[Capacity];
}

template <typename T>
vector<T>::vector(int Capacity){
    this->Capacity = Capacity;
    this->Size = 0;

    this->data = new T[Capacity];
}

template <typename T>
vector<T>::vector(int Capacity, T value){
    this->Capacity = Capacity;
    this->Size = Capacity;

    this->data = new T[Capacity];
    for(int i = 0 ; i < Capacity ; i++){
        this->data[i] = value;
    }
}

template <typename T>
template<typename... Args>
vector<T>::vector(Args... args){
    this->Size = sizeof...(args);
    this->Capacity = this->Size;
    data = new T[Capacity];

    int i = 0;
    ((data[i++] = args), ...);
}

template <typename T>
void vector<T>::push_back(const T &value){
    if(this->Size == this->Capacity){
        this->resize();
    }
    this->data[Size++] = value;
}

template <typename T>
void vector<T>::pop_back(){
    if(this->empty()){
        throw std::runtime_error{"Vector is Empty"};
    } 
    this->Size--;
}

template <typename T>
void vector<T>::push_front(T value){
    if(this->Size == this->Capacity){
        this->resize();
    }
    for(int i = this->Size - 1 ; i >= 0 ; i--){
        this->data[i + 1] = this->data[i];
    }
    this->data[0] = value;
    this->Size++;
}

template <typename T>
void vector<T>::pop_front(){
    if(this->empty()){
        throw std::runtime_error{"Vector is Empty"};
    }
    for(int i = this->Size - 1 ; i > 0 ; i--){
        this->data[i - 1] = this->data[i];
    }
    this->Size--;
}

template <typename T>
bool vector<T>::empty(){
    return (this->size() == 0);
}

template <typename T>
int vector<T>::size(){
    return this->Size;
}

template <typename T>
int vector<T>::capacity(){
    return this->Capacity;
}

template <typename T>
void vector<T>::insert(T value, int index){
    if(index < 0 || index > this->Size){
        throw std::out_of_range{"Index out of range"};
    }
    if(this->Size == this->Capacity){
        resize();
    }
    for(int i = this->Size - 1 ; i >= index ; i--){
        this->data[i + 1] = this->data[i];
    }
    this->data[index] = value;
    this->Size++;
}

template <typename T>
void vector<T>::remove(int index){
    if(index < 0 || index > this->Size){
        throw std::out_of_range{"Index out of range"};
    }
    for(int i = index ; i < this->Size - 1 ; i++){
        this->data[i] = this->data[i+1];
    }
    this->Size--;
}

template <typename T>
void vector<T>::sort(){
    quickSortHelper(0, this->Size - 1);
}

template <typename T>
void vector<T>::sort(int start, int end){
    quickSortHelper(start, end);
}

template <typename T>
void vector<T>::reverse(){
    int start = 0, end = this->Size - 1;
    while(start <= end){
        swap(data[start++], data[end--]);
    }
}

template <typename T>
void vector<T>::reverse(int start, int end){
    if(start >= 0 && start < this->Size || end >= 0 && end < this->Size){
        while(start <= end){
            swap(data[start++], data[end--]);
        }
        return;
    }
    throw std::out_of_range{"Index out of range"};
}

template <typename T>
T vector<T>::operator[](int index){
    if(index < 0 || index > this->size()){
        throw std::out_of_range{"Index out of range"};
    }
    return data[index];
}

template <typename T>
vector<T> vector<T> :: operator+(vector<T> &other){
    vector<T> ans;

    for(int i = 0 ; i < this->size() ; i++){
        ans.push_back(this->data[i]);
    }

    for(int i = 0 ; i < other.size() ; i++){
        ans.push_back(other.data[i]);
    }

    return ans;
}

template <typename T>
T* vector<T> :: begin(){
    return data;
}

template <typename T>
T* vector<T> :: end(){
    return data + this->size();
}

template <typename T>
class stack{
    int Capacity;
    int Size;
    int Top;

    T* data;

    void resize(){
        int oldCapacity = this->Capacity;
        this->Capacity *= 2;
        T* newData = new T[Capacity];

        for(int i = 0 ; i < oldCapacity ; i++){
            newData[i] = this->data[i];
        }

        T* temp = this->data;
        this->data = newData;

        delete[] temp;
    }

    public:
        void push(T value);
        void pop();
        T top();
        bool empty();
        int size();
        int capacity();
};

template <typename T>
class queue{

};

template <typename T>
class deque{

};

template <typename T>
struct Node{
    T data;
    Node* nextNode;
};

template <typename T>
class LinkedList{
    Node<T>* head;
    Node<T>* tail;

    public:
        LinkedList();
        void push_back(T data);
        void push_front(T data);
        void pop_back();
        void pop_front();
        bool empty();
        int size();
        void insert(T value, int index);
        void remove(int index);
        void reverse();
        void reverse(int start, int end);
        void sort();
        void sort(int start, int end);

        T operator[] (int index);
        T front();
        T back();
};

int main(){
}