#include <iostream>
#include "sc_servo/SCServo.hpp"

SCSCL sc;

int main(int argc, char **argv)
{
	if(argc<2){
        std::cout<<"argc error!"<<std::endl;
        return 0;
	}
	std::cout<<"serial:"<<argv[1]<<std::endl;
    if(!sc.begin(1000000, argv[1])){
        std::cout<<"Failed to init scscl motor!"<<std::endl;
        return 0;
    }
	// TODO: Change work mode when setting PWM mode
	// Warning: Take care of eeprom limits
	sc.PWMMode(1);
	std::cout<<"mode = "<<1<<std::endl;
	while(1){
		sc.WritePWM(1, 500);
		std::cout<<"pwm = "<<500<<std::endl;
		sleep(2);
		sc.WritePWM(1, 0);
		std::cout<<"pwm = "<<0<<std::endl;
		sleep(2);
		sc.WritePWM(1, -500);
		std::cout<<"pwm = "<<-500<<std::endl;
		sleep(2);
		sc.WritePWM(1,0);
		std::cout<<"pwm = "<<0<<std::endl;
		sleep(2);
	}
	sc.end();
	return 1;
}

