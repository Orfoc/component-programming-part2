#include <base64/base64.hh>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: base64 STRING\n";
        return 1;
    }
    std::string input(argv[1]);
    std::string output;
    output.resize(base64_encoded_size(input.size()));
    base64_encode(input.data(), input.size(), &output[0]);
    std::cout << output << '\n';
    std::string output2;
    output2.resize(base64_max_decoded_size(output.size()));
    auto actual_size = base64_decode(output.data(), output.size(), &output2[0]);
    output2.resize(actual_size);
    std::cout << output2 << '\n';
    return 0;
}
