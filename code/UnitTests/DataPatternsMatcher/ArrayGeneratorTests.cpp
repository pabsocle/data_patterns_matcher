#include "gtest/gtest.h"

#include "code/BusinessLogic/PatternsMatcherModules/inc/ArrayGenerator.h"

class GIVENAnArrayGenerator : public testing::Test
{
    protected:
        ArrayGenerator* sutArrayGenerator = nullptr;
    public:
    GIVENAnArrayGenerator()
    {
        sutArrayGenerator = new ArrayGenerator();
    }

    ~GIVENAnArrayGenerator()
    {
        delete sutArrayGenerator;
    }
};

TEST_F(GIVENAnArrayGenerator, WHENGenerateArrayIsCreatedTHENRUnThreadIsNotRunning)
{
    //ARRANGE

    //ACT

    //ASSERT
    ASSERT_FALSE(sutArrayGenerator->isRunning());
}

TEST_F(GIVENAnArrayGenerator, WHENGenerateArrayIsStartedAndAfterStoppedTHENFirstRunThreadIsRunningAndAfterRunThreadIsNotRunning)
{
    //ARRANGE

    //ACT
    sutArrayGenerator->start();
    bool started = sutArrayGenerator->isRunning();
    
    sutArrayGenerator->stop();
    bool stopped = sutArrayGenerator->isRunning();

    //ASSERT
    EXPECT_TRUE(started);
    EXPECT_FALSE(stopped);
}


TEST_F(GIVENAnArrayGenerator, WHENGenerateArrayThreadRunsTHENOneArrayOfRandomLengthBetween1To100IsCreated)
{
    //ARRANGE

    //ACT
    sutArrayGenerator->start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sutArrayGenerator->stop();

    //ASSERT
    const std::vector<int>& generatedArray = sutArrayGenerator->getLastGeneratedArray();
    ASSERT_GE(generatedArray.size(), 1);
    ASSERT_LE(generatedArray.size(), 100);
}

TEST_F(GIVENAnArrayGenerator, WHENGenerateArrayThreadRunsTHENDataOfCreatedArrayOfIsBetween0To255)
{
    //ARRANGE

    //ACT

    //ASSERT
}

TEST_F(GIVENAnArrayGenerator, WHENGenerateArrayThreadRunsTHENArrayIsCreatedAndPassedToNextIModule)
{
    //ARRANGE

    //ACT

    //ASSERT
}