#include "../include/INIReader.h"

void Vultive::INIReader::set(std::string section, std::string key, std::string value)
{
	data[std::make_pair(section, key)] = value;
}

std::string Vultive::INIReader::get(std::string section, std::string key)
{
	return data[std::make_pair(section, key)];
}

bool Vultive::INIReader::has(std::string section, std::string key)
{
	if (data[std::make_pair(section, key)].empty()) {
		return false;
	}
	return true;
}

void Vultive::INIReader::saveData() {
	std::string m_section = STRING_NULL;
	for (const auto& [key, value] : data) {
		if (m_section.compare(key.first)) {
			*sFile << "[" << key.first << "]\n";
			m_section = key.first;
		}
		*sFile << key.second + FILE_EQUALS + value + "\n";
	}
}

void Vultive::INIReader::parse() {
	INIReaderState state = none;
	std::string m_section, m_variable, m_tmp;
	for (std::string& line : File::data) {
		for (char& character : line) {
			if (state == none) {
				if (character == '[') {
					state = section;
					continue;
				}
				else if (character == ';') {
					state = comment;
					continue;
				}
				else {
					state = value;
				}
			}
			if (character == ']' && state == section) {
				m_section = m_tmp;
			}
			else if (character == '=' && state == value) {
				m_variable = m_tmp;
			}
			else if (state == comment && &character == &line.back()) { state = none; continue; }
			else {
				m_tmp += character;
				if (&character == &line.back() && state == value) {
					set(m_section, m_variable, m_tmp);
				}
			}
			if ((&character == &line.back() || character == '=') && state == value || character == ']' && state == section) {
				m_tmp.clear();
				state = none;
			}
		}
	}
}

void Vultive::INIReader::destroy() {
	File::destroy();
	data.clear();
}