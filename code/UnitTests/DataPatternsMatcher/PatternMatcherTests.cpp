#include "gtest/gtest.h"

#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"

#include "code/UnitTests/DataPatternsMatcher/IModuleMock.h"

class GIVENAPatternMatcher : public testing::Test
{
    protected:
        PatternMatcher* sutPatternMatcher = nullptr;
    public:
    GIVENAPatternMatcher()
    {
        sutPatternMatcher = new PatternMatcher();
    }

    ~GIVENAPatternMatcher()
    {
        delete sutPatternMatcher;
    }
};

TEST_F(GIVENAPatternMatcher, WHENPatternMatcherIsCreatedTHENRUnThreadIsNotRunningAndPatternIsInitialized)
{
    //ARRANGE
    std::vector<int> pattern = {0x00, 0x01, 0x02};

    //ACT

    //ASSERT
    ASSERT_FALSE(sutPatternMatcher->isRunning());
    ASSERT_EQ(pattern, sutPatternMatcher->getPattern());
}

TEST_F(GIVENAPatternMatcher, WHENGenerateArrayIsStartedAndAfterStoppedTHENFirstRunThreadIsRunningAndAfterRunThreadIsNotRunning)
{
    //ARRANGE

    //ACT
    sutPatternMatcher->start();
    bool started = sutPatternMatcher->isRunning();
    
    sutPatternMatcher->stop();
    bool stopped = sutPatternMatcher->isRunning();

    //ASSERT
    EXPECT_TRUE(started);
    EXPECT_FALSE(stopped);
}

TEST_F(GIVENAPatternMatcher, WhenDataIsReceivedIfThereIsAMatchWithPatternTHENArrayIsSentToNextModule)
{
    //ARRANGE
    std::vector<int> dataReceived = {0x03, 0x04, 0x05, 0x06, 0x00, 0x01, 0x02, 0x07, 0x08, 0x09};
    IModuleMock dataReceiverMock;
    sutPatternMatcher->setDataReceiver(&dataReceiverMock);

    EXPECT_CALL(dataReceiverMock, receiveData)
        .Times(1);

    //ACT
    sutPatternMatcher->start();
    sutPatternMatcher->sendData(dataReceived);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    sutPatternMatcher->stop();

    //ASSERT
}

TEST_F(GIVENAPatternMatcher, WhenDataIsReceivedIfThereIsNoMatchWithPatternTHENArrayIsNotSentToNextModule)
{
    //ARRANGE
    std::vector<int> dataReceived = {0x03, 0x04, 0x05, 0x06, 0x00, 0x01, 0x01, 0x07, 0x08, 0x09};
    IModuleMock dataReceiverMock;
    sutPatternMatcher->setDataReceiver(&dataReceiverMock);

    EXPECT_CALL(dataReceiverMock, receiveData)
        .Times(0);

    //ACT
    sutPatternMatcher->start();
    sutPatternMatcher->sendData(dataReceived);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    sutPatternMatcher->stop();

    //ASSERT
}