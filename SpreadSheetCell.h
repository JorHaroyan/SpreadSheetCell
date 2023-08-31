# pragma once

#include <iostream>
#include <string>

class SpreadSheetCell
{
public:
    std::string getStringValue() const;
    void setStringValue(const std::string&);
    int getIntValue() const;
    double getDoubleValue() const;

private:
    std::string m_value;
};

