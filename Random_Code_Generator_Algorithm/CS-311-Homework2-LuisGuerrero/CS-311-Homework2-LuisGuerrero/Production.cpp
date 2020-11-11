#include "Production.h"
#include <time.h>
#include <random>
#include <iomanip>
#include <string>
#include <iostream>

Production::Production()
{
	lhs = "";
}

Production::Production(std::string non_term)
{
	lhs = non_term;
}

void Production::add_rhs(std::string terminal, double probability)
{
	rhs_options.push_back(terminal);
	trans_probabilities.push_back(probability);
}

std::string Production::expand() const
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<double> distribution(0, 1);
	double rand_num = distribution(gen);
	std::string options;
	int i, n;
	for (i = 0; i < trans_probabilities.size(); i++)
	{
		if (trans_probabilities.size() == 1)
		{
			break;
		}
		double tprob = trans_probabilities.at(i);
		if (tprob >= rand_num)
		{
			break;
		}
		else
		{
			i = rand() % trans_probabilities.size();
			break;
		}
	}

	options = rhs_options.at(i);
	return options;
}