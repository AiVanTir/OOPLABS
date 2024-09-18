#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "modify.hpp"

/**
 * @brief Функция для проверки строки на соответствие формату.
 *
 * Эта функция принимает строку и проверяет ее на соответвией формату [Name] указанному в индивидуальном задании.
 *
 * @param Input Проверяемая строка.
 * @return Возвращает True при верном формате, False при неверном.
 */

bool CheckName(const std::string& Input){ 
    size_t Length = Input.length();
    return Length < 2 || (Input.front() != '[' || Input.back() != ']');
}

/*bool CheckExpression(const std::string& Input, int LastInd) {  //старая верия проверки выражения на правильный формат
    size_t  Index = Input.find('=');
    if (Index == std::string::npos || Index == 0 || Index == Input.length() - 1) {
        return false;
    }
    for (size_t i = 0; i < Index; ++i) {
        if (!std::isdigit(Input[i])) {
            return false;
        }
    }
    if(std::stoi(Input.substr(0, Index)) != LastInd + 1){
        return false;
    }
    for (size_t i = Index + 1; i < Input.length(); ++i) {
        if (!std::isdigit(Input[i])) {
            return false;
        }
    }
    return true;
}*/

/**
 * @brief Функция для проверки строки на соответствие формату.
 *
 * Эта функция принимает строку и проверяет ее на соответвией формату int = int указанному в индивидуальном задании.
 *
 * @param Line Проверяемая строка.
 * @param EqualIndex Индекс знака равенства в строке
 * @param LastInd Индекс предыдущего элемента, который должен быть на 1 меньше нового
 * @return Возвращает True при верном формате, False при неверном.
 */

bool CheckExpression(const std::string& Line, size_t EqualIndex, int LastInd){
    return ((std::stoi(Line.substr(0, EqualIndex)) == LastInd + 1) 
        && (EqualIndex != std::string::npos 
        && EqualIndex != 0 && EqualIndex != Line.length() - 1));
}

/**
 * @brief Вариация перегрузки функции перевода строки формата в массив.
 *
 * Эта функция принимает массив символов и размер этого массива, и возвращает массив целых чисел исходя из написанного в строке.
 *
 * @param Input Входной массив.
 * @param Size Размер массива.
 * @return Возвращает массив целых числе формата std::vector.
 */

std::vector<int> ConvertToVector(const char* Input, size_t Size) {
    std::vector<int> Numbers;
    std::string Line;
    std::stringstream Stream(std::string(Input, Size));
    std::getline(Stream, Line);
    if(!CheckName(Line)){
        throw std::runtime_error("Неверный формат имени");
    }
    int LastInd = 0;
    while (std::getline(Stream, Line)) {
        size_t EqualIndex = Line.find('=');
        if(!CheckExpression(Line, EqualIndex, LastInd)){
            throw std::runtime_error("Неверный формат строки");
        }
        LastInd++;
        int Number = std::stoi(Line.substr(EqualIndex + 1));
        Numbers.push_back(Number);
    }
    return Numbers;
}

/**
 * @brief Вариация перегрузки функции перевода строки формата в массив.
 *
 * Эта функция принимает указатель на нуль-терменированную строку, и возвращает массив целых чисел исходя из написанного в строке.
 *
 * @param Input Входная строка.
 * @return Возвращает массив целых числе формата std::vector.
 */

std::vector<int> ConvertToVector(const char* Input) {
    return ConvertToVector(Input, strlen(Input));
}

/**
 * @brief Вариация перегрузки функции перевода строки формата в массив.
 *
 * Эта функция принимает строку формата std::string, и возвращает массив целых чисел исходя из написанного в строке.
 *
 * @param Input Входная строка.
 * @return Возвращает массив целых числе формата std::vector.
 */

std::vector<int> ConvertToVector(const std::string& Input) {
    return ConvertToVector(Input.c_str(), Input.size());
}

/**
 * @brief Фунция перевода массива чисел в строку формата toml.
 *
 * Эта функция принимает массив числе и название массива, и возвращает строку формата toml.
 *
 * @param Numbers Входной массив.
 * @param ArrName Имя массива.
 * @return Строка форма std::string формата toml.
 */

std::string ConvertToString(const std::vector<int>& Numbers, const std::string ArrName) { //заменить на стандартный алгоритм
    std::string Result;
    Result += "[" + ArrName + "]" + "\n";
    for (size_t i = 0; i < Numbers.size(); ++i) {
        Result +=  std::to_string(i + 1) + "=" + std::to_string(Numbers[i]) + "\n";
    }
    return Result;
}