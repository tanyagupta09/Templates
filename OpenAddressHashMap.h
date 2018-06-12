/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OpenAddressHashMap.h
 * Author: rahulgupta
 *
 * Created on January 26, 2018, 6:22 PM
 */

#ifndef OPENADDRESSHASHMAP_H

inline uint64_t CharToInt(const char *, size_t keySize)
{
    // use some good hashing function for char *;
};

// only allows uint64_t as keys Idea is to have smallest possible map in the map
template <typename T, size_t maxNeighbours>

// The idea behind fixed size map is that once we are done inserting entries into it, we won't insert more.
// Also, can only be used when the HashFn will generate unique keys. In short, it is good only when a unique symbol 
// is used as key because we are going to use the key directly to translate the symbol to key
class StaticFixedSizeHashMap
{
    private:
        struct Pair
        {
            uint64_t key;
            T * key;
        };
        
        Pair *p;
public:
    StaticFixedSizeHashMap(size_t expectedNumerOfEntries);
    void build(const char * key, T * value);
    
    void buildComplete()
    {
        
    }
    
    // T* will be null when the key is not found.
    T* getValue(const uint64_t key);

private:
    size_t entryCount;
    
};

#define OPENADDRESSHASHMAP_H



#endif /* OPENADDRESSHASHMAP_H */

