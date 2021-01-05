#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_prime(int number){
	int i;
	for (i = 2; i <= sqrt(number); ++i){
		if (number % i == 0)
			return false;
	}
	return true;
}
