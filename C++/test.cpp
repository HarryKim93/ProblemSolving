#include <atomic>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <new>
 
#ifdef __cpp_lib_hardware_interference_size
    using std::hardware_constructive_interference_size;
    using std::hardware_destructive_interference_size;
#else
    // Lucky guess │ __cacheline_aligned │ L1_CACHE_BYTES │ L1_CACHE_SHIFT │ ...
    constexpr std::size_t hardware_constructive_interference_size
        = 2 * sizeof(std::max_align_t);
    constexpr std::size_t hardware_destructive_interference_size
        = 2 * sizeof(std::max_align_t);
#endif
 
struct Data
{
    std::atomic<std::uint8_t> lock;
    std::uint8_t data;
};
 
struct DataPack
{
    std::uint8_t port;
    alignas(hardware_constructive_interference_size) Data pack;
    std::uint8_t wait;
};
 
struct KeepApart
{
    std::uint8_t air;
    alignas(hardware_destructive_interference_size) std::atomic<std::uint8_t> ice;
    alignas(hardware_destructive_interference_size) std::atomic<std::uint8_t> fire;
    std::uint8_t soil;
};
 
int main()
{
    std::cout
        << "hardware_destructive_interference_size == "
        << hardware_destructive_interference_size << '\n'
        << "hardware_constructive_interference_size == "
        << hardware_constructive_interference_size << '\n'
        << "sizeof( std::max_align_t ) == " << sizeof(std::max_align_t) << "\n\n";
 
    std::cout
        << "offsetof( DataPack::port ) : " << offsetof(DataPack, port) << '\n'
        << "offsetof( DataPack::pack ) : " << offsetof(DataPack, pack) << '\n'
        << "offsetof( DataPack::wait ) : " << offsetof(DataPack, wait) << '\n'
        << "sizeof  ( DataPack )       : " << sizeof(DataPack)         << '\n'
        << '\n';
 
    std::cout
        << "offsetof( KeepApart::air  ) : " << offsetof(KeepApart, air)  << '\n'
        << "offsetof( KeepApart::ice  ) ! " << offsetof(KeepApart, ice)  << '\n'
        << "offsetof( KeepApart::fire ) ! " << offsetof(KeepApart, fire) << '\n'
        << "offsetof( KeepApart::soil ) : " << offsetof(KeepApart, soil) << '\n'
        << "sizeof  ( KeepApart )       : " << sizeof(KeepApart)         << '\n'
        << '\n';
}