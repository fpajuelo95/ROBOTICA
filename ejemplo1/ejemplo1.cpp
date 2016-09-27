#include "ejemplo1.h"
#include "myqtimer.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	x=1000;
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
	connect(&reloj, SIGNAL(timeout()), this, SLOT(recibirSenial()));
	connect(horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(reiniciarReloj()));
	reloj.start(x);
	
	
	

}


ejemplo1::~ejemplo1()
{
}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
	
	if(reloj.isActive()){
	  
	reloj.stop();
	
	}else{
	  
	  x = horizontalSlider->value();
	  reloj.start(x);
	  
	}
}

void ejemplo1::recibirSenial()
{
      lcdNumber->display(lcdNumber->intValue()+1);
      qDebug() << "RECIBIDA";
     
  
}

void ejemplo1::reiniciarReloj(){
  if(reloj.isActive()){
    x = horizontalSlider->value();
    reloj.start(x);
  }
}






