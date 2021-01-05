#include "gtest/gtest.h"
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<type_traits>
std::vector<int> get_r_value_vector(){
	return {1,2,3,4,5};
}
TEST(vector, push_back_test){
	std::vector<int> a;
	std::vector<std::string> b;
	EXPECT_EQ(0, a.size());
	EXPECT_EQ(0, b.size());

	int add_int = 1;
	std::string add_string = "hello";

	a.push_back(add_int);
	EXPECT_EQ(add_int, a[a.size() - 1]);

	b.push_back(add_string);
	EXPECT_EQ(add_string, b[b.size()-1]);
	}

TEST(vector, pop_back_test){
	std::vector<int> a = {1,2,3,4,5};
	EXPECT_EQ(5,a.size());
	a.pop_back();
	EXPECT_EQ(4, a.size());
	EXPECT_EQ(4, a[a.size() - 1]);
}

TEST(vector, erase){
	std::vector<int> a = {1,2,3,4,5};
	EXPECT_EQ(1, count(begin(a), end(a), 1));
	a.erase(begin(a), begin(a)+1);
	EXPECT_EQ(0, count(begin(a), end(a), 1));
			}
TEST(vector, begin_and_end){
	std::vector<int> a = {1,2,3,4,5}, b;
	for (auto i = begin(a); i!=end(a); ++i){
		b.push_back(*i);
	}
	EXPECT_EQ(b, a);
}

TEST(vector, construct_r_value){
	std::vector<int> a(get_r_value_vector());
	
	EXPECT_EQ(get_r_value_vector(), a);
}

TEST(vector, construct_l_value){
	std::vector<int> l_vector({1,2,3,4,5});
	std::vector<int> a(l_vector);

	EXPECT_EQ(l_vector, a);
}

TEST(vector, operator_r_value){
	std::vector<int> a = get_r_value_vector();

	EXPECT_EQ(get_r_value_vector(), a);
}
TEST(vector, operator_l_value){
	std::vector<int> l_vector({1,2,3,4,5});
	std::vector<int> a = l_vector;
	
	EXPECT_EQ(l_vector, a);
}



struct Erase_params{
	std::vector<int> elements;
	size_t start_index;
	size_t end_index;
	std::vector<int> result;
};

class Erase_test: public ::testing::TestWithParam<Erase_params>{};

TEST_P(Erase_test, vector){
	const Erase_params& param = GetParam();
	
	auto erased = param.elements;
	erased.erase(begin(erased) + param.start_index, begin(erased) + param.end_index); 
	EXPECT_EQ(param.result, erased);

}

INSTANTIATE_TEST_CASE_P(vector,  Erase_test, ::testing::Values(
			Erase_params{{1,2,3,4,5}, 3, 5, {1,2,3}}
			));

template<class T>
struct push_back_typed_test: public ::testing::Test{};

typedef ::testing::Types<float, std::string, std::ofstream> Types;

TYPED_TEST_CASE(push_back_typed_test, Types);

TYPED_TEST(push_back_typed_test, push_back){
	TypeParam new_element = {};
	std::vector<TypeParam> elements = {};
	if constexpr(std::is_same<TypeParam, std::ofstream>::value == true){
		bool start_state = new_element.is_open();
		EXPECT_EQ(0, elements.size());
		elements.push_back(std::move(new_element));
		EXPECT_EQ(1, elements.size());
		if (elements[0].is_open() == start_state){
			start_state = true;
		} else {
			start_state = false;
		}
		EXPECT_TRUE(start_state);
	} else if constexpr((std::is_same<float, TypeParam>::value) || (std::is_same<std::string, TypeParam>::value)){
		EXPECT_EQ(0, elements.size());
		elements.push_back(new_element);
		EXPECT_EQ(1, elements.size());
		EXPECT_EQ(elements[elements.size() - 1], new_element);
	}
}
