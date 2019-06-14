#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Infravermelho,modeEV3Proximidade_Proximidade)
#pragma config(Sensor, S3,     ,               sensorEV3_Infravermelho,modeEV3Proximidade_Proximidade)
#define NoventaGraus 2800;
#define preto 1;
#define azul 2;
#define verde 3;
#define amarelo 4;
#define vermelho 5;
#define branco 6;
#define marrom 7;
void andar(){

	if(SensorValue(S1)>vermelho && SensorValue(S4)>vermelho){
		setMotorSpeed(MotorA, -30);
		setMotorSpeed(MotorD, -30);
	}

	if(SensorValue(S1)<azul){
		setMotorSpeed(MotorA,-30);
		setMotorSpeed(MotorD,30);
	}
	if(SensorValue(S4)<azul){
		setMotorSpeed(MotorA,30);
		setMotorSpeed(MotorD,-30);
	}
}
void entrega(){
	while(SensorValue(S4)!=preto&&SensorValue(S1)!=preto){
		andar();
	}
	motor[motorB] = -50;
	wait1Msec(40000);
	setMotorSpeed(MotorA,30);
	setMotorSpeed(MotorD,30);
	wait1Msec(500);
	setMotorSpeed(MotorA,-30);
	setMotorSpeed(MotorD,-30);
	wait1Msec(500);
	return;

task main(){
	wait1Msec(25000);
	while(true){
		if(SensorValue(S3)<10){
			setMotorSpeed(MotorA, 30);
			setMotorSpeed(MotorD, 30);
			wait1Msec(1000);
			setMotorSpeed(MotorA, -30);
			setMotorSpeed(MotorD, 30);
			wait1Msec(NoventaGraus);
			break;
		}
	}
	while(true){
		andar();
		if(SensorValue(S4)==vermelho||SensorValue(S1)==vermelho){
			entrega();
			break;
		}
		
	}
return;	
}
