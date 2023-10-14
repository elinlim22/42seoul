#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <utility>

class PmergeMe {
	private:
		std::vector<int> originalVector;
		std::vector<std::pair<int, int> > pairs;
		std::vector<int> sortedVector;
		std::deque<int> originalDeque;
		std::deque<int> sortedDeque;
		void initData(std::string& input);
		int JacobsthalNumber();
		void doubling();
		void insertion(int prevJnum);
	public:
		// OCCF
		PmergeMe();
		PmergeMe(const PmergeMe& a);
		PmergeMe& operator= (const PmergeMe& a);
		virtual ~PmergeMe();
		// Member function
		void MIsort(std::string& input);
		void printResult();
};

#endif

	// if (!(jnum - 1 < 0 || jnum - 1 == originalJnum || static_cast<size_t>(jnum - 1) > pairs.size()))
	// 	insertion(jnum - 1);
