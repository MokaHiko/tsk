
namespace tsk {

enum class Endianness{
    k_big_endian = 0,
    k_little_endian,
};

Endianness get_platform_endianess();

constexpr Endianness k_stream_endianness = Endianness::k_big_endian;
inline Endianness k_platform_endianness = get_platform_endianess();

} // namespace tsk