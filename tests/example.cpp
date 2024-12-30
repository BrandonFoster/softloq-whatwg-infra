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
    infra_list<infra_byte> assign_list;
    assign_list = list1; // copy assignment
    assign_list = std::move(list4); // move assignment
    //------------------------//

    // infra list iterators //
    infra_list<infra_byte> it_list;
    auto begin = it_list.begin();
    const auto begin2 = it_list.begin();
    auto cbegin = it_list.cbegin();

    auto end = it_list.end();
    const auto end2 = it_list.end();
    auto cend = it_list.cend();

    auto rbegin = it_list.rbegin();
    const auto rbegin2 = it_list.rbegin();
    auto crbegin = it_list.crbegin();

    auto rend = it_list.rend();
    const auto rend2 = it_list.rend();
    auto crend = it_list.crend();
    //----------------------//

    // infra list member functions //
    infra_list<infra_byte> list{0xD, 0xA, 0x1C};

    auto front = list.front();
    const auto front2 = list.front();

    auto back = list.back();
    const auto back2 = list.back();

    list.append(0x5E);
    list.pop_back();

    list.prepend(0x5E);
    list.pop_front();

    list.extend(list2);
    list.replace(0x4, [](const infra_byte& byte) { return byte == 0x5E; });

    list.insert(2, 0xEF);

    list.remove(0xEF);
    list.remove_if([](const infra_byte& byte) { return byte == 0x5E; });
    
    list.size();
    list.empty();
    list.clear();

    list.contains(0xA);
    list.clone();

    list.sort_ascending();
    list.sort_descending();
    
    //------------------//

    return 0;
}