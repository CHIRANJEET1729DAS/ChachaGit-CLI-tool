# ChachaGit 

## Project Overview

ChachaGit is a lightweight command-line interface (CLI) tool developed as a personal project to simulate basic version control functionalities inspired by Git. It provides users with an intuitive interface to manage files in a local repository, allowing for operations such as adding, deleting, and logging files. 

The primary goal of ChachaGit is to enhance understanding of version control systems by building a custom implementation from scratch. This project serves as an educational tool to grasp the underlying concepts of file management, data structures, and the mechanics of version control without the complexity of existing systems.

### Key Objectives
- **Understand Version Control**: The project aims to explore how version control systems work, focusing on file management and data persistence.
- **Develop C++ Skills**: By implementing a project like ChachaGit, users can enhance their C++ programming and software design skills.
- **Encourage Best Practices**: The project encourages the use of best coding practices, such as modular design and clean coding, which are essential in software development.

## Functionality

ChachaGit supports the following functionalities:

- **Set Repository Path**: Users can specify the local directory that will act as the repository. This directory will store all files managed by ChachaGit.
  
- **Add Files**: Users can add files to the repository, providing a local file path and a custom name to associate with that file. This feature stores the file’s content along with the associated name in a hashmap for quick access.

- **Delete Files**: Users can remove files from the repository using the associated name. This operation updates the internal hashmap and deletes the actual file from the local filesystem.

- **Log Commit Messages**: Users can view a log of all actions performed in the repository, helping them keep track of changes over time.

## Technical Details

### Data Structure
ChachaGit employs a custom hashmap combined with a linked list to manage file associations efficiently. This hybrid data structure allows for quick retrieval of file information while maintaining the order of operations through the linked list. 

### Implementation Highlights
- **Node Class**: Represents an individual entry in the hashmap, containing key-value pairs (file name and content) and pointers for linked list traversal.
  
- **Repository Class**: Manages the core functionalities of ChachaGit, including methods for adding and deleting files, logging actions, and initializing the repository.

- **Command Line Interface (CLI)**: The user interacts with ChachaGit through a simple command-line interface that accepts various commands to manipulate the repository.

### File Management
ChachaGit ensures that files are not only managed in memory but also physically stored in the specified repository path. When a file is added or deleted, the application performs the necessary filesystem operations, ensuring that the user's filesystem remains in sync with the internal state of ChachaGit.

### Error Handling
The application includes robust error handling to manage common issues, such as:
- Invalid file paths.
- Non-existent files during delete operations.
- Problems with file I/O operations.

## Future Improvements
ChachaGit is designed as a foundational project with potential for future enhancements, including:
- **Branching and Merging**: Implementing features to support branching and merging of file changes.
- **Conflict Resolution**: Adding logic to handle file conflicts during concurrent modifications.
- **User Interface Enh**
[CLI](/home/chiranjeet/Pictures/Screenshots/Screenshot_20241103_190415.png)
