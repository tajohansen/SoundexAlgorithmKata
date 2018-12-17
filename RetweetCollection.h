//
// Created by troyjohansen on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_RETWEETCOLLECTION_H
#define FIRSTEXAMPLE_RETWEETCOLLECTION_H

#include "Tweet.h"

class RetweetCollection {
private:
    unsigned  int size_;
public:
    bool  isEmpty () const;
    unsigned  int size() const;
    void add(const Tweet& tweet);

};


#endif //FIRSTEXAMPLE_RETWEETCOLLECTION_H
