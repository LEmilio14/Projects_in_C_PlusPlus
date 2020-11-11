#pragma once
#include <string>
#include <vector>

class Production {
private:
	std::string lhs;
	std::vector<std::string> rhs_options;
	std::vector<double> trans_probabilities;

public:
	Production();
	Production(std::string);
	void add_rhs(std::string, double);
	std::string expand() const;

};