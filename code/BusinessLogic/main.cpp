#include "code/BusinessLogic/IModule/inc/IModule.h"
#include "code/BusinessLogic/PatternsMatcherModules/inc/ArrayGenerator.h"
#include "code/BusinessLogic/PatternsMatcherModules/inc/PatternMatcher.h"
#include "code/BusinessLogic/PatternsMatcherModules/inc/DataRecorder.h"
#include <iostream>

int main(void) {
    std::cout << "Start of programm\n";

    //Create modules
    IModule *m1 = new ArrayGenerator();
    IModule *m2 = new PatternMatcher();
    IModule *m3 = new DataRecorder();

    //Set m1 to deliver data to m2
    m1->setDataReceiver(m2);

    //Set m2 to deliver data to m3
    m2->setDataReceiver(m3);

    //Start modules
    m1->start();
    m2->start();
    m3->start();

    //Wait 100 seconds
    std::this_thread::sleep_for(std::chrono::seconds(100));

    //Stop modules
    m1->stop();
    m2->stop();
    m3->stop();

    //Release modules

    delete m1;
    delete m2;
    delete m3;

    std::cout << "End of programm\n";
    return 0;
}