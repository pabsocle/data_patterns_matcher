#include "code/BusinessLogic/PatternsMatcherModules/inc/DataRecorder.h"

#include <iostream>
#include <set>
#include <iomanip>

DataRecorder::DataRecorder(): dataReceiver(nullptr), moduleRunning(false){}
DataRecorder::~DataRecorder(){}

void DataRecorder::start()
{
    moduleRunning = true;
    moduleThread = std::thread(&DataRecorder::runThread, this);
}

void DataRecorder::stop()
{
    moduleRunning = false;
    if (moduleThread.joinable())
    {
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
    if (inputBuffer.size() < MAX_RECORDS)
    {
        inputBuffer.push(dataGenerated);
    }
}

void DataRecorder::runThread()
{
    while(moduleRunning)
    {
        if(!inputBuffer.empty())
        {
            getPendingData();
            printRecords();
            std::this_thread::sleep_for(std::chrono::milliseconds(delayThreadMilliseconds));
        }
    }
}

void DataRecorder::getPendingData()
{
    auto pendingData = inputBuffer.front();
    inputBuffer.pop();
    auto pendingDataTime = std::chrono::system_clock::now();
    dataRecords.emplace_back(pendingDataTime, pendingData);
}

void DataRecorder::printRecords()
{
    std::set<std::pair<std::chrono::system_clock::time_point, std::vector<int>>> orderedRecords(dataRecords.begin(), dataRecords.end());
    std::cout << "Records:\n";
    for (const auto& record : orderedRecords)
    {
        std::time_t time = std::chrono::system_clock::to_time_t(record.first);
        std::cout << std::ctime(&time) << "[";
        int count = 0;
        for (const auto& value : record.second)
        {
            std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0')<< std::uppercase << static_cast<int>(value);
            count ++;
            if (count != record.second.size())
            {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }
}

const std::vector<std::pair<std::chrono::system_clock::time_point, std::vector<int>>>& DataRecorder::getRecords() const
{
    return dataRecords;
}