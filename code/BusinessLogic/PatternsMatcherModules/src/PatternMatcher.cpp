#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"

#include <algorithm>

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
    while (moduleRunning) {

        if (!dataBuffer.empty()) {
            const auto data = dataBuffer.front();
            dataBuffer.pop();
            const auto patternPos = std::search(data.begin(), data.end(), goalPattern.begin(), goalPattern.end());


            // Si se ha encontrado el patrón, enviar los datos al siguiente módulo
            if (patternPos != data.end()) {
                dataReceiver->sendData(data);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Esperar 100 ms
    }
}

bool PatternMatcher::isRunning()
{
    return moduleRunning;
}

const std::vector<int>& PatternMatcher::getPattern() const {
    return goalPattern;
}