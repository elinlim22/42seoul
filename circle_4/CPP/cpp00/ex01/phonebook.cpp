/*
	phonebook
		1. array of contacts
		2. max 8 contacts : if 9th, replace 1st
		3. dynamic allocation forbidden
	class
		1. phonebook class
		2. contacts class
	commands
		1. ADD
		2. SEARCH
			- 4 columns(index, first, last, nickname) with 10 width separated by "|"
			- if longer than 10 characters, the last displayable character must be replaced by a "."
		3. EXIT
		4. any other input is discarded
*/

#include <iostream>
#include <string>

class
