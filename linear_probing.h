//  Tiffany Cai
//  linear_probing.h
//  This class is an inheritted class from QuadraticProbing.
//  This will implement linear probing to handing collisions.  FindPos is the function that is changed because linear probing finds positions differently than quadratic probing.
//

#ifndef linear_probing_h
#define linear_probing_h

#include <vector>
#include <algorithm>
#include <functional>

// Linear probing implementation.
template <typename HashedObj>
class HashTableLinear : public HashTable <HashedObj>
{
protected:
    //linear probing inherits quadratic probing functions
    //FindPos is overridden.
    //this->x is used bc we are overriding a function using polymorphism
    size_t FindPos(const HashedObj & x) const override {
        size_t offset = 1;
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
    
};

#endif /* linear_probing_h */
