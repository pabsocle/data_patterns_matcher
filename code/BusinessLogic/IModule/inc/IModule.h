#ifndef IMODULE_H
#define IMODULE_H

#include <vector>

class IModule {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void setDataReceiver(IModule* dataReceiver_0) = 0;
        virtual void sendData(const std::vector<int>& dataGenerated) { receiveData(dataGenerated, dataGenerated.size()); }
    protected:
        virtual void receiveData(const std::vector<int>& dataGenerated, int size) = 0;

};

#endif // IMODULE_H