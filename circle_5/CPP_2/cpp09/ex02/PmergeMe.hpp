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
		/* ---------------------------- Member variables ---------------------------- */
		// Vector
		std::vector<int> originalVector;
		std::vector<std::pair<int, int> > pairsVector;
		std::vector<int> sortedVector;
		// Deque
		std::deque<int> originalDeque;
		std::deque<std::pair<int, int> > pairsDeque;
		std::deque<int> sortedDeque;
		/* ---------------------------- Member functions ---------------------------- */
		// Common
		int JacobsthalNumber();
		void initData(std::string& input);
		void printResult();
		// Vector
		void pairingVector();
		std::vector<std::pair<int, int> > mergeVector(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right);
		std::vector<std::pair<int, int> > mergeSortVector(const std::vector<std::pair<int, int> >& arr);
		void insertionSortVector(int prevJnum);
		// Deque
		void pairingDeque();
		std::deque<std::pair<int, int> > mergeDeque(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right);
		std::deque<std::pair<int, int> > mergeSortDeque(const std::deque<std::pair<int, int> >& arr);
		void insertionSortDeque(int prevJnum);
	public:
		/* ---------------------------------- OCCF ---------------------------------- */
		PmergeMe();
		PmergeMe(const PmergeMe& a);
		PmergeMe& operator= (const PmergeMe& a);
		virtual ~PmergeMe();
		/* ----------------------------- Member function ---------------------------- */
		void MIsort(std::string& input);
};

#endif
