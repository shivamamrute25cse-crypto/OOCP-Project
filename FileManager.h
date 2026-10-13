#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
class BookStore;
class FileManager {
private:
    std::string dataDirectory;
public:
    explicit FileManager(std::string directory = "Data");
    bool save(const BookStore& store) const;
    bool load(BookStore& store) const;
    const std::string& getDirectory() const;
};
#endif
