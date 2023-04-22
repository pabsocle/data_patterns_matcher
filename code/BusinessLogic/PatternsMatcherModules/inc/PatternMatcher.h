#ifndef PATTERNMATCHER_H
#define PATTERNMATCHER_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

#include <thread>
#include <queue>

class PatternMatcher : public :: IModule
{
    public:
        PatternMatcher(){}
        ~PatternMatcher(){}
        void start() override;
        void stop() override;
        void setDataReceiver(IModule* dataReceiver_0) override;
        bool isRunning();
        const std::vector<int>& getPattern() const;
    protected:
        void receiveData(const std::vector<int>& dataGenerated, int size) override;
    private:
        IModule* dataReceiver;
        std::vector<int> lastReceivedArray;
        std::queue<std::vector<int>> dataBuffer;
        bool moduleRunning;
        std::vector<int> goalPattern = {0x00, 0x01, 0x02};

        std::thread moduleThread;

        void runThread();
};

#endif // PATTERNMATCHER_H