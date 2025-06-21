#include "BasicString.h"

explicit BasicString::BasicString(const char* const data) {
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

BasicString::BasicString(const BasicString& copied) : m_size(copied.m_size) {
	size_t i = 0;
	m_data = new char[m_size];
	for (i = 0; i < m_size; i++) {
		m_data[i] = copied.m_data[i];
	}
}

BasicString::~BasicString() {
	delete[] m_data;
}