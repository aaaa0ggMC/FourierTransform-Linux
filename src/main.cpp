#include <gtest/gtest.h>
#include "app.h"

int main(void){
    //// Support For Google Test
    testing::InitGoogleTest();

    //// Application
    MainApplication app;
    // Setup Application,May provide more params
    app.setup();
    app.run();

    return app.return_val;
}