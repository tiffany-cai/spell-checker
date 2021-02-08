//  Tiffany Cai
//  double_probing.h
//  This class is an inheritted class from QuadraticProbing.
//It will implement double probing.  FindPos is changed to follow how double probing works.
//

#ifndef double_probing_h
#define double_probing_h

#include "quadratic_probing.h"
#include <vector>
#include <algorithm>
#include <functional>

// Double hashing/probing implementation.
template <typename HashedObj>
class HashTableDouble : public HashTable <HashedObj>
{
protected:
    //double probing inherits quadratic probing functions
    //FindPos is overridden.
    //this->x is used bc we are overriding a function using polymorphism
    size_t FindPos(const HashedObj & x) const override {
        size_t offset = InternalHash_2(x);
        size_t current_pos = this->InternalHash(x);

        while (this->array_[current_pos].info_ != this->EMPTY && this->array_[current_pos].element_ != x) {
            //added, num of collisions go up until x is found
            this->number_of_collisions_++;
            current_pos += offset;  // Compute ith probe.
            //offset += 2;
            if (current_pos >= this->array_.size())
                current_pos -= this->array_.size();
        }
        return current_pos;
    }
    
    size_t InternalHash_2(const HashedObj & x) const
    {
        static std::hash<HashedObj> hash;
        return 73 - (hash(x) % 73); //hash function r - (x mod r)
    }
    
};
#endif /* double_probing_h */
