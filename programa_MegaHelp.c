#pragma config(Sensor, S2,     ,               sensorEV3_Infravermelho,modeEV3Proximidade_Proximidade)
void elevador(){
	setMotorSpeed(MotorA, 30);
	wait1Msec(12000);
}
void gancho(){
	setMotorSpeed(MotorB, 100);
	wait1Msec(400);
}
void esteira(){
		setMotorSpeed(MotorC, 30);
	wait1Msec(10000);
}

task main(){
	while(true){
		if(SensorValue(S2)<10){
			elevador();
			chute();
			esteira();
		}
	}
	
}
