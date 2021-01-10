// constexpr - 상수 표현식
// 컴파일 시간에 계산되기 때문에, 배열을 정의할 때 사용 가능하다.
// 런타임에 실행 시킬 함수들은 통일시켜 주어야 한다.

// const
// 동일한 의미.
// 아래에는 예외케이스, 오른쪽에서 왼쪽으로 읽으면 해석이 쉽다.
int const* const ip = nullptr;
const int* const ip = nullptr;

// constexpr
// const시 오류
constexpr int getArraySize() {
    return 32;
}

class Rect
{
public:
    constexpr Rect(size_t width, size_t height) 
        : mWidth(width), mHeight(height) {}

    constexpr size_t getArea() const { return mWidth * mHeight; } 
private:
    size_t mWidth, mHeight;
};

int main() {
    int myArray[getArraySize()];

    constexpr Rect r(8, 2);
    int myArray2[r.getArea()];

    return 0;
}