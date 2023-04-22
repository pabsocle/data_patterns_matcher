#ifndef DATARECORDER_H
#define DATARECORDER_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

#include <thread>
#include <queue>

class DataRecorder : public :: IModule
{
    public:
        DataRecorder(): dataReceiver(nullptr), moduleRunning(false){}
        ~DataRecorder(){}
        void start() override;
        void stop() override;
        void setDataReceiver(IModule* dataReceiver_0) override;
        bool isRunning();

    protected:
        void receiveData(const std::vector<int>& dataGenerated, int size) override;

    private:
        IModule* dataReceiver;
        bool moduleRunning;
        std::queue<std::vector<int>> inputBuffer;
        std::vector<std::vector<int>> records;
        const int MAX_RECORDS = 100;
        std::thread moduleThread;

        void runThread();
};

#endif // DATARECORDER_H