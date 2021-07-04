#include <iostream>
#include <exception>
using namespace std;

class my_exception: public exception{
  public:
  virtual const char *what() const throw(){
    return "Something BAADD happened!!";
  }
};

class test{
  public:
    void goes_wrong()
    {
      throw my_exception();
    }
};

int main() {
   cout << __PRETTY_FUNCTION__<< ": Hello World!\n";
   test tst;
   try {
     tst.goes_wrong();
    }
    catch (my_exception &e)
    {
        cout<<e.what()<<endl;
    }
    cout<< __PRETTY_FUNCTION__<<": still running\n"<<endl;
    return 0;
}