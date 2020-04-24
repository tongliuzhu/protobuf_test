#include <stdio.h>
#include <iostream>
#include <string>
#include "addressbook.pb.h"
using namespace std;
using namespace tutorial;

int main(int argc, char *argv[])
{
Info *pinfo = new Info();
pinfo->set_name("testname");
pinfo->set_age(120);
cout<<"info.name="<<pinfo->name()<<", age="<<pinfo->age()<<endl;

delete pinfo;
return 0;
}
