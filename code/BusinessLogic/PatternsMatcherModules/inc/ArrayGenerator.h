#include "code/BusinessLogic/IModule/inc/IModule.h"

#include <thread>
#include <vector>

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
    private:
        IModule* dataReceiver;
        bool moduleRunning;
        std::vector<int> lastGeneratedArray;
        std::thread moduleThread;

        void runThread();
};