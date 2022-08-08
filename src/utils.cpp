#include "utils.h"
#include <string>
#include <QString>

#include <sys/stat.h>

inline bool file_exists(const std::string& filename)
{
    struct stat buffer;
    return (stat (filename.c_str(), &buffer) == 0);
}

inline bool file_exists(const QString filename)
{
    struct stat buffer;
    return (stat (filename.toStdString().c_str(), &buffer) == 0);
}