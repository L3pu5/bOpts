#include <string>
#include <map>
#include <vector>
#include "bOpts.h"
// 
// bOpts: Bunny command parsing.
//      https://github.com/L3pu5/bOpts
//      By L3pu5, L3pu5_Hare, Lepus Hare.

//TestCase: .\bOpts.exe -X -F Fswitch -E eSwitch floating1 -K kswitch floating2 floating3 last_3 last_2 last_1
//Should output: 
// eSwitch                                                                                                                                             kswitch
// kswitch
// floating3
// last_3
// last_2
// last_1
// floating2
// floating3
// last_3
// last_2
// last_1
// 1 
// 0 
int main(int argc, char * argv[]){
   bOpts::SetOpts("Fireworks", std::vector<std::string> {"F", "K"});
    bOpts::SetToggleOpts({"X", "Y", "Z"});
    bOpts::MakeOpts(argc, argv);
    printf("%s\n", bOpts::GetOpt("E").c_str());
    printf("%s\n", bOpts::GetOpt("Fireworks").c_str());
    printf("%s\n", bOpts::GetFloatingOpt(2).c_str());
    printf("%s\n", bOpts::GetOpt(2, true).c_str());
    printf("%s\n", bOpts::GetOpt(2, false).c_str());
    printf("%s\n", bOpts::GetOpt(1, false).c_str());
    printf("%s\n", bOpts::GetOpt(0, false).c_str());
    printf("%s\n", bOpts::GetFloatingOpt(1).c_str());
    printf("%s\n", bOpts::GetFloatingOpt(2).c_str());
    printf("%s\n", bOpts::GetFloatingOpt(3).c_str());
    printf("%s\n", bOpts::GetFloatingOpt(4).c_str());
    printf("%s\n", bOpts::GetFloatingOpt(5).c_str());
    printf("%s\n", std::to_string(bOpts::GetToggleOpt("X")).c_str());
    printf("%s\n", std::to_string(bOpts::GetToggleOpt("Z")).c_str());
    return 0;
}
