#include "tsk/file.h"

#include <fstream>

namespace tsk {

size_t file_read(const char* file_path, char* buffer, size_t buffer_size) {
	std::ifstream file(file_path, std::ios::ate | std::ios::binary);

	if(!file.is_open()) {
		return 0;
	}

	size_t file_size = static_cast<size_t>(file.tellg());

	if(buffer == nullptr) {
		return file_size;
	}

	assert(buffer_size >= file_size && "Buffer size is too small!");

	file.seekg(0);
	file.read(buffer, file_size);

	file.close();
	return file_size;
}

} // namespace tgfx
