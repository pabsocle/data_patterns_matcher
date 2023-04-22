#include "gtest/gtest.h"

#include "code/UnitTests/DataPatternsMatcher/ArrayGeneratorTests.cpp"
#include "code/UnitTests/DataPatternsMatcher/PatternMatcherTests.cpp"
#include "code/UnitTests/DataPatternsMatcher/DataRecordertests.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}