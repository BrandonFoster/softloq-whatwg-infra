#include <softloq/whatwg/infra.hpp>

#include <iostream>
#include <iomanip>

int main()
{
    using namespace softloq::whatwg;

    // infra list constructors //
    infra_list<infra_byte> list1; // default constructor
    
    infra_list<infra_byte> list2{0xD, 0xA, 0x1B}; // initializer list

    infra_list<infra_byte> list3{list2}; // copy constructor

    infra_list<infra_byte> list4{std::move(infra_list<infra_byte>{0xD, 0xA, 0x1C})}; // move constructor
    //-------------------------//

    // infra list assignments //
    //------------------------//
    
    // infra_string string{0x000D, 0x000D, 0x000D, 0x000A, 0x000A, 0x000D, 0x000A, 0x000D};
    // // for(const auto c: U"🜐") std::cout << "0x" << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << static_cast<std::uint32_t>(static_cast<std::uint32_t>(c)) << " ";
    // // for(const auto c: u8"🜐")
    //     // std::cout << "0x" << std::setfill('0') << std::setw(2) << std::hex << static_cast<std::uint32_t>(static_cast<std::uint8_t>(c)) << " ";
    
    // infra_list<infra_byte> byte_list{0x000D, 0x000D, 0x000D, 0x000A, 0x000A, 0x000D, 0x000A, 0x000D};
    // byte_list.sort_descending();
    
    // std::cout << byte_list;
    // std::cout << std::endl;

    return 0;
}