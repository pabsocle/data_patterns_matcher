#ifndef DATARECORDER_H
#define DATARECORDER_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

#include <thread>
#include <queue>

class DataRecorder : public :: IModule
{
    public:
        DataRecorder();
        ~DataRecorder();
        void start() override;
        void stop() override;
        void setDataReceiver(IModule* dataReceiver_0) override;
        bool isRunning();
        const std::vector<std::pair<std::chrono::system_clock::time_point, std::vector<int>>>& getRecords() const;

    protected:
        void receiveData(const std::vector<int>& dataGenerated, int size) override;

    private:
        IModule* dataReceiver;
        bool moduleRunning;
        std::queue<std::vector<int>> inputBuffer;
        std::vector<std::pair<std::chrono::system_clock::time_point, std::vector<int>>> dataRecords;
        const int MAX_RECORDS = 100;
        std::thread moduleThread;
        const int delayThreadMilliseconds = 100;

        void runThread();
        void getPendingData();
        void printRecords();
};

#endif // DATARECORDER_H