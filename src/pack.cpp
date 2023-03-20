#include "../include/pack.h"

void Vultive::Pack::set(std::string path, std::string content)
{
	data[path] = content;
}

std::string Vultive::Pack::get(std::string path) {
	return data[path];
}

bool Vultive::Pack::has(std::string path)
{
	if (data[path].empty()) {
		return false;
	}
	return true;
}

Vultive::Pack& Vultive::Pack::operator<<(std::string path)
{
	if (isOpen()) {
		Vultive::File* file = new Vultive::File(path);
		file->open();
		if (file->isOpen()) {
			file->load();
			*sFile << path << '\n';
			for (int i = 0; i < file->getData().size(); i++) {
				*sFile << file->getData()[i] << '\n';
			}
			file->destroy();
		}
	}
	return *this;
}

void Vultive::Pack::load() {
	File::load();
	/*
		TODO
	*/
}


void Vultive::Pack::print() {
	for (const auto& [path, content] : data) {
		std::cout << path.c_str() << " -> " << content.length() << '\n';
	}
}

void Vultive::Pack::destroy() {
	File::destroy();
	data.clear();
}