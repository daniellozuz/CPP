#ifndef _labelgenerator_h
#define _labelgenerator_h

#include <string>

using namespace std;

class LabelGenerator{
public:
	LabelGenerator(string prefix, int first);
	~LabelGenerator();
	string next_label();

private:
	string prefix;
	int number;
};

#endif
