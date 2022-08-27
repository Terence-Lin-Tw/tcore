#include "KeyValueStore_tests.hpp"

TEST_GROUP(common){
	void setup(){
    }

	void teardown(){
    }
};

TEST(common, timeStamp){
    printf("\n");
    printShortTimestamp();
    printf("\n");

	CHECK_EQUAL(1, 1);
}

TEST(common, Nothing){
	CHECK_EQUAL(1, 1);
}

int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
