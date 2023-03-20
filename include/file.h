#ifndef _VULTIVE_FILE_H_
#define _VULTIVE_FILE_H_

#include "vultive.header.h"

#define FILE_NEW_PROP '|'
#define FILE_EQUALS '='

namespace Vultive {

	class File {

	protected:
		std::string path;
		std::fstream* sFile;
		std::vector<std::string> data;

		virtual void saveData();
		
	public:

		File(std::string path) {
			this->path = path;
		}

		virtual File &operator<<(std::string data);

		virtual int create(std::ios_base::openmode params = std::ios::binary | std::ios::in | std::ios::out);
		virtual int open(std::ios_base::openmode params = std::ios::binary | std::ios::in | std::ios::out);
		virtual void load(std::string data = STRING_NULL);
		virtual void print();
		virtual void clear();
		virtual void close();
		bool isOpen() {
			return (sFile ? sFile->is_open() : false);
		}
		void setPath(std::string path) {
			this->path = path;
		}
		std::string getPath() {
			return this->path;
		}
		std::vector<std::string> getData() {
			return this->data;
		}
		int save();
		virtual void destroy();

	};

}

#endif