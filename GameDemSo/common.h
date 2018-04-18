//
// @Author: Van Cong Le Ca
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Data
{
private:
	unsigned int __data;
public:
	void set_data(const unsigned int data);

	unsigned int get_data();
};