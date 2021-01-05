#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Hello, world!" << endl;
	int i;
	for (i = 0; i < argc; ++i){
		cout << argv[i] << " ";
	}
	bool is_prime(int number);
	if (argc == 2){
		if (is_prime(atoi(argv[1]))){
			cout << argv[1] << " IS PRIME NUMBER" << endl;
		} else {
			cout << argv[1] << " ISN'T PRIME NUMBER " << endl;
		}
	}
	return 0;
}
