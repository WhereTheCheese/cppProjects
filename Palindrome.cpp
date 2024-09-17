#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main() {
  cout << "test 1" << endl;
  char str[80];
  cin.get(str, 80, '\n');
  cout << str << endl;
  char str2[80];
  char str3[80];
  int count = 0;
  int num = 0;
  for (int i = 0; i < 80; i++) {
    if (str[i] == '\n' || str[i] == ' ' || str[i] == '.') {
      
	} else {
      str2[num] = str[i];
      //r3[num] = str[i];
      num++;
    }
  }
  int hi = 0;
  cout << str2 << endl;
  for (int o = 0; o < strlen(str2); o++) {
    cout << o << endl;
    if (str2[o] == str2[strlen(str2) - o]) {
      cout << "cheese" << endl;
      hi++;
    }
  }
  

  //for (int y = 0; y < strlen(str2); y++) {
  ///str3[y] = str2[strlen(str2) - y];
  //cout << "hi" << endl;
  //hi++;
  // }


  //reverse(str3, str3 + strlen(num ));
  cout << str3 << "hi" << endl;
  
      return 0;

    


}
