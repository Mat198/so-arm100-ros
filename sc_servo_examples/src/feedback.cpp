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
	while(1){
		int Pos;
		int Speed;
		int Load;
		int Voltage;
		int Temper;
		int Move;
		int Current;
		//һ��ָ���������з���������������
		if(sc.FeedBack(1)!=-1){
			Pos = sc.ReadPos(-1);//-1��ʾ���������ݣ�������ͬ
			Speed = sc.ReadSpeed(-1);
			Load = sc.ReadLoad(-1);
			Voltage = sc.ReadVoltage(-1);
			Temper = sc.ReadTemper(-1);
			Move = sc.ReadMove(-1);
			Current = sc.ReadCurrent(-1);
			std::cout<<"pos = "<<Pos<<" ";
			std::cout<<"Speed = "<<Speed<<" ";
			std::cout<<"Load = "<<Load<<" ";
			std::cout<<"Voltage = "<<Voltage<<" ";
			std::cout<<"Temper = "<<Temper<<" ";
			std::cout<<"Move = "<<Move<<" ";
			std::cout<<"Current = "<<Current<<std::endl;
			usleep(10*1000);
			continue;
		}else{
			std::cout<<"read err"<<std::endl;
			sleep(1);
		}
		//һ��ָ���һ����������
		Pos = sc.ReadPos(1);
		if(Pos!=-1){
			std::cout<<"pos = "<<Pos<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read pos err"<<std::endl;
			sleep(1);
		}
		Voltage = sc.ReadVoltage(1);
		if(Voltage!=-1){
			std::cout<<"Voltage = "<<Voltage<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read Voltage err"<<std::endl;
			sleep(1);
		}

		Temper = sc.ReadTemper(1);
		if(Temper!=-1){
			std::cout<<"temperature = "<<Temper<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read temperature err"<<std::endl;
			sleep(1);
		}

		Speed = sc.ReadSpeed(1);
		if(Speed!=-1){
			std::cout<<"Speed = "<<Speed<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read Speed err"<<std::endl;
			sleep(1);
		}
  
		Load = sc.ReadLoad(1);
		if(Load!=-1){
			std::cout<<"Load = "<<Load<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read Load err"<<std::endl;
			sleep(1);
		}

		Current = sc.ReadCurrent(1);
		if(Current!=-1){
			std::cout<<"Current = "<<Current<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read Current err"<<std::endl;
			sleep(1);
		}

		Move = sc.ReadMove(1);
		if(Move!=-1){
			std::cout<<"Move = "<<Move<<std::endl;
			usleep(10*1000);
		}else{
			std::cout<<"read Move err"<<std::endl;
			sleep(1);
		}
	}
	sc.end();
	return 1;
}

