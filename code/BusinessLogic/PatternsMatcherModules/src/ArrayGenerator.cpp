#include "code/BusinessLogic/PatternsMatcherModules/inc/ArrayGenerator.h"

#include <chrono>
#include <random>

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

void ArrayGenerator::setDataReceiver(IModule *dataReceiver_0)
{
    dataReceiver = dataReceiver_0;
}

void ArrayGenerator::runThread()
{
    lastGeneratedArray = randomArrayGenerator();

    if (dataReceiver) {
        dataReceiver->sendData(lastGeneratedArray);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool ArrayGenerator::isRunning()
{
    return moduleRunning;
}

const std::vector<int>& ArrayGenerator::getLastGeneratedArray() const
{
    return lastGeneratedArray;
}

std::vector<int> ArrayGenerator::randomArrayGenerator()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_int_distribution<> dis(1, 100);
    int arrayLength = dis(gen);

    std::uniform_int_distribution<> dis_data(0, 255);

    std::vector<int> arrayGenerated(arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        arrayGenerated[i] = dis_data(gen);
    }
    return arrayGenerated;
}