#include "UGF/IniFile.h"
#include <fstream>
#include <sstream>
using std::string;
using std::map;
using std::ifstream;
using std::ios;
using namespace ugf;

IniFile::IniFile(){}


void IniFile::loadFromFile(const string& filename) {
    ifstream file;
    file.open(filename, ios::in);
    if (file.fail())
        throw IniFileExeption(IniFileExeptionCode::CANNOT_OPEN, filename);

    string line;
  	int lineNumber = 0;
    string categoryName;
    while (getline(file, line)) {
		lineNumber++;
        if (line.length() == 0)
            continue;

		if (line.at(0) == '#' || line.at(0) == ';')
            continue;
		//Changing category
        if(line.at(0) == '['){
            categoryName = "";
            for (unsigned int i=1; i<line.length(); i++)
				if(line.at(i) != ']')
					categoryName += line.at(i);
				else
                    continue;
            continue;
        }

		//Parsing Variables
        string variableName;
        string variableValue;
        unsigned int charNumberInLine = 0;

        //Parsing Variable's name
        while(line.at(charNumberInLine) != '=') {
            if (!isspace(line.at(charNumberInLine)))
				variableName += line.at(charNumberInLine);
			charNumberInLine++;
        }
        charNumberInLine++;

		//Parsing Variable value
		bool stringMode = false;
        bool specialChar = false; //the \ sign for " sign in strings
        for (; charNumberInLine < line.length(); charNumberInLine++) {
			if (stringMode && line.at(charNumberInLine) == '"' && !specialChar)
				break;
			if (line.at(charNumberInLine) == '"' && variableValue.length() == 0)
				stringMode = true;
            else if (line.at(charNumberInLine) == '\\')
				specialChar = true;
			else if (stringMode)
				variableValue += line.at(charNumberInLine);
            else if ((line.at(charNumberInLine) == '#' || line.at(charNumberInLine) == ';' ) && !stringMode )
				break; //comment
            else if (!isspace(line.at(charNumberInLine)))
				variableValue += line.at(charNumberInLine);
		}

		if (!stringMode && variableValue.length() == 0)
            throw IniParseExeption(filename, line, lineNumber);

		//Add Variable to category
		if (stringMode) {
            getCategory(categoryName).setString(variableName, variableValue);
		} else if (variableValue == "true")
            getCategory(categoryName).setBool(variableName, true);
		else if (variableValue == "false")
      getCategory(categoryName).setBool(variableName, false);
    else if (variableValue.at(variableValue.length()-1) == 'f') { //float
  		variableValue.erase(variableValue.length()-1);
      getCategory(categoryName).setFloat(variableName, stof(variableValue));
        } else {
			try {
              getCategory(categoryName).setInteger(variableName, stoi(variableValue));
            } catch (const std::invalid_argument) {
                throw IniParseExeption(filename, line, lineNumber);
			}
		}


	}

}

IniCategory& IniFile::getCategory(const string& name){
    if (categories.find(name) == categories.end())
        categories[name] = IniCategory();
    return categories[name];
}

void IniCategory::setBool(const string& name, bool value){
    bools[name] = value;
}

void IniCategory::setFloat(const string& name, float value){
    floats[name] =  value;
}

void IniCategory::setInteger(const string& name, int value){
    integers[name] = value;
}

void IniCategory::setString(const string& name, const string& value){
    strings[name] = value;
}

bool IniCategory::getBool(const string& name){
    if (bools.count(name) == 0)
        throw IniVariableExeption(IniVariableExeptionCode::NOT_FOUND, name, IniVariableType::BOOL);
    return bools[name];
}

float IniCategory::getFloat(const string& name){
    if (floats.count(name) == 0)
        throw IniVariableExeption(IniVariableExeptionCode::NOT_FOUND, name, IniVariableType::FLOAT);
    return floats[name];
}

string IniCategory::getString(const string& name){
    if (strings.count(name) == 0)
        throw IniVariableExeption(IniVariableExeptionCode::NOT_FOUND, name, IniVariableType::STRING);
    return strings[name];
}

int IniCategory::getInteger(const string& name){
    if (integers.count(name) == 0)
        throw IniVariableExeption(IniVariableExeptionCode::NOT_FOUND, name, IniVariableType::INTEGER);
    return integers[name];
}
