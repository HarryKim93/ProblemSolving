#include <cstddef>
#include <string_view>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class SpreadSheetCell {
public:
    SpreadSheetCell() = default;

    SpreadSheetCell(double inValue) {
        mValue = inValue;
    }

    void setString(string_view inString) {
        mValue = stringToDouble(inString);
    }

    void setValue(double inValue) {
        mValue = inValue;
    }

    double getValue() const {
        return mValue;
    }

    string getString() const {
        return doubleToString(mValue);
    }

private:
    string doubleToString(double inValue) const {
        return to_string(mValue);
    }

    double stringToDouble(string_view inString) const {
        return strtod(inString.data(), nullptr);
    }

    double mValue;
};

class SpreadSheet {
public:
    friend void swap(SpreadSheet& first, SpreadSheet& second) noexcept;

    SpreadSheet(const SpreadSheet& src) : SpreadSheet(src.mWidth, src.mHeight) {
        cout << "copy constructor\n";
        for (size_t i = 0; i < mWidth; i++) {
            for (size_t j = 0; j < mHeight; j++) {
                mCells[i][j] = src.mCells[i][j];
            }
        }
    } 

    SpreadSheet(SpreadSheet&& src) noexcept : SpreadSheet() {
        cout << "move constructor\n";
        swap(*this, src);
    }

    SpreadSheet(size_t width, size_t height) : mWidth(width), mHeight(height) {
        cout << "normal constructor\n";
        mCells = new SpreadSheetCell*[mWidth];
        for (size_t i = 0; i < mWidth; i++) {
            mCells[i] = new SpreadSheetCell[mHeight];
            for (size_t j = 0; j < mHeight; j++) {
                mCells[i][j] = SpreadSheetCell(0);
            }
        }
    }

    SpreadSheet& operator=(const SpreadSheet& rhs) {
        cout << "copy assignment constructor\n";
        if (this == &rhs) {
            return *this;
        }

        SpreadSheet temp = rhs;
        swap(*this, temp);

        return *this;
    }

    SpreadSheet& operator=(SpreadSheet&& rhs) noexcept {
        cout << "move assignment constructor\n";
        SpreadSheet temp(move(rhs));
        swap(*this, temp);
        return *this;
    }

    ~SpreadSheet() {
        for (size_t i = 0; i < mWidth; i++) {
            delete[] mCells[i];
        }

        delete []mCells;
        mCells = nullptr;
    }

    void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell) {
        verifyCoordinate(x, y);
        mCells[x][y] = cell;
    }

    SpreadSheetCell& getCellAt(size_t x, size_t y) {
        return const_cast<SpreadSheetCell&>(as_const(*this).getCellAt(x, y));
    }

    const SpreadSheetCell& getCellAt(size_t x, size_t y) const {
        verifyCoordinate(x, y);
        return mCells[x][y];
    }

    void print() {
        try {
            cout << getCellAt(4, 4).getValue() << "\n";
        } catch (exception& e) {
            cout << e.what() << "\n";
        }
    }

private:
    SpreadSheet() = default;

    void verifyCoordinate(size_t x, size_t y) const {
        if (x >= mWidth || y >= mHeight) {
            throw out_of_range("");
        }
    }
 
    bool inRange(size_t value, size_t upper) const;
    size_t mWidth = 0;
    size_t mHeight = 0;
    string mName = "";
    SpreadSheetCell** mCells = nullptr;
};

void swap(SpreadSheet& first, SpreadSheet& second) noexcept {
    using std::swap;
    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}

void printSpreadsheet(SpreadSheet s) {
    //something
} 

SpreadSheet createObject() {
    return SpreadSheet(3, 2);
}

int main() {
    // vector<SpreadSheet> vec;
    // for (int i = 0; i < 2; i++) {
    //     cout << "Iteration " << i << "\n";
    //     vec.push_back(SpreadSheet(100, 100));
    // }

    SpreadSheet s(2, 3);
    s = createObject();

    cout << "\n";

    SpreadSheet s2(5, 6);
    s2 = s;

    return 0;
}