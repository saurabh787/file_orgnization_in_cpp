#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std::filesystem;

class my_file {
public:
    void create_folder(path direct);
    void create_file(path filePath);
    void file_iterate(const path& dirPath);
};

class organize {
public:
    void file_orgnize(const path& p);

private:
    std::string getCategory(const std::string& ext);
};

#endif
