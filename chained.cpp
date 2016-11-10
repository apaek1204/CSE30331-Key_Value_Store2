// chained.cpp: Separate Chaining Map

#include "map.h"
#include <iostream>
#include <stdexcept>
#include <map>

// Methods --------------------------------------------------------------------

void            ChainedMap::insert(const std::string &key, const std::string &value) {
    if( (float)(items/size) > load_factor ){
        resize(size * 2);
    }
    int place = hfunc(key);
    place = place % size;
    if( entries[place].find(key) != entries[place].end() ){
        entries[place][key] = value;
    }
    else{
        entries[place].insert( {key, value} );
    }
    items++;
}

const Entry     ChainedMap::search(const std::string &key) {
    int place = hfunc(key);
    place = place % size;
    if( entries[place].find(key) != entries[place].end() ){
        return Entry{ key, entries[place][key] };
    }
    else{
        return NONE;
    }
}

void            ChainedMap::dump(std::ostream &os, DumpFlag flag) {
    for(size_t m=0; m<size; m++){
        for(auto i : entries[m]){
            switch(flag){
                case(DUMP_KEY):
                    os << i.first;
                    break;
                case(DUMP_VALUE):
                    os << i.second;
                    break;
                case(DUMP_KEY_VALUE):
                    os << i.first << "\t\t" << i.second;
                    break;
                case(DUMP_VALUE_KEY):
                    os << i.second << "\t\t" << i.first;
                    break;
            }
            os << std::endl;
        }
    }
}

void            ChainedMap::resize(const size_t new_size) {
    std::map<std::string, std::string> *old_entries = new std::map<std::string, std::string>[size];
    std::copy(entries, entries+size, old_entries);
    delete [] entries;
    size_t old_size = size;
    size = new_size;
    entries = new std::map<std::string, std::string>[size];
    for(size_t i=0; i<old_size; i++){
        for(auto m: old_entries[i]){
            insert(m.first, m.second);
        }
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
