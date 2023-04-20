#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

#include <thread>

class ArrayGenerator : public :: IModule
{
    public:
        ArrayGenerator() : dataReceiver(nullptr),  moduleRunning(false) {}
        ~ArrayGenerator(){}
        void start() override;
        void stop() override;
        void setDataReceiver(IModule* dataReceiver_0) override;
        bool isRunning();
        const std::vector<int>& getLastGeneratedArray() const;
    protected:
            void receiveData(const std::vector<int>* data, int size) override {}
    private:
        IModule* dataReceiver;
        bool moduleRunning;
        std::vector<int> lastGeneratedArray;
        std::thread moduleThread;

        void runThread();
        std::vector<int> randomArrayGenerator();
};

#endif // ARRAYGENERATOR_H