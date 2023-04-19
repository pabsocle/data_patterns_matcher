#ifndef IMODULE_H
#define IMODULE_H

class IModule {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void setDataReceiver(IModule *dataReceiver) = 0;

};

#endif // IMODULE_H