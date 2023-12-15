#include <iostream>

#define ASPECT_RATIO 1.653
const double AspectRatio = 1.653;

/*
 * todo 将#define替换为常量时,有两种特殊情况值得一提
 *  第一个是定义常量指针  constant pointers
 * */
#define AUTHORNAME "Scott Meyers"
const char* authorName = "Scott Meyers";
const char* authorName2 = "wangze";
const char* const authorName3 = "Scott Meyers";
const std::string authorName4("Scott Meyers");


// todo 第二种特殊情况涉及特定于类的常量  class-specific constants
class GamePlayer {
private:
//宏无法将作用域限制在类的内部.
//#define NUMTURNS 5
    static const int NumTurns = 5;  //constant declaration
    int scores[NumTurns];
public:
    int numTurns() {
        return NumTurns;
    }
};

//错误
//const int GamePlayer::NumTurns = 5; //定义
const int GamePlayer::NumTurns;



class GamePlayerWithoutArray {
private:
    static const int NumTurns;
public:
    int numTurns() {
        return NumTurns;
    }
};

const int GamePlayerWithoutArray::NumTurns = 5;

class GamePlayerWithEnum {
private:
    enum {NumTurns = 5};
    int score[NumTurns];
public:
    int numTurns() {
        return NumTurns;
    }
};

int f(int num) {
    return num;
}

#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))

template<typename T>
inline T callWithMax(const T& a, const T& b) {
    f (a > b ? a : b);
}

int main() {
    std::cout << ASPECT_RATIO << std::endl;
    std::cout << AUTHORNAME << std::endl;
    std::cout << AspectRatio << std::endl;
    authorName = authorName2;
    //下面语句编译不通过.
    //authorName3 = authorName2;
    std::cout << authorName << std::endl;

    GamePlayerWithoutArray gamePlayerWithoutArray;
    std::cout << "GamePlayerWithoutArray " << gamePlayerWithoutArray.numTurns() << std::endl;

    GamePlayerWithEnum gamePlayerWithEnum;
    std::cout << "GamePlayerWithEnum " << gamePlayerWithEnum.numTurns() << std::endl;

    int a = 5, b = 0;

    std::cout << CALL_WITH_MAX(++a, b) << std::endl;
    std::cout << CALL_WITH_MAX(++a, b + 10) << std::endl;

    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;

    int c = 5, d = 0;

    std::cout << callWithMax(++c, d) << std::endl;
    return 0;
}
