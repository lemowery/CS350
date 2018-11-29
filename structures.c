#include <stdio.h>

typedef struct PersonalInfo{
  char* name; //8 bytes
  int age; //4 bytes
  char* address; //8 bytes
} PersonalInfo; //20 bytes

// Definition of new datatypre named 'UserInfo'
// with two members using a structure
struct UserInfo{
  char* user_name; //8 bytes
  char* password; //8 bytes
  struct PersonalInfo personal_info;  //20 bytes
}; // Dont forget semicolon

// typedef allows us to create aliases of datatypes
// every time you see UserInfo it mesns 'struct UserInfo'
typedef struct UserInfo UserInfo;

void InitializeUserInfo(UserInfo* user, char* user_name, char* password, int age,
			char* name, char* address){
  (*user).user_name = user_name;
  user->password = password;
  user->personal_info.age = age;
  user->personal_info.name = name;
  user->personal_info.address = address;
}

int main(){
  UserInfo user; // creating instance of UserInfo
  InitializeUserInfo(&user, "lmowery", "password", 21, "Levi Mowery", "Morgantown");
  user.personal_info.age = 21;
  user.personal_info.name = "Levi Mowery";
  user.personal_info.address = "Morgantown";
  printf("Username: %s\n", user.user_name);
  printf("Password: %s\n", user.password);
  printf("Size of pointer: %ld\n", sizeof(user.user_name));
  printf("Size of UserInfo: %ld\n", sizeof(user));
  //size in bytes of these structures
  
  return 0;
}
