#include "SpreadSheet.h"
#include "SpreadSheetCell.h"

#include <iostream>
#include <string>

int SpreadSheet::getRow() const {
    return m_row;
}
int SpreadSheet::getColumn() const {
    return m_col;
}

void SpreadSheet::addRow(int row) {
    if (row <= 0) {
        throw std::runtime_error("error: invalid row");
    }
    if (m_cell == nullptr) {
        m_row = row;
        m_cell = new SpreadSheetCell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            if(m_col == 0) {
                m_cell[i] = nullptr;
            }
            else {
                m_cell[i] = new SpreadSheetCell[m_col];
            }
        }
    }
    else {
        SpreadSheetCell** temp = new SpreadSheetCell*[m_row + row];
        if (m_cell[0] == nullptr) {
            for (int i = 0; i < m_row + row; ++i) {
                temp[i] = nullptr;
            }
        }
        else {
            for (int i = 0; i < m_row + row; ++i) {
                temp[i] = new SpreadSheetCell[m_col];
            }
            for (int i = 0; i < m_row; ++i) {
                for (int j = 0; j < m_col; ++j) {
                    temp[i][j] = m_cell[i][j];
                }
            }
        }
        for (int i = 0; i < m_row; ++i) {
            delete[] m_cell[i];
        }
        delete m_cell;
        m_cell = temp;
        temp = nullptr;
        m_row += row;
    }
}

void SpreadSheet::addCol(int col) {
    if (col <= 0) {
        throw std::runtime_error("error: invalid column");
    }
    if (m_cell == nullptr) {
        m_col = col;
    }
    else {
        SpreadSheetCell** temp = new SpreadSheetCell*[m_row];
        for (int i = 0; i < m_row; ++i) {
            temp[i] = new SpreadSheetCell[m_col + col];
        }
        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_col; ++j) {
                temp[i][j] = m_cell[i][j];
            }
        }
        for (int i = 0; i < m_row; ++i) {
            delete[] m_cell[i];
        }
        delete m_cell;
        m_cell = temp;
        temp = nullptr;
        m_col += col;
    }
}
SpreadSheetCell* SpreadSheet::getCell(int y, int x) const{
    if (x > m_col  x < 0  y < 0 || y > m_row) {
        throw std::out_of_range("error: invalid coordinates");
    }
    return &m_cell[y][x];
}

void SpreadSheet::setCell(int y, int x, const std::string& value) {
    if (x >= 0 && x < m_row && y >= 0 && y < m_col) {
        m_cell[y][x].setStringValue(value);
    }
    else {
        throw std::out_of_range("error: invalid coordinates");
    }
}


void SpreadSheet::PrintSpreadsheet() const {
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            std::cout << m_cell[i][j].getStringValue() << "\t|";
        }
        std::cout << std::endl;
    }
}

SpreadSheet::~SpreadSheet() {
    for (int i = 0; i < m_row; ++i) {
        delete[] m_cell[i];
    }
    delete[] m_cell;
}



