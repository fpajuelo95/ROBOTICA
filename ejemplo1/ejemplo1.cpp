#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
	connect(&reloj, SIGNAL(timeout()), this, SLOT(recibirSenial()));
	reloj.start(500);
	lcdNumber->display(lcdNumber->intValue()+1);
	
	

}


ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
	
	if(reloj.isActive()){
	  
	reloj.stop();
	
	}else{
	  
	  reloj.start(500);
	  
	}
}

void ejemplo1::recibirSenial()
{
      qDebug() << "RECIBIDA";
     
  
}






