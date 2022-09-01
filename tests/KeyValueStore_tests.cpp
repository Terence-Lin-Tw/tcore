#include "KeyValueStore_tests.hpp"

TEST_GROUP(one_kv_pair){
	KVSstore *mStore;
	void setup(){
		mStore = kvs_create(strcmp);
    }

	void teardown(){
		kvs_destroy(mStore);
    }
};

TEST(one_kv_pair, store_length_should_be_one){
	char k[256] = "Cyan-Spider-97";
	char v[256] = "CS_064,261";
	kvs_put(mStore, k, v);

	size_t sz = kvs_length(mStore);

	CHECK(sz == 1);
}

/* -------- test group separator -------- */

TEST_GROUP(object_life_cycle){
	KVSstore *mStore;
	void setup(){
		mStore = kvs_create(strcmp);
    }

	void teardown(){
		kvs_destroy(mStore);
    }
};

TEST(object_life_cycle, created_store_should_not_be_null){
	KVSstore *store = kvs_create(strcmp);
	CHECK(store);
}

TEST(object_life_cycle, newly_created_store_length_should_be_zero){
	KVSstore *store = kvs_create(strcmp);

	CHECK(  kvs_length(store) == 0  );
}

TEST(object_life_cycle, destroyed_store_should_be_null){
	KVSstore *store = kvs_create(strcmp);
	kvs_destroy(store);
	store = NULL;

	CHECK(!store);
}

TEST(object_life_cycle, initial_testing_environment_check){
	CHECK(true);
	CHECK_EQUAL(1, 1);
}

int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
