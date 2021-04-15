#include <iostream>
#include <regex>

int main()
{

//    std::regex re(R"(\d+)");
//    std::smatch m;
//    std::string text = "1234";
//    bool res = std::regex_search(text, m, re); //zwróci wartość true
//    std::cout<<res<<std::endl;
//    std::cout<<m.str(0)<<std::endl;
//    text = "1234m 78910";
//    res = std::regex_search(text, m, re); //zwróci wartość true i zwróci do m pierwszy pasujący podciąg czyli 1234
//    std::cout<<res<<std::endl;
//    std::cout<<m.str(0)<<std::endl;
    std::cout << std::endl << "regex_search all" << std::endl;
    std::string log(R"(
          Speed: 366
          Mass: 35
          Speed: 378
          Mass: 32
          Speed: 400
          Mass: 30)");
    std::regex re(R"(Speed:\s(\d+))");
    std::smatch sm;
    while (regex_search(log, sm, re)) {
          std::cout << sm[0] << std::endl; //Podciąg dla którego wzorzec jest w pełni dopasowany
          std::cout << "Group 1: " << sm[1] << std::endl << std::endl; //grupa nr 1 (\d*)

          log = sm.suffix(); //przycięcie napisu do przeszukania
    }
    return 0;
}
