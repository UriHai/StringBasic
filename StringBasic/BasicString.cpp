#include "BasicString.h"

#include <iostream>

using std::cout;
using std::endl;

void BasicString::copyBasicString(const BasicString& copied) {
	m_size = copied.m_size;
	size_t i = 0;
	m_data = new char[m_size];
	for (i = 0; i < m_size; i++) {
		m_data[i] = copied.m_data[i];
	}
}

BasicString::BasicString(const char* const data) {
	size_t length = 0;
	size_t i = 0;
	while (data[length] != '\0') {
		length++;
	}
	m_size = length + 1;

	m_data = new char[m_size];
	for (i = 0; i < m_size; i++) {
		m_data[i] = data[i];
	}
}

BasicString::BasicString(const BasicString& copied) {
	this->copyBasicString(copied);
}

BasicString::~BasicString() {
	delete[] m_data;
}

BasicString& BasicString::operator=(const BasicString& copied) {
	this->copyBasicString(copied);
	return *this;
}

bool BasicString::operator==(const BasicString& other) const {
	size_t i = 0;
	while ((m_data[i] != '\0') && (other.m_data[i] != '\0')) {
		if (m_data[i] != other.m_data[i]) {
			return false;
		}
		i++;
	}
	return true;
}

BasicString BasicString::operator+(const BasicString& other) const {
	size_t i = 0;
	char* new_data = new char [m_size + other.m_size - 1];
	for (i = 0; i < m_size - 1; i++) {
		new_data[i] = m_data[i];
	}
	for (i = 0; i < other.m_size; i++) {
		new_data[m_size - 1 + i] = other.m_data[i];
	}
	BasicString newBasicString(new_data);
	delete[] new_data;
	return newBasicString;
}

void BasicString::operator+=(const BasicString& other) {
	size_t i = 0;
	char* new_data = new char[m_size + other.m_size - 1];
	for (i = 0; i < m_size - 1; i++) {
		new_data[i] = m_data[i];
	}
	for (i = 0; i < other.m_size; i++) {
		new_data[m_size - 1 + i] = other.m_data[i];
	}
	delete[] m_data;
	m_data = new_data;
	m_size += (other.m_size - 1);
}

BasicString BasicString::operator*(const size_t& multiply) const {
	size_t i = 0;
	size_t j = 0;
	size_t new_size = (m_size - 1) * multiply + 1;
	char* new_data = new char[new_size];
	for (j = 0; j < multiply; j++) {
		for (i = 0; i < m_size - 1; i++) {
			new_data[j * (m_size - 1) + i] = m_data[i];
		}
	}
	new_data[new_size - 1] = '\0';
	BasicString newBasicString(new_data);
	delete[] new_data;
	return newBasicString;
}

char& BasicString::operator[](const int& index) const {
	if ((index >= int(m_size) - 1) || (index <= -1 * int(m_size))) {
		throw IndexOutOfRangeError();
	}
	if (index < 0) {
		return m_data[m_size - 1 + index];
	}
	return m_data[index];
}

size_t BasicString::getLength() const {
	return m_size - 1;
}

void BasicString::printBasicString() const {
	cout << m_data << endl;
}

BasicStringError::BasicStringError(const BasicString& errorMessage) : m_errorMessage(errorMessage) {
	// Left blank intentionally
}

BasicString BasicStringError::getErrorMessage() const {
	return m_errorMessage;
}

IndexOutOfRangeError::IndexOutOfRangeError() : BasicStringError(BasicString ("Index out of range")) {
	// Left blank intentionally
}