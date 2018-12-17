
#include <gmock/gmock.h>
#include "RetweetCollection.h"
using namespace testing;

class ARetweetCollection: public Test{
public:
    RetweetCollection collection;
};

TEST(ARetweetCollection, IsEmptyWhenCreated)
{
    RetweetCollection collection;
    ASSERT_TRUE(collection.isEmpty());
}

TEST(ARetweetCollection, HasSizeZeroWhenCreated)
{
    RetweetCollection collection;
    ASSERT_THAT(collection.size(), Eq(0u));
}


