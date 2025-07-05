

#include <filesystem>
#include <fstream>
#include <iostream>
#include "task.h"


// using namespace std;
using namespace std::filesystem;



int main(int argc, char* argv[]) {
    my_file obj;
    organize org;



    if (argc < 2) {
        std::cerr << "Usage:\n  " << argv[0] << " <source_dir>\n";
        return 1;
    }

    path source = argv[1];
    org.file_orgnize(source);

   

    
    

    path directorypath = "mydirectory";
    path direct = "mydirectory/subfolder";
    path fileDirect = "mydirectory/myTxt1.txt";

    // std::string path = "mydirectory";

    // org.file_orgnize(directorypath);
   
    // obj.create_folder(directorypath);

    // obj.create_file(fileDirect);

    // obj.file_iterate(directorypath);




    // int main(int argc, char* argv[]) {
    //     if (argc < 2 || argc > 3) {
    //         std::cout << "Usage:\n";
    //         std::cout << "  " << argv[0] << " <source_dir> [destination_dir]\n";
    //         return 1;
    //     }
    
    //     fs::path source = argv[1];
    //     fs::path destination = (argc == 3) ? argv[2] : argv[1];
    
    //     organizeFiles(source, destination);
    //     return 0;
    // }
    

    return 0;
}













// void FileOrganizer::organize(const path& directory) {
//     if (!exists(directory) || !is_directory(directory)) {
//         std::cerr << "Invalid directory!\n";
//         return;
//     }

//     for (const auto& entry : directory_iterator(directory)) {
//         if (entry.is_regular_file()) {
//             path filePath = entry.path();
//             std::string category = getCategory(filePath);

//             path destDir = directory / category;
//             if (!exists(destDir)) {
//                 create_directory(destDir);
//             }

//             path newLocation = destDir / filePath.filename();

//             try {
//                 rename(filePath, newLocation);
//                 std::cout << "Moved: " << filePath.filename() << " → " << category << "/\n";
//             } catch (const filesystem_error& e) {
//                 std::cerr << "Error moving file: " << e.what() << '\n';
//             }
//         }
//     }
// }

// std::string FileOrganizer::getCategory(const path& file) {
//     std::string ext = file.extension().string();

//     if (ext == ".txt" || ext == ".md") return "TextFiles";
//     if (ext == ".jpg" || ext == ".png" || ext == ".jpeg") return "Images";
//     if (ext == ".cpp" || ext == ".h") return "Code";
//     if (ext == ".pdf") return "Documents";
//     if (ext == ".mp3" || ext == ".wav") return "Audio";
//     if (ext == ".mp4" || ext == ".avi") return "Videos";

//     return "Others";
// }
