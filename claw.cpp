#include <iostream>
#include <filesystem>
#include <string>

// Laziness
using namespace std;
namespace fs = std::filesystem;

const string getInput(string question) {
  string answer;
  cout << question << endl;
  getline(cin, answer);
  return answer;
}

const void output(string output) {
  cout << output << endl;
}

// Function to search a directory for a file/directory and returns it
const fs::path findPath(string &directory, string &query) {
  fs::path cPath;
  for(fs::path path : fs::recursive_directory_iterator(directory)) {
    if(path.stem() == query)
      cPath = path;
  }
  return cPath;
}

int main() {
  string cont = "Y";
  fs::path cPath;
  do {
// Getting user input
    string input = getInput("Input Directory: ");
    if(!fs::exists(input)) {
      cout << "Error: That directory doesn't exist" << endl;
      continue;
    }
    do {
      string path = getInput("Path: ");

// Calling findPath, passing input directory and query
       cPath = findPath(input, path);
        if(!fs::exists(cPath)) {
          output("Error: That directory doesn't exist");
          continue;
        }
    } while(!fs::exists(cPath));

      string outDir = getInput("Output Directory: ");

// Copying
    string output = "Copying " + cPath.filename() + " (this may take awhile) ..."
    ouput(output);
    fs::copy(cPath, outDir);
    output("Copying complete!");

    cont = getInput("Press y to continue. \nPress anything else to exit");
  } while(cont == "Y"|| cont == "y");
}
