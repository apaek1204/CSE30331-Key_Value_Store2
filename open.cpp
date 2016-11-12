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
    //cout << "in insert" << endl;
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
    //table[bucket] = Entry(key, value);
    items ++;
}

const Entry OpenMap::search(const std::string &key) { 
    size_t bucket = locate(key);
    return table[bucket];
    //return NONE;
}

void OpenMap::dump(std::ostream &os, DumpFlag flag) {
    //cout << "in dump " << endl;
    for(size_t i=0; i<size; i++){
        
        switch(flag){
            case(DUMP_KEY):
                if(table[i]!=NONE)
                    os << table[i].first;
                break;
            case(DUMP_VALUE):
                if(table[i] !=NONE)
                    os << table[i].second;
                break;
            case(DUMP_KEY_VALUE):
                if(table[i] != NONE)
                    os << table[i].first << "\t" << table[i].second;
                break;
            case(DUMP_VALUE_KEY):
                if(table[i] != NONE)
                    os << table[i].second << "\t" << table[i].first;
                break;
        }
        if(table[i] != NONE)
            os << std:: endl;
    }
}

size_t OpenMap::locate(const std::string &key) {
    //cout << "in locate " << endl;
    size_t bucket = hfunc(key);
    bucket = bucket % size;
    size_t i=0; 
    while(table[bucket]!=NONE && table[bucket].first!=key){
        bucket = (bucket+1) %size;
        i++;
        if(i==size){
            resize(size*2);
            return locate(key);
        }
    }
        
    return bucket;
}

void OpenMap::resize(const size_t new_size) {
    //cout << "in resize" << endl;
    size_t old_size = size;
    size = new_size;
    Entry *old_table = new Entry[old_size];
    copy(table, table+old_size, old_table);
    delete [] table;
    table = new Entry[new_size];
    for(size_t i=0; i<old_size; i++){
        if(old_table[i]!=NONE){
            insert(old_table[i].first, old_table[i].second);
        }
    }
    
    delete [] old_table;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
