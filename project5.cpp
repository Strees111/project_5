#include <iostream>
#include <cstring>

inline void convertArabicToRoman(const char *arabicNumber, char romanNumber[]);

// Функция для преобразования римской цифры в арабское число
int romanToInt(char symbol) {
    switch (symbol) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            throw "wrong integer";
    }
}

// Функция для преобразования римского числа в арабское
inline long long convertRomanToArabic(const char *romanNumber) {
    long long arabicNumber = 0;
    int previousValue = 0;

    // Преобразование римского числа в арабское, начиная с конца строки
    for (int i = static_cast<int>(strlen(romanNumber)) - 1; i >= 0; i--) {
        int currentValue = romanToInt(romanNumber[i]);

        if (currentValue < previousValue) {
            arabicNumber -= currentValue;
        } else {
            arabicNumber += currentValue;
        }

        previousValue = currentValue;
    }

    // Проверка на превышение максимального значения 3999
    if (arabicNumber > 3999) {
        throw "wrong integer";
    }

    // Проверка корректности преобразования
    char arabicAsRoman[128]{};
    char arabicAsString[5]{};
    arabicAsString[0] = arabicNumber / 1000 % 10 + '0';
    arabicAsString[1] = arabicNumber / 100 % 10 + '0';
    arabicAsString[2] = arabicNumber / 10 % 10 + '0';
    arabicAsString[3] = arabicNumber % 10 + '0';
    arabicAsString[4] = '\0';

    convertArabicToRoman(arabicAsString, arabicAsRoman);

    for (int i = 0; arabicAsRoman[i] != '\0' || romanNumber[i] != '\0'; ++i) {
        if (arabicAsRoman[i] != romanNumber[i]) {
            throw "Invalid Roman numeral";
        }
    }

    return arabicNumber;
}

// Функция для преобразования арабского числа в римское
inline void convertArabicToRoman(const char *arabicNumber, char romanNumber[]) {
    const char *romanSymbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int arabicValues[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    int number = 0;
    for (int i = 0; arabicNumber[i] != '\0'; ++i) {
        number = number * 10 + (arabicNumber[i] - '0');
    }

    if (number > 3999) {
        throw "wrong integer";
    }

    int i = sizeof(arabicValues) / sizeof(arabicValues[0]) - 1;
    int index = 0;

    while (number > 0) {
        while (number >= arabicValues[i]) {
            for (int j = 0; romanSymbols[i][j] != '\0'; ++j) {
                romanNumber[index++] = romanSymbols[i][j];
            }
            number -= arabicValues[i];
        }
        --i;
    }

    romanNumber[index] = '\0';
}

// Функция для проверки входного значения и его конвертации
void checkInputAndConvert(const char *input) {
    int letterCount = 0;
    int digitCount = 0;
    size_t length = strlen(input);

    for (size_t i = 0; i < length; ++i) {
        if (isalpha(input[i])) {
            ++letterCount;
        } else if (isdigit(input[i])) {
            ++digitCount;
        }
    }

    if ((digitCount != length) && (letterCount != length)) {
        throw "wrong integer";
    }

    if (digitCount == length) {
        char romanNumber[128]{};
        convertArabicToRoman(input, romanNumber);
        std::cout << romanNumber << std::endl;
    } else if (letterCount == length) {
        std::cout << convertRomanToArabic(input) << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: program input" << std::endl;
        return 1;
    }

    try {
        checkInputAndConvert(argv[1]);
    }
    catch (const char *errorMessage) {
        std::cout << errorMessage << std::endl;
        return 0;
    }

    return 0;
}
