#include "bingoCardGenerator.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int randomIntWithLimits(int lower, int upper) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lower, upper);

    return distribution(generator);
}

vector<string> generatePreamble() {
    ifstream preambleInput{PREAMBE_LOCATION};

    if (!preambleInput) {
        throw(
            runtime_error("File " + string(PREAMBE_LOCATION) + " not found."));
    }

    vector<string> preambleLines;

    string nextLine;
    while (getline(preambleInput, nextLine)) {
        preambleLines.emplace_back(nextLine);
    }
    return preambleLines;
}

vector<string> generatePostamble() {
    ifstream postableInput{POSTAMBLE_LOCATION};

    if (!postableInput) {
        throw(
            runtime_error("File " + string(PREAMBE_LOCATION) + " not found."));
    }

    vector<string> postambleLines;

    string nextLine;
    while (getline(postableInput, nextLine)) {
        postambleLines.emplace_back(nextLine);
    }

    return postambleLines;
}

void generateBingoCard() {
    ifstream bingoInput{READ_FROM};
    ofstream texOut{WRITE_TO};

    if (!bingoInput) {
        throw(runtime_error("File " + string(READ_FROM) + " not found"));
    }

    vector<string> bingoPhrases{};

    string nextLine;
    while (getline(bingoInput, nextLine)) {
        bingoPhrases.emplace_back(nextLine);
    }

    shuffle(bingoPhrases);

    for (string line : generatePreamble()) {
        texOut << line << endl;
    }

    int tableSize = static_cast<int>(sqrt(bingoPhrases.size()));

    tableSize = (tableSize > MAX_TABLE_SIZE ? MAX_TABLE_SIZE : tableSize);

    string tableSizeString = "c";

    for (int i = 1; i < tableSize; i++) {
        tableSizeString += "|c";
    }

    texOut << "\\begin{tabular}{|" + tableSizeString + "|}" << endl;
    texOut << "\\hline" << endl;

    for (int i = 0; i < tableSize; i++) {
        texOut << bingoPhrases.at(i * tableSize);

        for (int j = 1; j < tableSize; j++) {
            texOut << " & " << bingoPhrases.at(i * tableSize + j);
        }
        texOut << "\\\\ \\hline" << endl;
    }

    texOut << "\\end{tabular}";

    for (string line : generatePostamble()) {
        texOut << line << endl;
    }
}
