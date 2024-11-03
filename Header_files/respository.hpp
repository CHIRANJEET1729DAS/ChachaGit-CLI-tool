#include "/home/chiranjeet/custom_git/header_files/commit.hpp" // Assuming Commit class is defined in commit.hpp
#include "/home/chiranjeet/custom_git/header_files/file_utils.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Repository {
private:
  string repo_path;
  Commit commit; // Assuming you have a Commit class to manage commits

public:
  void init() {}

  void setRepoPath(const string& path) {
    repo_path = path;
  }

  void add(const string& file_path, const string& name_for_the_file) {
    string content = Process::readFile(file_path);
    Process::saveToRepo(repo_path, name_for_the_file, content);
    commit.add(name_for_the_file, content); // Use the commit instance
  }

  void delete_it(const string& file_name) {
    if (commit.get_Length() == 0) {
      throw runtime_error("Repository is already empty.");
    }

    string fullFilePath = repo_path + "/" + file_name;
    std::fstream fs(fullFilePath, std::ios::in);
    if (!fs) {
      throw runtime_error("Error: File does not exist at " + fullFilePath);
    }
    fs.close();

    if (!Process::delete_off(fullFilePath)) {
      throw runtime_error("Error deleting file: " + fullFilePath);
    }

    commit.removeLastCommit(); // Use the commit instance
  }

  void logMessages() {
    commit.printList(); // Use the commit instance
  }
};
