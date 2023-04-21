#ifndef IMODULEMOCK_H
#define IMODULEMOCK_H

#include "code/BusinessLogic/IModule/inc/IModule.h"

#include "gmock/gmock.h"

class IModuleMock : public IModule
{
    public:
        MOCK_METHOD(void, start, (), (override));
        MOCK_METHOD(void, stop, (), (override));
        MOCK_METHOD(void, setDataReceiver, (IModule*), (override));
        MOCK_METHOD(void, receiveData, (const std::vector<int>&, int), (override));
};


#endif // IMODULEMOCK_H