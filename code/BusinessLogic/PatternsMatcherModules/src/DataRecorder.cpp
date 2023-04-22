#include "code/BusinessLogic/PatternsMatcherModules/inc/DataRecorder.h"

void DataRecorder::start()
{
    moduleRunning = true;
    moduleThread = std::thread(&DataRecorder::runThread, this);
}

void DataRecorder::stop()
{
    moduleRunning = false;
    if (moduleThread.joinable()) {
        moduleThread.join();
    }
}

void DataRecorder::setDataReceiver(IModule* dataReceiver_0)
{
    dataReceiver = dataReceiver_0;
}

bool DataRecorder::isRunning() {
    return moduleRunning;
}

void DataRecorder::receiveData(const std::vector<int>& dataGenerated, int size)
{
    if (inputBuffer.size() < MAX_RECORDS) {
        inputBuffer.push(dataGenerated);
    }
}

void DataRecorder::runThread()
{

}