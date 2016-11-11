// open.cpp: Open Addressing Map

#include "map.h"

#include <stdexcept>
using namespace std;
// Methods --------------------------------------------------------------------

OpenMap::OpenMap(size_t s, double lf){
    items =0;   
    size=0;
    load_factor = lf;
    table= new Entry[s];
    size = s;
}
OpenMap::~OpenMap(){
    delete [] table;   
}
void OpenMap::insert(const std::string &key, const std::string &value) {
    
    if((double)(items/size) > load_factor){
        resize(size *2);
    }

    int bucket;
    bucket = locate(key);
    //if key already exists, update
    if(table[bucket]!=NONE){
        table[bucket].second = value;
    }
    //if key doesnt exist, insert
    else{
        table[bucket] = pair<string, string>(key, value);
    }
    items ++;
}

const Entry OpenMap::search(const std::string &key) {
    for(size_t i=0; i<size; i++){
        if(table[i]!=NONE){
            if(table[i].first == key){
                return table[i];
            }
        }
    }
    return NONE;
}

void OpenMap::dump(std::ostream &os, DumpFlag flag) {
    for(size_t i=0; i<size; i++){
        
        switch(flag){
            case(DUMP_KEY):
                os << table[i].first;
                break;
            case(DUMP_VALUE):
                os << table[i].second;
                break;
            case(DUMP_KEY_VALUE):
                os << table[i].first << "\t\t" << table[i].second;
                break;
            case(DUMP_VALUE_KEY):
                os << table[i].second << "\t\t" << table[i].first;
                break;
        }
        os << std:: endl;
    }
}

size_t OpenMap::locate(const std::string &key) {
    size_t bucket = hfunc(key);
    bucket = bucket % size;
    
    if(table[bucket]==NONE || table[bucket].first == key){
        return bucket;
    }
    else{
        int i = bucket;
        //increment till find key or find empty bucket
        while(table[i]!=NONE){
            i++;
            i = i % size;
            if(table[i].first == key){
                return i;
            }
        }
        return i;
    }
    //if out here, then no empty buckets, so resize and then recall function
    resize(size * 2);
    return locate(key);
}

void OpenMap::resize(const size_t new_size) {
    Entry *old_table=table;
    
    delete [] table;
    table = new Entry[new_size];
    if(items){
        for(size_t i=0; i<size; i++){
            if(old_table[i]!=NONE){
                insert(old_table[i].first, old_table[i].second);
            }
        }
    }
    size = new_size;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
