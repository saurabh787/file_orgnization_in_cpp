#include "task.h"

void my_file::create_folder(path direct) {
    if (!exists(direct)) {
        create_directories(direct);
    } else {
        std::cout << "Directory already exists.\n";
    }
}

void my_file::create_file(path filePath) {
    if (!exists(filePath)) {
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << "Hello, FileSystem!";
            file.close();
            std::cout << "File created.\n";
        } else {
            std::cerr << "Failed to create or open file: " << filePath << std::endl;
        }
    } else {
        std::cout << "Already exists\n";
    }
}

void my_file::file_iterate(const path& dirPath) {
    try {
        for (const auto& entry : directory_iterator(dirPath)) {
            const path& p = entry.path();
            std::cout << (is_directory(p) ? "[Dir]" : "[File]") << " " << p.filename().string() << "\n";
        }
    } catch (const filesystem_error& e) {
        std::cerr << e.what() << '\n';
    }
}

void organize::file_orgnize(const path& p) {
    if (!exists(p) || !is_directory(p)) {
        std::cerr << "Invalid directory!\n";
        return;
    }

    for (const auto& entry : directory_iterator(p)) {
        if (entry.is_regular_file()) {
            path myfile = entry.path();
            std::string str = myfile.extension().string();
            std::string category = getCategory(str);

            path categoryPath = p / category;

            if (!exists(categoryPath)) {
                create_directories(categoryPath);
            }

            path target_path = categoryPath / myfile.filename();

            try {
                rename(myfile, target_path);
                std::cout << "File moved\n";
            } catch (const filesystem_error& e) {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

std::string organize::getCategory(const std::string& ext) {
    if (ext == ".txt" || ext == ".md") return "TextFiles";
    if (ext == ".jpg" || ext == ".JPG" || ext == ".png" || ext == ".jpeg") return "Images";
    if (ext == ".cpp" || ext == ".h") return "Code";
    if (ext == ".pdf") return "Documents";
    if (ext == ".mp3" || ext == ".wav") return "Audio";
    if (ext == ".mp4" || ext == ".avi") return "Videos";
    return "others";
}
