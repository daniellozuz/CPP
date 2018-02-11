#include "LabelGenerator.h"
#include <string>

using namespace std;

LabelGenerator::LabelGenerator(string prefix, int first) {
	this->prefix = prefix;
	this->number = first;
}

LabelGenerator::~LabelGenerator() {
}

string LabelGenerator::next_label() {
	return (this->prefix + to_string(this->number++));
}
