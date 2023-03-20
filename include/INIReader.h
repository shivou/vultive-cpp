#ifndef _VULTIVE_INIREADER_H_
#define _VULTIVE_INIREADER_H_

#include "file.h"

#define FILE_INIREADER_START_SECTION "["
#define FILE_INIREADER_END_SECTION "]"
#define FILE_INIREADER_NAME_SECTION_LIMIT 50

namespace Vultive {

	enum INIReaderState {
		none, section, value, comment
	};

	class INIReader : public File {

	private:
		std::map<std::pair<std::string, std::string>, std::string> data;

		void saveData();

	public:

		INIReader(std::string path): File(path) {}

		void parse();
		void set(std::string section, std::string key, std::string value);
		std::string get(std::string section, std::string key);
		bool has(std::string section, std::string key);
		void destroy();

	};

}

#endif