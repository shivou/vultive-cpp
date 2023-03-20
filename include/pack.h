#ifndef _VULTIVE_PACK_H_
#define _VULTIVE_PACK_H_

#include "file.h"

#define FILE_PACK_PREFIX "YAVR_PACK"

namespace Vultive {

	class Pack : public File {

	private:
		std::map<std::string, std::string> data;

	public:
		Pack(std::string path): File(path) {}

		Pack& operator<<(std::string path);

		void load();

		void set(std::string path, std::string content);
		std::string get(std::string path);
		bool has(std::string path);

		void print();
		void destroy();

	};

}

#endif