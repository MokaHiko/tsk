#include "tsk/tsk.h"

namespace tsk {

/// @brief Transitions the layout of a vulkan image form current to new.
///
/// @param[out] texure Pointer to texture that will be populated. 
/// @returns the amount of bytes read.
[[nodiscard]] TUSK_API size_t file_read(const char* file_path, char* buffer, size_t buffer_size);

} // tsk
