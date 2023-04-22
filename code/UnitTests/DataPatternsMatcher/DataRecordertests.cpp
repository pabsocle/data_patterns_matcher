#include <gtest/gtest.h>

#include "code/BusinessLogic/PatternsMatcherModules/inc/DataRecorder.h"

class GIVENADataRecorder : public testing::Test
{
    protected:
        DataRecorder* sutDataRecorder = nullptr;
    public:
    GIVENADataRecorder()
    {
        sutDataRecorder = new DataRecorder();
    }

    ~GIVENADataRecorder()
    {
        delete sutDataRecorder;
    }
};

TEST_F(GIVENADataRecorder, RunThreadNotStarted)
{
    ASSERT_FALSE(sutDataRecorder->isRunning());
}

TEST_F(GIVENADataRecorder, WHENDataRecorderIsStartedAndAfterStoppedTHENFirstRunThreadIsRunningAndAfterRunThreadIsNotRunning)
{
    //ARRANGE

    //ACT
    sutDataRecorder->start();
    bool started = sutDataRecorder->isRunning();
    sutDataRecorder->stop();
    bool stopped = sutDataRecorder->isRunning();

    //ASSERT
    EXPECT_TRUE(started);
    EXPECT_FALSE(stopped);
}

TEST_F(GIVENADataRecorder, WHENAVectorIsReceivedTHENItIsStoredAndPrintedWithUTCTime)
{
    //ARRANGE
    std::vector<int> dataReceived1 = {0x01, 0x02, 0x03, 0x02, 0xFF};
    std::vector<int> dataReceived2 = {0x04, 0x05, 0x06};
    std::vector<int> dataReceived3 = {0x07, 0x08, 0x09, 0x0A};
    
    //ACT
    sutDataRecorder->start();
    testing::internal::CaptureStdout();

    sutDataRecorder->sendData(dataReceived1);
    sutDataRecorder->sendData(dataReceived2);
    sutDataRecorder->sendData(dataReceived3);

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(output.find("[0x01, 0x02, 0x03, 0x02, 0xFF]"), std::string::npos);
    ASSERT_NE(output.find("[0x04, 0x05, 0x06]"), std::string::npos);
    ASSERT_NE(output.find("[0x07, 0x08, 0x09, 0x0A]"), std::string::npos);

    std::string output = testing::internal::GetCapturedStdout();

    sutDataRecorder->stop();

    //ASSERT

}