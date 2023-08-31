#include "SpreadSheetCell.h"
//#include "SpreadSheet.h"

#include <iostream>
#include <string>


bool isConvertibleToDouble(const std::string& str) {
    bool result = false;
    try {
        
        std::stod(str);

        result = true;
    } catch (...) {
    }
    return result;
}

std::string SpreadSheetCell::getStringValue() const {
    return m_value;
}
void SpreadSheetCell::setStringValue(const std::string& value) {
    m_value = value;
}
int SpreadSheetCell::getIntValue() const {
    for (int i = 0; i < m_value.size(); ++i) {
        if (m_value[i] > '9' && m_value[i] < '0') {
            throw std::runtime_error("error: is not integer!");
        }
    }
    int num = std::stoi(m_value);
    return num;
}

double SpreadSheetCell::getDoubleValue() const {
    if (!isConvertibleToDouble(m_value)) {
        throw std::runtime_error("error: is not double");
    }
    double d_num = stod(m_value);
    return d_num;
}



























