//#include <iostream>
#include <string>
#include <map>
#include <typeinfo>

int bOpts_FLOATINGCOUNT = 0;
std::map <std::string, std::string> bOpts_MAP = std::map<std::string, std::string>();

void populate(int argc, char* _argv[]){
    //Internal variables
    bool _priorSwitch = 0;
    std::string _key = "";
    //Main Loop.
    for (int i = 1; i < argc; i++)
    {
        //Read the string
        std::string _argument(_argv[i]);
        //Check if prior was a switch
        if(_priorSwitch == 0){
            //If not, is this a switch?
            if(_argument.at(0) == '-'){
                _key = _argument.substr(1);
                _priorSwitch = 1;
                continue;
            }
            _key += "Floating_";
            _key += std::to_string(bOpts_FLOATINGCOUNT);
            //If this is a value and not a switch, feed it into the map as one of the floating values.
            bOpts_MAP.insert({_key, _argument});
            bOpts_FLOATINGCOUNT++;
            _key = "";
            continue;
        }
        //Prior was a switch
        //Read it directly
        bOpts_MAP[_key] = _argument;
        _key = "";
        _priorSwitch = 0;
        continue;
    }

    
}

int main(int argc, char * argv[]){
    populate(argc, argv);
}