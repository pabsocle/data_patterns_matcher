#include "gtest/gtest.h"

#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"

class GIVENAnPatternMatcher : public testing::Test
{
    protected:
        PatternMatcher* sutPatternMatcher = nullptr;
    public:
    GIVENAnPatternMatcher()
    {
        sutPatternMatcher = new PatternMatcher();
    }

    ~GIVENAnPatternMatcher()
    {
        delete sutPatternMatcher;
    }
};

TEST_F(GIVENAnPatternMatcher, WHENPatternMatcherIsCreatedTHENRUnThreadIsNotRunningAndPattern)
{
    //ARRANGE

    //ACT

    //ASSERT
    ASSERT_FALSE(sutPatternMatcher->isRunning());
}