#ifndef PATTERNMATCHER_H
#define PATTERNMATCHER_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

class PatternMatcher : public :: IModule
{
    public:
        PatternMatcher(){}
        ~PatternMatcher(){}
        void start() override;
        void stop() override;
        void setDataReceiver(IModule* dataReceiver_0) override;
        bool isRunning();
        const std::vector<uint8_t>& getPattern() const;
    protected:
        void receiveData(const std::vector<int>& dataGenerated, int size) override;
    private:
        bool moduleRunning;
        std::vector<int> goalPattern;

        std::thread moduleThread;

        void runThread();
};

#endif // PATTERNMATCHER_H