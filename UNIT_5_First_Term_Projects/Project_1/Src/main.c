/**
 ******************************************
 * @file           : main.c
 * @author         : Peter Moner
 * @processor      : ARM Cortex M3
 ******************************************/

#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Platform_Types.h"

#define Threshold_val 20

int main (){
	
	uint32 Pressure_value=0;
	
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(LOW);

	while (1)
	{
		Pressure_value = getPressureVal();
		if(Pressure_value >= Threshold_val)
		{
			Set_Alarm_actuator(HIGH);
			Delay(1000000);

		}
		
		else{
			Set_Alarm_actuator(LOW);
		}
	}

}
