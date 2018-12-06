#include <iostream>
#include <fstream>
#include <string>
#include "BookClass.h"
using namespace std;
class readFile{
private:
  BookClass *head;
public:
  readFile(BookClass *head);
  bool readFileFunction();
};
