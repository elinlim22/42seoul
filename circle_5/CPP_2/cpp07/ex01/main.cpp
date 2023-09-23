#include "iter.hpp"

int main() {
	int arr[5] = {0, 1, 2, 3, 4};
	char arr2[5] = {'a', 'b', 'c', 'd', 'e'};

	iter<int>(arr, 5, func<int>);
	std::cout << std::endl;
	iter<char>(arr2, 5, func<char>);
	std::cout << std::endl;

	return 0;
}

/* Evaluation tester

#include "iter.hpp"

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );

	return 0;
}

*/
