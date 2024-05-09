#pragma once

#include <cassert>
#include <filesystem>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const std::filesystem::path READ_FROM = "input.txt";
const std::filesystem::path WRITE_TO = "bingoCard.tex";
const std::filesystem::path PREAMBE_LOCATION = "preamble.tex";
const std::filesystem::path POSTAMBLE_LOCATION = "postamble.tex";
constexpr int MAX_TABLE_SIZE = 5;

template <typename T>
bool isInVector(std::vector<T> vec, T element) {
    for (T item : vec) {
        if (item == element) {
            return true;
        }
    }
    return false;
}

int randomIntWithLimits(int lower, int upper);

template <typename T>
void shuffle(std::vector<T>& vec) {
    for (int i = 0; i < vec.size() * 50; i++) {
        std::swap(
            vec.at(randomIntWithLimits(0, static_cast<int>(vec.size() - 1))),
            vec.at(randomIntWithLimits(0, static_cast<int>(vec.size() - 1))));
    }
}
std::vector<std::string> generatePostambe();
std::vector<std::string> generatePreamble();
void generateBingoCard();
