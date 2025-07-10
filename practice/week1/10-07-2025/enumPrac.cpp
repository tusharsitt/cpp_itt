#include <iostream>

// namespace Monster
// {

//     enum MonsterType
//     {

//         orc ,
//         goblin,
//         troll,
//         ogre,
//         skeleton,
//     };

// }

enum Color
{
    red,
    blue,
    green,
    black
};

enum Paint : long
{
    redpaint

};

int main()
{

    Color clr = Color::green;
    // default: int integral type
    std::cout << sizeof(clr) << std::endl;

    Paint pat = Paint::redpaint;
    // long integral type
    std::cout << sizeof(pat) << std::endl;

    // Monster::MonsterType myMonster{Monster::troll};
}