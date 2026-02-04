/*
 * sensors.c
 *
 *  Created on: Sep 25, 2024
 *      Author: nidul
 */

#include "sensors.h"
#include "adc.h"
#include "math.h"

//double kxlf;
//double qlf = 0.125; //process noise covariance
//double rlf = 25; //measurement noise covariance
//double plf = 500; //estimation error covariance
//double klf; //kalman gain
//
//double kxrf; //value
//double qrf = 0.125; //process noise covariance
//double rrf = 25; //measurement noise covariance
//double prf = 500; //estimation error covariance
//double krf; //kalman gain

double avg_freq = 100.0;

float disLF, disRF, disL, disR;

//double getFilteredValueLF(double measurement) {
//	/* Updates and gets the current measurement value */
//	//prediction update
//	//omit x = x
//	plf = plf + qlf;
//	//measurement update
//	klf = plf / (plf + rlf);
//	kxlf = kxlf + klf * (measurement - kxlf);
//	plf = (1 - klf) * plf;
//
//	return kxlf;
//}
//
//double getFilteredValueRF(double measurement) {
//	/* Updates and gets the current measurement value */
//	//prediction update
//	//omit x = x
//	prf = prf + qrf;
//
//	//measurement update
//	krf = prf / (prf + rrf);
//	kxrf = kxrf + krf * (measurement - kxrf);
//	prf = (1 - krf) * prf;
//
//	return kxrf;
//}

double sensorLF() {
	double ls = 0;
	for (int i = 0; i < avg_freq; ++i) {
		ls = ls + read_DL_Sensor / 3000.0;
	}
	ls = ls / avg_freq;
	double dis = (
			577.8457 * pow(ls, 6) - 2978.2481 * pow(ls, 5)
					+ 6112.9197 * pow(ls, 4) - 6520.3361 * pow(ls, 3)
					+ 3890.0716 * pow(ls, 2) - 1312.1028 * ls + 237.7826);
	if (dis > 150) {
		dis = 150.0;
	}
	return dis;
//	return read_DL_Sensor;

}

double sensorRF() {
	double ls = 0;
	for (int i = 0; i < avg_freq; ++i) {
		ls = ls + read_RF_Sensor / 3000.0;
	}
	ls = ls / avg_freq;
	double dis = (
			-745.8339 * pow(ls, 6) + 1174.5013 * pow(ls, 5)
					+ 1889.5711 * pow(ls, 4) - 5713.97013 * pow(ls, 3)
					+ 5144.2669 * pow(ls, 2) - 2122.4670 * ls + 392.7954);
	if (dis > 150) {
		dis = 150.0;
	}
	return dis;
//	return read_RF_Sensor;

}

double sensorL() {
	double ls = 0;
	for (int i = 0; i < avg_freq; ++i) {
		ls = ls + read_LF_Sensor / 3000.0;
	}
	ls = ls / avg_freq;
	double dis = (1088.5843* pow(ls, 6) - 4492.5206 * pow(ls, 5)
			+ 7824.2323 * pow(ls, 4) - 7516.7340 * pow(ls, 3)
			+ 4294.4290 * pow(ls, 2) - 1456.5525 * ls + 267.6718);

	if (dis > 160) {
		dis = 160.0;
	}
	return dis;
//	return read_DL_Sensor;

}

double sensorR() {
	double ls = 0;
	for (int i = 0; i < avg_freq; ++i) {
		ls = ls + read_DR_Sensor / 3000.0;
	}
	ls = ls / avg_freq;
	double dis = (1510.6676 * pow(ls, 6) - 5217.1136 * pow(ls, 5)
			+ 7940.0245 * pow(ls, 4) - 7123.6724 * pow(ls, 3) + 4041.1574 * pow(ls, 2) - 1401.0866 * ls +259.8527);

	if (dis > 160) {
		dis = 160.0;
	}
	return dis;
//	return read_RF_Sensor;

}

void updateIRValues() {
//	for (int i = 0; i < 10; ++i) {
//		sensorLF();
//		sensorRF();
//	}
	disLF = (float) sensorLF();
	disRF = (float) sensorRF();
	disL = (float) sensorL();
	disR = (float) sensorR();

}

bool startRun() {
	double activation_threshold = 70.0;
	if (sensorLF() < activation_threshold) {
		HAL_Delay(2000);
		return true;

	}

	return false;
}
