#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"


void ArrayGenerator::start()
{
    moduleRunning = true;
    moduleThread = std::thread(&ArrayGenerator::runThread, this);
}

void ArrayGenerator::stop()
{
    moduleRunning = false;
     if (moduleThread.joinable()) {
        moduleThread.join();
    }
}

bool PatternMatcher::isRunning()
{
    return moduleRunning;
}

const std::vector<uint8_t>& PatternMatcher::getPattern() const {
    return goalPattern;
}