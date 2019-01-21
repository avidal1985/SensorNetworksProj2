#include "mbed.h"
#include "rtos.h"
#include "SerialGPS.h"


Thread threadGPS(osPriorityNormal, 2048); // 1K stack size

SerialGPS GPS(PA_9,PA_10,9600);

int numero_mensajes_leidos;
int lock;
int sats = 0;
float latitude = 0.0;
float longitude = 0.0;
float gpsAlt = 0.0;
float gpsTime = 0;
int h, hour, min, sec;
float hours, minutes, seconds;




void GPS_thread();

void GPS_thread() {

		while (1) {

			if (GPS.sample()){
			
					longitude=GPS.longitude;
					latitude=GPS.latitude;
					sats=GPS.sats;
					gpsTime=GPS.time;		
					hours=floor(gpsTime/10000);
					
					hour=(int)hours;
					h=hour+1;
				
					minutes=floor(gpsTime/-100);
					minutes=((hours*100)+minutes);
					min=((-1)*(int)minutes)-1;

				seconds=floor(gpsTime-(hour*10000));
				seconds=(seconds-(min*100));
				sec=(int)seconds;
					
					gpsAlt=GPS.alt;
				
				}
			
				Thread::wait(200);
    }
}





