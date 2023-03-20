#include "../include/file.h"

Vultive::File & Vultive::File::operator<<(std::string data)
{
	if (sFile->is_open()) {
		this->data.push_back(data);
	}
	return *this;
}

int Vultive::File::create(std::ios_base::openmode params) {
	if (!path.empty()) {
		sFile = new std::fstream(path.c_str(), std::ios::out | std::ios::trunc);
		if (sFile->is_open()) {
			sFile->close();
			open(params);
		}
		else return -1;
	}
	return -2;
}

int Vultive::File::open(std::ios_base::openmode params) {
	if (!path.empty()) {
		sFile = new std::fstream(path.c_str(), params);
		if (!sFile->is_open())
			return -1;
	}
	return -2;
}

int Vultive::File::save() {
	if (!isOpen()) {
		return -1;
	}
	create();
	saveData();
	return 0;
}

void Vultive::File::saveData() {
	for (int it = 0; it < static_cast<int>(data.size()); it++) {
		*sFile << data[it] << '\n';
	}
}

void Vultive::File::load(std::string data) {
	if (isOpen()) {
		std::string tmp;
		if (data.empty()) {
			while (std::getline(*sFile, tmp)) {
				this->data.push_back(tmp);
				tmp.clear();
			}
		}
		else {
			for (int i = 0; i < static_cast<int>(data.size()) + 1; i++) {
				if (data[i] != '\n' && i != static_cast<int>(data.size()) && data[i] != FILE_NEW_PROP) {
					tmp += data[i];
				}
				else {
					this->data.push_back(data);
					tmp.clear();
				}
			}
		}
	}
}

void Vultive::File::print() {
	for (int it = 0; it < static_cast<int>(data.size()); it++) {
		printf("%s\n", data[it].c_str());
	}
}

void Vultive::File::clear() {
	data.clear();
}

void Vultive::File::close() {
	if (isOpen()) {
		sFile->close();
	}
}

void Vultive::File::destroy() {
	clear();
	close();
}