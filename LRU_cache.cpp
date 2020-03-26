#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class LRU_cache
{
    int csize; // capacity of cache
    deque <int> cache;
    deque<int>::iterator it; 
    public:
        LRU_cache(int);
        void display();
        void refer(int);

};

LRU_cache::LRU_cache(int n){
    csize = n;
};
void LRU_cache::display(){

    for(it=cache.begin(); it!=cache.end();++it){
        cout << "\t" << *it;
    }
    cout << "\n";
};

void LRU_cache::refer(int n){
    it = find(cache.begin(), cache.end(), n);

    // found
    if(it!=cache.end()){
        cache.erase(it);
        
    }
    // not found
    else{
        if(cache.size() >= csize){
            cache.pop_front();
        }

    }
    cache.push_back(n);
   
}

int main(){
    LRU_cache ca(3);
    ca.refer(3);
    ca.refer(2);
    ca.refer(1);
    ca.display();

    ca.refer(2);
    ca.display();
    ca.refer(8);
    ca.display();

    return 0;
}
