#include <functional> //for std::hash
#include <string>
#include <iostream>

using namespace std;

//hash maps for both id lookup and category lookup
//same structure, different string as keys

//find<inventoryid> -> unorderedmap<string inventoryID, productData data> 

//listInventory<category_string> -> unordered map<string category, list productData products>
//each type inherits from this template
template<typename keyType, typename valueType>
class hashMap{

private:

struct Entry {
    keyType key;
    valueType value;  
};
    vector<list<Entry>> buckets;
    int numElements;
    int capacity;

//basic hashing function, finds index given input key
int hashFunction(const keyType& k) const {
    return std::hash<Key>{}(k) % capacity;
}

void rehash() { //rehash if hashmap is too full (loadfactor over 3/4)
    int oldCapacity = capacity;
    capacity *= 2; // double the capacity
    vector<list<Entry>> newBuckets(capacity);

    for (int i = 0; i < oldCapacity; ++i) {
        for (const auto& entry : buckets[i]) {
            int newIndex = hashFunction(entry.key);
            newBuckets[newIndex].push_back(entry);
        }
    }
    buckets = move(newBuckets);
}

public:

//constructor function
hashMap(int initialCapacity = 1000): numElements(0), capacity(initialCapacity){
    buckets.resize(capacity);
}

void insert(const keyType& key, const valueType& value){
    if (numElements >= (capacity * 0.75)){ //rehash if num elements exceeds 3/4 load factor
        rehash(); //double capacity
    }

    int index = hashFunction(key); //get index value from hash function

    for (auto &entry: buckets[index]){
        if(entry.key == key){
            entry.value = value;
            return;
        }
    }
    buckets[index].push_back({key, value});
    numElements++; 
}

valueType* find(const keyType& key){
    int index = hashFunction(key);
    for(auto& entry: buckets[index]){
        if (entry.key == key){
            return &entry.value
        }
    }
    return nullptr;  //return null if item not found

}

void erase (const keyType& key){
    int index = hashFunction(key);
    auto& bucket = buckets[index];
    for(auto it = bucket.begin(); it!=bucket.end(); it++){
        if(it->key == key){
            bucket.erase(it);
            numElements--;
            return;
        }
    }
}

int size() const{
    return this->numElements;
}

bool empty() const{
    return this->numElements == 0;
}

};