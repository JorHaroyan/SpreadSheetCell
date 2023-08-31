#pragma once

#include <iostream>

class SpreadSheet 
{
public:
    void addRow(int);
    void addCol(int);
    SpreadSheetCell* getCell(int, int) const;
    void setCell(int, int, const std::string&);
    void PrintSpreadsheet() const;
    int getRow() const;
    int getColumn() const;
    ~SpreadSheet();

private:
    SpreadSheetCell** m_cell = nullptr;
    int m_row = 0;
    int m_col = 0;
};
