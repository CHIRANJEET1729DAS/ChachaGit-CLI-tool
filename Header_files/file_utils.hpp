#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "/home/chiranjeet/custom_git/header_files/commit.hpp"

using namespace std;

class Process {
public:
  static string readFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
      throw runtime_error("cannot open " + filePath);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }

  static void saveToRepo(const string& repoPath, const string& filename, const string& buffer) {
    ofstream file(repoPath + "/" + filename, ios::binary);
    if (file) {
      file.write(buffer.c_str(), buffer.size());
      file.close();
    }
  }

  static bool delete_off(const string& file_path) {
    if (remove(file_path.c_str()) != 0) {
      return false;
    }
    return true;
  }
};

#endif
