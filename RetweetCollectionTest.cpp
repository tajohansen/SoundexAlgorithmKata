
#include <gmock/gmock.h>
#include "RetweetCollection.h"
#include "Tweet.h"

using namespace testing;

class ARetweetCollection: public Test{
public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
    RetweetCollection collection;
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
    RetweetCollection collection;
    ASSERT_THAT(collection.size(), Eq(0u));
}
TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}
TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{
    ASSERT_THAT(collection.size(),Eq(0u));
    ASSERT_TRUE(collection.isEmpty());
}
TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsNonZero)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(),Gt(0u));
    ASSERT_FALSE(collection.isEmpty());
}

class ARetweetCollectionWithOneTweet : public  Test
{
public:
    RetweetCollection collection;
    void SetUp() override
    {
        collection.add(Tweet());
    }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty)
{
    ASSERT_FALSE(collection.isEmpty());
}
TEST_F(ARetweetCollectionWithOneTweet, HasSizeofOne)
{
    ASSERT_THAT(collection.size(), Eq(1u));
}


