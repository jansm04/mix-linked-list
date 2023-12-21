#include <iostream>

#include "chain.h"

using namespace std;


int main(void) {
	Chain chain = Chain();

	chain.Insert(1);
	chain.Insert(2);
	chain.Insert(3);

	chain.Insert(11);
	chain.Insert(12);
	chain.Insert(13);

	chain.Mix();

	chain.PrintChain();
	return 0;
}