#pragma once
#include <string>
#include <map>
#include "UGF/Exeptions/IniExeptions.h"

namespace ugf {

class IniCategory;

/***
     * #comment
     * ;comment2
     * [Category]
     * string = "abc"
     * bool = true
     * int = 12
     * float = 10.34f
    */

class IniFile {
public:
    IniFile();

    void loadFromFile(const std::string& filename);
	void loadFromMemory(char* address);
    void saveToFile(const std::string& filename);

    bool categoryExists(const std::string& name);
    IniCategory& getCategory(const std::string& name);
    void deleteCategory(const std::string& name);
private:
    void addCategory(const std::string& name);
    std::map<std::string, IniCategory> categories;
//    maybe map<int, std::string> comments ?
};

class IniCategory {
public:
    bool isSetString(std::string& name);
    bool isSetBool(std::string& name);
    bool isSetInteger(std::string& name);
    bool isSetFloat(std::string& name);

    std::string getString(const std::string& name);
    bool getBool(const std::string& name);
    int getInteger(const std::string& name);
    float getFloat(const std::string& name);

    void setString(const std::string& name, const std::string& value);
    void setBool(const std::string& name, bool value);
    void setInteger(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
    void deleteVariable(const std::string& name);
private:
    std::map<std::string, std::string> strings;
    std::map<std::string, bool> bools;
    std::map<std::string, int> integers;
    std::map<std::string, float> floats;
    std::map<std::string, double> doubles;
};



}
