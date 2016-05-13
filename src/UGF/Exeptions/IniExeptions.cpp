#include "UGF/Exeptions/IniExeptions.h"
using namespace ugf;

IniFileExeption::IniFileExeption(IniFileExeptionCode code, std::string filename){
    switch (code) {
    case IniFileExeptionCode::CANNOT_OPEN:
        msg = "Cannot open file: " + filename;
        break;
    case IniFileExeptionCode::CANNOT_SAVE:
        msg = "Cannot save file: " + filename;
        break;
    case IniFileExeptionCode::PARSE_ERROR:
        msg = "Parsing error in file: " + filename;
    default:
        break;
    }
}

IniParseExeption::IniParseExeption(std::string filename, std::string line, int linenumber) : IniFileExeption(IniFileExeptionCode::PARSE_ERROR, filename){
    msg = "Parsing error in file: " + filename + " at line " + std::to_string(linenumber) + " - '" + line + "'";
}

IniVariableExeption::IniVariableExeption(IniVariableExeptionCode code, const std::string name, IniVariableType type){
    std::string vType;
    switch (type) {
    case IniVariableType::BOOL:
        vType = "bool"; break;
    case IniVariableType::FLOAT:
        vType = "float"; break;
    case IniVariableType::INTEGER:
        vType = "integer"; break;
    case IniVariableType::STRING:
        vType = "string"; break;
    case IniVariableType::NONE:
        vType = "none"; break;
    }

    switch (code) {
    case IniVariableExeptionCode::NOT_FOUND:
        msg = "Variable " + name + " of type " + vType + " not found";
        break;
    case IniVariableExeptionCode::FOUND_MANY:
        msg = "Variable " + name + " found in many types";
    default:
        break;
    }
}


const char* IniExeption::what(){
    return msg.c_str();
}
