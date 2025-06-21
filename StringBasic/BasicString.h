#pragma once

class BasicString final {
private:
	char* m_data;
	size_t m_size;

public:
	/**
	 * @brief						Basic String constructor
	 *
	 * @param data			[IN]	The data of the string	
	 */
	explicit BasicString(const char* const data);

	/**
	 * @brief						Basic String copy constructor - performs deep copy
	 * 
	 * @param copied		[IN]	The Basic String to be copied
	 */
	BasicString(const BasicString& copied);

	
	// Basic String destructor
	~BasicString();
};