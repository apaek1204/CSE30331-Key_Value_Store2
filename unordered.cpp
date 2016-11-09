// unordered.cpp: Unordered Map

#include "map.h"

#include <algorithm>

// Methods --------------------------------------------------------------------

void            UnorderedMap::insert(const std::string &key, const std::string &value) {
    if( entries.find(key) == entries.end() ){
        entries.insert({key, value});
    }
    else{
        (entries.find(key))->second = value;
    }
}

const Entry     UnorderedMap::search(const std::string &key) {
    auto result = entries.find(key);
    if( result != entries.end() ){
        return Entry{ result->first, result->second };
    }
    else{
        return NONE;
    }
}

void            UnorderedMap::dump(std::ostream &os, DumpFlag flag) {
    for(auto i=entries.begin(); i!=entries.end(); ++i){
        switch(flag){
            case DUMP_KEY:
                os << i->first;
                break;
            case DUMP_VALUE:
                os << i->second;
                break;
            case DUMP_KEY_VALUE:
                os << i->first << "\t\t" << i->second;
                break;
            case DUMP_VALUE_KEY:
                os << i->second << "\t\t" << i->first;
                break;
        }
        os << std::endl;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
