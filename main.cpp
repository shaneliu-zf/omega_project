
using namespace std;


#include "include.hpp"

#include "func.hpp"
#include "val.hpp"
#include "cmd_func.hpp"



string ope[]={"+=","-=","*=","/=","+","-","*","/","="};

int main(){
    runCmd("clear");
    intro();
    string cmd;
    while(true){
        cout<<"(੭•̀ω•́)੭:";
        getline(cin,cmd);
        runCmd(cmd);
    }
    return 0;
}
