#include <iostream>
#include <limits> // std::numeric_limits

int main() {
    int user_input;

    do {
        std::cout << "정수를 입력하세요: ";

        // 사용자 입력 확인
        if (!(std::cin >> user_input)) {
            std::cerr << "오류: 정수를 입력하세요." << std::endl;

            // 에러 발생 시 입력 버퍼 비우기
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // 정상적인 입력일 때 루프 종료
            break;
        }
    } while (true);

    std::cout << "입력한 정수: " << user_input << std::endl;

    return 0;
}
