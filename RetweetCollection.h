//
// Created by troyjohansen on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_RETWEETCOLLECTION_H
#define FIRSTEXAMPLE_RETWEETCOLLECTION_H

#include "Tweet.h"
#include <set>

class RetweetCollection
        {
private:
    unsigned  int size_;
    //Container that stores unique elements following a specific order
    set<Tweet> tweets;

public:
    RetweetCollection();

    bool  isEmpty () const;
    unsigned  int size() const;
    void add(const Tweet& tweet);



};


#endif //FIRSTEXAMPLE_RETWEETCOLLECTION_H
