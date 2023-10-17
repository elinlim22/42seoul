#include "PmergeMe.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCF                                    */
/* -------------------------------------------------------------------------- */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& a) {
	*this = a;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& a) {
	if (this != &a) {
		originalVector = a.originalVector;
		pairsVector = a.pairsVector;
		sortedVector = a.sortedVector;
		originalDeque = a.originalDeque;
		pairsDeque = a.pairsDeque;
		sortedDeque = a.sortedDeque;
	} return *this;
}

PmergeMe::~PmergeMe() {}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
/* --------------------------------- Common --------------------------------- */
int PmergeMe::JacobsthalNumber(int containerType) {
	if (containerType == VEC) {
		static int v1;
		static int v2 = 1;
		int v3 = v2 + v1 * 2;
		v1 = v2;
		v2 = v3;
		return v3;
	} else if (containerType == DEQ) {
		static int d1;
		static int d2 = 1;
		int d3 = d2 + d1 * 2;
		d1 = d2;
		d2 = d3;
		return d3;
	} else throw std::runtime_error("Jacobsthal Number error: container type not specified");
}

void PmergeMe::initData(std::string& input) {
	std::istringstream iss(input);
	std::string token;
	int i;

	while (std::getline(iss, token, ' ')) {
		try {
			i = std::stoi(token);
			if (i >= 0) {
				originalVector.push_back(i);
				originalDeque.push_back(i);
			} else {
				throw std::runtime_error("Parsing error: Negative integer value found");
			}
		} catch (const std::invalid_argument& e) {
			throw std::runtime_error("Parsing error: Non-integer value found");
		}
	}

	// pairingVector();
	// pairingDeque();
}

void PmergeMe::printResult() {
	// std::cout << "Before:\t";
	// for (size_t i = 0; i < originalVector.size(); ++i) {
	// 	std::cout << originalVector[i] << " ";
	// } std::cout << std::endl;
	// std::cout << "After:\t";
	// for (size_t i = 0; i < sortedVector.size(); i++) {
	// 	std::cout << sortedVector[i] << " ";
	// } std::cout << std::endl;
	// std::cout << "Deque result>\n";
	// for (size_t i = 0; i < sortedDeque.size(); i++) {
	// 	std::cout << sortedDeque[i] << " ";
	// } std::cout << std::endl;
	// std::cout << std::endl;
	if (std::is_sorted(sortedVector.begin(), sortedVector.end()) && std::is_sorted(sortedDeque.begin(), sortedDeque.end())) {
		// if (sortedVector.size() == originalVector.size() && sortedDeque.size() == originalDeque.size())
		// 	std::cout << "SUCCESS" << std::endl;
		// else throw std::runtime_error("Sorting error: numbers count does not match");
		if (!(sortedVector.size() == originalVector.size() && sortedDeque.size() == originalDeque.size()))
			throw std::runtime_error("Sorting error: numbers count does not match");
	} else throw std::runtime_error("Sorting error: failed to sort");
	std::cout << "Time to process a range of " << originalVector.size() << " elements with std::vector :\t " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << originalDeque.size() << " elements with std::deque :\t " << timeDeque << " us" << std::endl;
}

/* --------------------------------- Vector --------------------------------- */
void PmergeMe::pairingVector() {
	int tmp = -1;
	if (originalVector.size() % 2 != 0) {
		tmp = originalVector[originalVector.size() - 1];
	}
	for (size_t i = 0; i < originalVector.size() - 1; i += 2) {
		pairsVector.push_back(std::make_pair(originalVector[i], originalVector[i + 1]));
	}
	for (size_t i = 0; i < pairsVector.size(); ++i) {
		if (pairsVector[i].first < pairsVector[i].second) {
			std::swap(pairsVector[i].first, pairsVector[i].second);
		}
	}

	pairsVector = mergeSortVector(pairsVector);

	// std::cout << "Vector pairs:\t";
	// for (size_t i = 0; i < pairsVector.size(); i++) {
	// 	std::cout << "[" << pairsVector[i].first << ", " << pairsVector[i].second << "] "; //////////////////////////////
	// } std::cout << std::endl;

	for (size_t i = 0; i < pairsVector.size(); i++) {
		sortedVector.push_back(pairsVector[i].first);
	}

	if (tmp != -1) {
		std::vector<int>::iterator it = sortedVector.begin();

		while (it != sortedVector.end() && *it < tmp) ++it;
		sortedVector.insert(it, tmp);
	}

	// std::cout << "After Vector pairing:\n\t";
	// for (size_t i = 0; i < sortedVector.size(); i++) {
	// 	std::cout << sortedVector[i] << " ";
	// } std::cout << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::mergeVector(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right) {
	std::vector<std::pair<int, int> > result;
	size_t leftIndex = 0, rightIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size()) {
		if (left[leftIndex].first < right[rightIndex].first) {
			result.push_back(left[leftIndex]);
			leftIndex++;
		} else {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}
	}

	while (leftIndex < left.size()) {
		result.push_back(left[leftIndex]);
		leftIndex++;
	}

	while (rightIndex < right.size()) {
		result.push_back(right[rightIndex]);
		rightIndex++;
	}

	return result;
}

std::vector<std::pair<int, int> > PmergeMe::mergeSortVector(const std::vector<std::pair<int, int> >& arr) {
	if (arr.size() <= 1) {
		return arr;
	}

	size_t mid = arr.size() / 2;
	std::vector<std::pair<int, int> > left(arr.begin(), arr.begin() + mid);
	std::vector<std::pair<int, int> > right(arr.begin() + mid, arr.end());

	left = mergeSortVector(left);
	right = mergeSortVector(right);

	return mergeVector(left, right);
}

void PmergeMe::insertionSortVector(int jnum) {
	static int originalJnum = -1;

	if (jnum == 1 && originalJnum == -1) {
		std::vector<int>::iterator it = sortedVector.begin();
		if (*it < pairsVector[0].second) ++it;
		sortedVector.insert(it, pairsVector[0].second);
	} else if (jnum > 1) {
		int toInsert = pairsVector[jnum - 1].second;

		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairsVector[jnum - 1].first);
		std::vector<int>::iterator it = sortedVector.begin();
		while (it != at && *it < toInsert) ++it;
		sortedVector.insert(it, toInsert);
	}
	if (jnum - 1 > 1 && jnum - 1 > originalJnum)
		insertionSortVector(jnum - 1);
	originalJnum = jnum;
}

/* ---------------------------------- Deque --------------------------------- */
void PmergeMe::pairingDeque() {
	int tmp = -1;
	if (originalDeque.size() % 2 != 0) {
		tmp = originalDeque[originalDeque.size() - 1];
	}
	for (size_t i = 0; i < originalDeque.size() - 1; i += 2) {
		pairsDeque.push_back(std::make_pair(originalDeque[i], originalDeque[i + 1]));
	}
	for (size_t i = 0; i < pairsDeque.size(); ++i) {
		if (pairsDeque[i].first < pairsDeque[i].second) {
			std::swap(pairsDeque[i].first, pairsDeque[i].second);
		}
	}

	pairsDeque = mergeSortDeque(pairsDeque);

	// std::cout << "Deque pairs:\t";
	// for (size_t i = 0; i < pairsDeque.size(); i++) {
	// 	std::cout << "[" << pairsDeque[i].first << ", " << pairsDeque[i].second << "] "; //////////////////////////////
	// } std::cout << std::endl;

	for (size_t i = 0; i < pairsDeque.size(); i++) {
		sortedDeque.push_back(pairsDeque[i].first);
	}

	if (tmp != -1) {
		std::deque<int>::iterator it = sortedDeque.begin();

		while (it != sortedDeque.end() && *it < tmp) ++it;
		sortedDeque.insert(it, tmp);
	}

	// std::cout << "After Deque pairing:\n\t";
	// for (size_t i = 0; i < sortedDeque.size(); i++) {
	// 	std::cout << sortedDeque[i] << " ";
	// } std::cout << std::endl;
}

std::deque<std::pair<int, int> > PmergeMe::mergeDeque(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right) {
	std::deque<std::pair<int, int> > result;
	size_t leftIndex = 0, rightIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size()) {
		if (left[leftIndex].first < right[rightIndex].first) {
			result.push_back(left[leftIndex]);
			leftIndex++;
		} else {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}
	}

	while (leftIndex < left.size()) {
		result.push_back(left[leftIndex]);
		leftIndex++;
	}

	while (rightIndex < right.size()) {
		result.push_back(right[rightIndex]);
		rightIndex++;
	}

	return result;
}

std::deque<std::pair<int, int> > PmergeMe::mergeSortDeque(const std::deque<std::pair<int, int> >& arr) {
	if (arr.size() <= 1) {
		return arr;
	}

	size_t mid = arr.size() / 2;
	std::deque<std::pair<int, int> > left(arr.begin(), arr.begin() + mid);
	std::deque<std::pair<int, int> > right(arr.begin() + mid, arr.end());

	left = mergeSortDeque(left);
	right = mergeSortDeque(right);

	return mergeDeque(left, right);
}

void PmergeMe::insertionSortDeque(int jnum) {
	// std::cout << "Sorting status >> ";
	// for (size_t i = 0; i < sortedDeque.size(); i++) {
	// 	std::cout << sortedDeque[i] << " ";
	// } std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << "jnum:\t\t" << jnum << std::endl;
	static int originalJnum = -1;
	// std::cout << "originalJnum:\t" << originalJnum << std::endl;

	if (jnum == 1 && originalJnum == -1) {
		// std::cout << "[[[\ttoInsert: " << pairsDeque[0].second << "\t]]]" << std::endl;
		std::deque<int>::iterator it = sortedDeque.begin();
		if (*it < pairsDeque[0].second) ++it;
		sortedDeque.insert(it, pairsDeque[0].second);
		// std::cout << std::endl;
	} else if (jnum > 1) {
		int toInsert = pairsDeque[jnum - 1].second;
		// std::cout << "[[[\ttoInsert: " << toInsert << "\t]]]" << std::endl;

		std::deque<int>::iterator at = std::find(sortedDeque.begin(), sortedDeque.end(), pairsDeque[jnum - 1].first);
		std::deque<int>::iterator it = sortedDeque.begin();
		while (it != at && *it < toInsert) ++it;
		sortedDeque.insert(it, toInsert);
	}
	if (jnum - 1 > 1 && jnum - 1 > originalJnum)
		insertionSortDeque(jnum - 1);
	originalJnum = jnum;
	// std::cout << "--------stop---------" << std::endl;
}


/* --------------------------------- Public --------------------------------- */
void PmergeMe::MIsort(std::string& input) {
	try {
		initData(input);
		// std::cout << "Vector input size:\t" << originalVector.size() << std::endl;
		// std::cout << "Deque input size:\t" << originalDeque.size() << std::endl;
		// std::cout << "pairsVector size:\t" << pairsVector.size() << std::endl;
		// std::cout << "pairsDeque size:\t" << pairsDeque.size() << std::endl;
		// Vector sorting
		clock_t startVector = clock();
		pairingVector();
		for (int i = JacobsthalNumber(VEC); static_cast<size_t>(i) <= pairsVector.size(); i = JacobsthalNumber(VEC)) {
			insertionSortVector(i);
		}
		if (originalVector.size() != sortedVector.size()) {
			insertionSortVector(pairsVector.size());
		}
		clock_t endVector = clock();
		timeVector = (static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC) * 1000000.0;
		// Deque sorting
		pairingDeque();
		clock_t startDeque = clock();
		for (int i = JacobsthalNumber(DEQ); static_cast<size_t>(i) <= pairsDeque.size(); i = JacobsthalNumber(DEQ)) {
			insertionSortDeque(i);
		}
		if (originalDeque.size() != sortedDeque.size()) {
			insertionSortDeque(pairsDeque.size());
		}
		clock_t endDeque = clock();
		timeDeque = (static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC) * 1000000.0;
		printResult();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

/*
Tester:
./PmergeMe 3 12 2 10 6 11 8 0 1 7 9 4 5 14 13
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
*/
