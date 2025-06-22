#pragma once

class BasicString final {
private:
	char* m_data;
	size_t m_size;

	/**
	 * @brief						Create size and data of a Basic String
	 * 
	 * @param				[IN]	The Basic String to be copied
	 */
	void copyBasicString(const BasicString& copied);

public:
	/**
	 * @brief						Basic String constructor
	 *
	 * @param data			[IN]	The data of the Basic String	
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

	/**
	* @brief						Basic String copy assigment operator - performs deep copy
	*
	* @param copied		[IN]		The Basic String to be copied
	*/
	BasicString& operator=(const BasicString& copied);

	/**
	 * @brief						'==' operator - Compare Basic Strings
	 * 
	 * @param other		[IN]		The Basic String to compare to
	 * @return						True if all chars up to the first '\0' are identical, false otherwise
	 */
	bool operator==(const BasicString& other) const;

	/**
	 * @brief						'+' operator - Concatenate Basic Strings
	 *
	 * @param other		[IN]		The Basic String to add
	 * @return						New Basic String that is the concatenation of this string and the other string
	 */
	BasicString operator+(const BasicString& other) const;

	/**
	 * @brief						'+=' operator - Append Basic String
	 * 
	 * @param other		[IN]		The Basic String to 
	 */
	void operator+=(const BasicString& other);

	/**
	 * @brief						'*' operator - Concatenate Basic String with itself
	 * 
	 * @param multiply	[IN]		The number of times to concatenate the Basic String with itself
	 * @return						The Basic String concatenated with itself mult times
	 */
	BasicString operator*(const size_t& multiply) const;
	
	/**
	* @brief						'[]' operator - Access Basic String data by index
	*
	* @param index		[IN]		The index
	* @return						The char at that index
	*/
	char& operator[](const int& index) const;

	// Get Basic String Length
	size_t getLength() const;

	// Print Basic String
	void printBasicString() const;
};

class BasicStringError {
private:
	BasicString m_errorMessage;
public:
	explicit BasicStringError(const BasicString& errorMessage);
	BasicString getErrorMessage() const;
};

class IndexOutOfRangeError final : public BasicStringError {
public:
	explicit IndexOutOfRangeError();
};