#include <exception>
#include <string>

namespace ugf{

enum class IniFileExeptionCode{
    CANNOT_OPEN,
    CANNOT_SAVE,
    PARSE_ERROR,
};

enum class IniVariableType{
    BOOL,
    INTEGER,
    FLOAT,
    STRING,
    NONE
};

enum class IniVariableExeptionCode{
    NOT_FOUND,
    FOUND_MANY
};


class IniExeption : public std::exception{
protected:
    std::string msg;
    virtual const char* what();
};

class IniFileExeption : public IniExeption {
public:
    IniFileExeption(IniFileExeptionCode code, std::string filename);
};

class IniParseExeption : public IniFileExeption{
public:
    IniParseExeption(std::string filename, std::string line, int linenumber);
};

class IniVariableExeption : public IniExeption{
public:
    IniVariableExeption(IniVariableExeptionCode code, const std::string name, IniVariableType type = IniVariableType::NONE);
};

}
