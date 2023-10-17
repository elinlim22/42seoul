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

PmergeMe::~PmergeMe() {
	// delete 있을수도
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
/* --------------------------------- Common --------------------------------- */
int PmergeMe::JacobsthalNumber() {
	static int i1;
	static int i2 = 1;
	int i3 = i2 + i1 * 2;
	i1 = i2;
	i2 = i3;
	return i3;
}

void PmergeMe::initData(std::string& input) {
	std::istringstream iss(input);
	std::string token;
	while (std::getline(iss, token, ' ')) {
		try {
			int i = std::stoi(token);
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
	pairingVector();
	pairingDeque();
}

void PmergeMe::printResult() {
	std::cout << "Vector result:\n\t";
	for (size_t i = 0; i < sortedVector.size(); i++) {
		std::cout << sortedVector[i] << " ";
	} std::cout << std::endl;
	std::cout << "Deque result:\n\t";
	for (size_t i = 0; i < sortedDeque.size(); i++) {
		std::cout << sortedDeque[i] << " ";
	} std::cout << std::endl;
	if (std::is_sorted(sortedVector.begin(), sortedVector.end()) && std::is_sorted(sortedDeque.begin(), sortedDeque.end())) {
		if (sortedVector.size() == originalVector.size() && sortedDeque.size() == originalDeque.size())
			std::cout << "SUCCESS" << std::endl;
		else throw std::runtime_error("Sorting error: numbers count does not match");
	} else throw std::runtime_error("Sorting error: failed to sort");
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
	for (size_t i = 0; i < originalVector.size(); ++i) {
		if (pairsVector[i].first < pairsVector[i].second) {
			std::swap(pairsVector[i].first, pairsVector[i].second);
		}
	}

	pairsVector = mergeSortVector(pairsVector);

	for (size_t i = 0; i < pairsVector.size(); i++) {
		// std::cout << "[" << pairsVector[i].first << ", " << pairsVector[i].second << "] ";
		sortedVector.push_back(pairsVector[i].first);
	} std::cout << std::endl;

	if (tmp != -1) {
		std::vector<int>::iterator it = sortedVector.begin();

		while (it != sortedVector.end() && *it < tmp) ++it;
		sortedVector.insert(it, tmp);
	}
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
		sortedVector.insert(sortedVector.begin(), pairsVector[0].second);
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
	for (size_t i = 0; i < originalDeque.size(); ++i) {
		if (pairsDeque[i].first < pairsDeque[i].second) {
			std::swap(pairsDeque[i].first, pairsDeque[i].second);
		}
	}

	pairsDeque = mergeSortDeque(pairsDeque);

	for (size_t i = 0; i < pairsDeque.size(); i++) {
		// std::cout << "[" << pairsDeque[i].first << ", " << pairsDeque[i].second << "] ";
		sortedDeque.push_back(pairsDeque[i].first);
	} std::cout << std::endl;

	if (tmp != -1) {
		std::deque<int>::iterator it = sortedDeque.begin();

		while (it != sortedDeque.end() && *it < tmp) ++it;
		sortedDeque.insert(it, tmp);
	}
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
	static int originalJnum = -1;

	if (jnum == 1 && originalJnum == -1) {
		sortedDeque.insert(sortedDeque.begin(), pairsDeque[0].second);
	} else if (jnum > 1) {
		int toInsert = pairsDeque[jnum - 1].second;

		std::deque<int>::iterator at = std::find(sortedDeque.begin(), sortedDeque.end(), pairsDeque[jnum - 1].first);
		std::deque<int>::iterator it = sortedDeque.begin();
		while (it != at && *it < toInsert) ++it;
		sortedDeque.insert(it, toInsert);
	}
	if (jnum - 1 > 1 && jnum - 1 > originalJnum)
		insertionSortDeque(jnum - 1);
	originalJnum = jnum;
}


/* --------------------------------- Public --------------------------------- */
void PmergeMe::MIsort(std::string& input) {
	try {
		initData(input);
		std::cout << "Vector input size:\t" << originalVector.size() << std::endl;
		std::cout << "Deque input size:\t" << originalDeque.size() << std::endl;
		std::cout << "pairsVector size:\t" << pairsVector.size() << std::endl;
		std::cout << "pairsDeque size:\t" << pairsDeque.size() << std::endl;
		// Vector sorting
		for (int i = JacobsthalNumber(); static_cast<size_t>(i) <= pairsVector.size(); i = JacobsthalNumber()) {
			insertionSortVector(i);
		}
		if (originalVector.size() != sortedVector.size()) {
			insertionSortVector(pairsVector.size());
		}
		// Deque sorting
		for (int i = JacobsthalNumber(); static_cast<size_t>(i) <= pairsDeque.size(); i = JacobsthalNumber()) {
			insertionSortDeque(i);
		}
		if (originalDeque.size() != sortedDeque.size()) {
			insertionSortDeque(pairsDeque.size());
		}
		std::cout << std::endl;
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
