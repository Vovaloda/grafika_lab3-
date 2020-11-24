#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>

double f1(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3;
}

double f2(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3; 
}

double f3(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}

double f4(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}



double t_max = 0;

void Render(double delta_time)
{

	t_max += delta_time / 5; 

	if (t_max > 1) t_max = 0;


	double P1[] = { 0,0,0 };
	double P2[] = { 3,-6,7 };
	double P3[] = { 5,-6,-5 };
	double P4[] = { 8,-1,-3 };
	double P[3];


	glBegin(GL_LINE_STRIP);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glVertex3dv(P4);
	glEnd();

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		P[0] = f1(P1[0], P2[0], P3[0], P4[0], t);
		P[1] = f1(P1[1], P2[1], P3[1], P4[1], t);
		P[2] = f1(P1[2], P2[2], P3[2], P4[2], t);
		glVertex3dv(P);
	}

	glEnd();

	
	glColor3d(1, 0, 1);
	glLineWidth(1); 


	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(P);
	glEnd();

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P1);
	glVertex3dv(P2);
	glVertex3dv(P3);
	glEnd();

	///
	
	double P50[] = { 1,1,1 };
	double P60[] = { 3,3,3 };
	double P70[] = { 3,6,3 };
	double P80[] = { -5,6,3 };
	double PP[3];


	glBegin(GL_LINE_STRIP);
	glVertex3dv(P50);
	glVertex3dv(P60);
	glVertex3dv(P70);
	glVertex3dv(P80);
	glEnd();

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PP[0] = f2(P50[0], P60[0], P70[0], P80[0], t);
		PP[1] = f2(P50[1], P60[1], P70[1], P80[1], t);
		PP[2] = f2(P50[2], P60[2], P70[2], P80[2], t);
		glVertex3dv(PP);
	}

	glEnd();


	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(P50);
	glVertex3dv(P60);
	glVertex3dv(P70);
	glEnd();

	///

	double r1[] = { 0,4,0 }; 
	double r2[] = { 0,2,6 };

	double r3[] = { 4,6,3 };
	double r4[] = { 8,8,8 };

	double P5[] = { 0,4,0 };;
	double P6[] = { 4,6,3 };

	double R1[] = { 0,-2,6 };
	double R2[] = { 4, 2, 5 };

	double PPP[3];

	glBegin(GL_LINES);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();


	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PPP[0] = f3(P5[0], P6[0], R1[0], R2[0], t);
		PPP[1] = f3(P5[1], P6[1], R1[1], R2[1], t);
		PPP[2] = f3(P5[2], P6[2], R1[2], R2[2], t);
		glVertex3dv(PPP);  
	}
	glEnd();

	
	glColor3d(1, 0, 1);
	glLineWidth(1);  

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();


	///

	double r5[] = { 3,2,3 };
	double r6[] = { 1,0,1 };

	double r7[] = { 5,3,3 };
	double r8[] = { 8,2,4 };

	double P7[] = { 3,2,3 };;
	double P8[] = { 5,3,3 };

	double R3[] = { -2, -2, -2 };
	double R4[] = { 3, -1, 1 };

	double PPPP[3];

	glBegin(GL_LINES);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();


	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PPPP[0] = f4(P7[0], P8[0], R3[0], R4[0], t);
		PPPP[1] = f4(P7[1], P8[1], R3[1], R4[1], t);
		PPPP[2] = f4(P7[2], P8[2], R3[2], R4[2], t);
		glVertex3dv(PPPP);
	}
	glEnd();


	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();


	glLineWidth(1);

}