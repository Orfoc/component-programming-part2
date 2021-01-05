#include "base64/base64.hh"
#include<string>
#include<stdexcept>
#include<gtest/gtest.h>
#include<algorithm>
#include<limits>

TEST(base64, encode_rem0){
	std::string start = "prikol";
	std::string answer = "cHJpa29s";
	std::string result;
	result.resize(base64_encoded_size(start.size()));

	base64_encode(start.data(), start.size(), &result[0]);
	EXPECT_EQ(result, answer);	

}

TEST(base64, decode_rem0){
	std::string encoded = "cHJpa29s";
	std::string answer = "prikol";
	std::string decoded;

	decoded.resize(base64_max_decoded_size(encoded.size()));
	base64_decode(encoded.data(), encoded.size(), &decoded[0]);
	EXPECT_EQ(decoded, answer);
}
TEST(base64, encode__decode_rem1){
	std::string start_string = "prikoll";
	
	std::string encoded_answer = "cHJpa29sbA==";
	std::string encoded;
	encoded.resize(base64_encoded_size(start_string.size()));
	
	base64_encode(start_string.data(), start_string.size(), &encoded[0]);
	EXPECT_EQ(encoded_answer, encoded);

	std::string decoded;
	decoded.resize(base64_max_decoded_size(encoded.size()));
	
	base64_decode(encoded.data(), encoded.size(), &decoded[0]);
	decoded.resize(decoded.size()-2);
	EXPECT_EQ(start_string, decoded);
}

TEST(base64, encode_decode_rem2){
	std::string start_string = "prikolll";

	std::string encoded_answer = "cHJpa29sbGw=";
	std::string encoded;
	encoded.resize(base64_encoded_size(start_string.size()));

	base64_encode(start_string.data(), start_string.size(), &encoded[0]);
	EXPECT_EQ(encoded_answer, encoded);

	std::string decoded;
	decoded.resize(base64_max_decoded_size(encoded.size()));

	base64_decode(encoded.data(), encoded.size(), &decoded[0]);
	decoded.resize(decoded.size() - 1);
	EXPECT_EQ(start_string, decoded);
}

TEST(base64, decode_len_0){
	std::string encoded = "", result;
	auto returned = base64_decode(encoded.data(), encoded.size(), &result[0]);
	EXPECT_EQ(0, returned);
}

TEST(base64, length_error){
	try{
		auto size = base64_encoded_size(std::numeric_limits<size_t>::max() / 4u * 3u);
		FAIL() << "no length error";
	} catch(std::length_error const & err){
		EXPECT_EQ(err.what(), std::string("base64 length is too large"));
	}
}


 
struct decode_param{
	std::string encoded;
	std::string error_what;
};

class decode_test: public ::testing::TestWithParam<decode_param>{};

TEST_P(decode_test, catch_errors){
	const decode_param& param = GetParam();
	std::string result;
	try{
		result.resize(base64_max_decoded_size(param.encoded.size()));
		base64_decode(param.encoded.data(), param.encoded.size(), &result[0]);
		FAIL() << "no error";
	} 
	catch(std::invalid_argument const & err){
		EXPECT_EQ(err.what(), param.error_what);
	}
	catch(std::length_error const & err){
		EXPECT_EQ(err.what(), param.error_what);
	}
}


INSTANTIATE_TEST_CASE_P(
		_, 
		decode_test,
		::testing::Values(
			decode_param{
			"123", "bad base64 string"},
			decode_param{
			"123,", "bad base64 string"},
			decode_param{
			std::string("123" + std::string{char(134)}) , "bad base64 string"})
);








