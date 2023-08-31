#include "SpreadSheet.h"
#include "SpreadSheetCell.h"

#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream&, const SpreadSheet&);

int main() {
    //SpreadSheetCell cell;
  //  cell.setStringValue("12.4");
//    std::cout << cell.getDoubleValue() << std::endl;
  
    //SpreadSheetCell cell2;
  //  cell2.setStringValue("text");
//    std::cout << cell2.getIntValue() << std::endl;
    

    SpreadSheet sp;

    sp.addRow(2);
    sp.addCol(2);
    sp.setCell(0, 0, "3.14");


    std::cout << sp << std::endl;

    return 0;
}


std::ostream& operator<<(std::ostream& out, const SpreadSheet& obj) {
    size_t max_size_of_value = 0;
    for (size_t i {}; i < obj.getRow(); ++i) {
        for (size_t j {}; j < obj.getColumn(); ++j) {
            std::string current_SpreadsheetCell_value = obj.getCell(i, j)->getStringValue();
            if (max_size_of_value < current_SpreadsheetCell_value.size()) {
                max_size_of_value = current_SpreadsheetCell_value.size();
            }
        }
    }
    size_t cell_size = max_size_of_value + 2;
    for (size_t i {}; i < obj.getRow(); ++i) {
        for (size_t j {}; j < cell_size*obj.getColumn(); ++j) {
            std::cout << "-";
        }
        std::cout << std::endl;
        for (size_t j {}; j < obj.getColumn(); ++j) {
            std::string current_SpreadsheetCell_value = obj.getCell(i, j)->getStringValue();
            std::cout << "|" << current_SpreadsheetCell_value;
            for (size_t k {}; k < cell_size - current_SpreadsheetCell_value.size() - 2; ++k) {
                std::cout << " ";
            }
            std::cout << "|";
        }
        std::cout << std::endl;
    }
    for (size_t j {}; j < cell_size*obj.getColumn(); ++j) {
        std::cout << "-";
    }
    std::cout << std::endl;
    return out;
}

