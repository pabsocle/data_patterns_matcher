#include "code/BusinessLogic/PatternsMatcherModules/inc/ArrayGenerator.h"

void ArrayGenerator::start()
{
    moduleRunning = true;
    moduleThread = std::thread(&ArrayGenerator::runThread, this);
}

void ArrayGenerator::stop()
{
    moduleRunning = false;
}

void ArrayGenerator::setDataReceiver(IModule *dataReceiver_0)
{
    dataReceiver = dataReceiver_0;
}

void ArrayGenerator::runThread()
{
    
}

bool ArrayGenerator::isRunning()
{
    return moduleRunning;
}

const std::vector<int>& ArrayGenerator::getLastGeneratedArray() const
{
    return lastGeneratedArray;
}