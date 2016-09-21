#include "myqtimer.h"

MyQtimer::MyQtimer()
{
periodo = 1000;
}

void MyQtimer::start(int num)
{
    stopp=false;
    this->periodo = num;
    QThread::start();
}

void MyQtimer::stop()
{
  stopp = true;
}

bool MyQtimer::isActive()
{
  if(stopp==true){
    return false;
  }
  else
    return true;  
}

void MyQtimer::run()
{
  stopp = false;
  while(true)
{
    if(!stopp)
    {
      emit timeout();
    }
    usleep(periodo);
}

}