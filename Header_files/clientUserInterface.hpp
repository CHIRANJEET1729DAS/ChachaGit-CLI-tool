#ifndef CLIENTUSERINTERFACE_HPP
#define CLIENTUSERINTERFACE_HPP

#include "/home/chiranjeet/custom_git/header_files/respository.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class CLI {
  private:
    Repository repository;
    string repo_path;

  public:
    CLI() {
      repository.init();
    }

    void start() {
      string command;
      cout << "Welcome to ChachaGit CLI. Type 'exit' to quit." << endl;

      while (true) {
        cout << ":)  ";
        getline(cin, command);
        if (command == "exit") break;
        processCommand(command);
      }
    }

  private:
    void processCommand(const string& command) {
      string cmd, arg1, arg2;
      istringstream iss(command);

      // Read the command and ignore the "chacha" prefix
      iss >> cmd; // Read "chacha"
      if (cmd != "chacha") {
        cout << "Unknown command: " << command << endl;
        cout << "Available operations: setrepo, add, delete, logs" << endl;
        return;
      }

      // Read the actual command after "chacha"
      iss >> cmd; // Read the actual command (setrepo, add, delete, logs)
      iss >> arg1 >> arg2; // Read any additional arguments

      if (cmd == "setrepo") {
        cout << "Enter the repository path: ";
        getline(cin, repo_path);
        repository.setRepoPath(repo_path);
        cout << "Repository path set to: " << repo_path << endl;

      } else if (cmd == "add") {
        if (arg1.empty() || arg2.empty()) {
          cout << "Usage: add <file_path> <file_name>" << endl;
          return;
        }
        try {
          repository.add(arg1, arg2); // Pass only relevant args
          cout << "File added successfully." << endl;
        } catch (const runtime_error& e) {
          cerr << e.what() << endl;
        }

      } else if (cmd == "delete") {
        if (arg1.empty()) {
          cout << "Usage: delete <file_name>" << endl;
          return;
        }
        try {
          repository.delete_it(arg1); // Pass the file name
          cout << "File deleted successfully." << endl;
        } catch (const runtime_error& e) {
          cerr << e.what() << endl;
        }

      } else if (cmd == "logs") {
        repository.logMessages();

      } else {
        cout << "Unknown command: " << cmd << endl;
        cout << "Available operations: setrepo, add, delete, logs" << endl;
      }
    }



};
#endif
