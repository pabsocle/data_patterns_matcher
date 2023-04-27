#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"

#include <algorithm>

PatternMatcher::PatternMatcher(): dataReceiver(nullptr), moduleRunning(false){}
PatternMatcher::~PatternMatcher(){}

void PatternMatcher::start()
{
    moduleRunning = true;
    moduleThread = std::thread(&PatternMatcher::runThread, this);
}

void PatternMatcher::stop()
{
    moduleRunning = false;
    if (moduleThread.joinable()) {
        moduleThread.join();
    }
}

void PatternMatcher::setDataReceiver(IModule *dataReceiver_0)
{
    dataReceiver = dataReceiver_0;
}

void PatternMatcher::receiveData(const std::vector<int>& dataGenerated, int size)
{
    lastReceivedArray = dataGenerated;
    dataBuffer.push(dataGenerated);
}

void PatternMatcher::runThread()
{
    while (moduleRunning)
    {

        if (!dataBuffer.empty())
        {
            const auto data = dataBuffer.front();
            dataBuffer.pop();
            const auto patternPos = std::search(data.begin(), data.end(), goalPattern.begin(), goalPattern.end());
            
            if (patternPos != data.end())
            {
                dataReceiver->sendData(data);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(delayThreadMilliseconds));
    }
}

bool PatternMatcher::isRunning()
{
    return moduleRunning;
}

const std::vector<int>& PatternMatcher::getPattern() const
{
    return goalPattern;
}