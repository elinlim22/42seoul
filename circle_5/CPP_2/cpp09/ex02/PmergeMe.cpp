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
		sortedVector = a.sortedVector;
		originalDeque = a.originalDeque;
		sortedDeque = a.sortedDeque;
	} return *this;
}

PmergeMe::~PmergeMe() {
	// delete 있을수도
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
// bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
// 	return std::max(a.first, a.second) < std::max(b.first, b.second);
// }

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
	doubling();
}

void PmergeMe::doubling() {
	// 홀수인 경우 -1추가 -> 나중에 제거 필요
	if (originalVector.size() % 2 != 0 && originalDeque.size() % 2 != 0) {
		originalVector.push_back(-1);
	}

	// pair로 묶음
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < originalVector.size() - 1; i += 2) {
		pairs.push_back(std::make_pair(originalVector[i], originalVector[i + 1]));
	}

	// 앞쪽에 큰 값으로 정렬(내부)
	for (size_t i = 0; i < originalVector.size(); ++i) {
		if (pairs[i].first < pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
	}

	// 앞을 기준으로 정렬(외부)
	std::sort(pairs.begin(), pairs.end());

	// 출력 및 sortedvector에 그대로 넣기
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "] ";
		sortedVector.push_back(pairs[i].first);
		sortedVector.push_back(pairs[i].second);
	} std::cout << std::endl;

	// sortedVector 출력
	for (size_t i = 0; i < sortedVector.size(); i++) {
		std::cout << sortedVector[i] << " ";
	} std::cout << std::endl;
}

int PmergeMe::JacobsthalNumber() {
	static int i1;
	static int i2 = 1;
	int i3 = i2 + i1 * 2;
	i1 = i2;
	i2 = i3;
	return i3;
}

void PmergeMe::MIsort(std::string& input) {
	try {
		initData(input);
		printResult();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void PmergeMe::printResult() {

}
