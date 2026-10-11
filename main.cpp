#include <iostream>
#include <STL.hpp>
using namespace std;

int main(){
    vector<int> x = {1, 2, 3, 4, 5};
    std :: cout << x << std :: endl;

    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_front(5);
    q.push_front(6);
    q.pop_back();
    q.pop_front();

    cout << q << endl;
}