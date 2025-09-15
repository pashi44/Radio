#include  <zephyr/kernel.h>
#include  <iostream>


extern "C" void call_c();


 using namespace  std;
  int main(){

    call_c();


    return  0;
  }


  extern "C"   void call_c(){

  cout << "in the c  func "  <<  endl;

while(1){
    k_msleep(1000);
}



  }