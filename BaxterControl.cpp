
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
#include <iomanip>  
#include <fstream> 
#include <sstream>
#include <string> 
#include<windows.h>

extern "C" {
    #include "extApi.h"
}

int main(int argc,char* argv[])
{
	int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
	int clientID1 = simxStart((simxChar*)"127.0.0.1", 19998, true, true, 2000, 5);
	if (clientID != -1 || clientID1 != -1)
	{
		printf("Connected to remote API server\n");

		int Baxter_rightArm_joint1;
		int Baxter_rightArm_joint2;
		int Baxter_rightArm_joint3;
		int Baxter_rightArm_joint4;
		int Baxter_rightArm_joint5;
		int Baxter_rightArm_joint6;
		int Baxter_rightArm_joint7;

		int Baxter_leftArm_joint1;
		int Baxter_leftArm_joint2;
		int Baxter_leftArm_joint3;
		int Baxter_leftArm_joint4;
		int Baxter_leftArm_joint5;
		int Baxter_leftArm_joint6;
		int Baxter_leftArm_joint7;

		simxGetObjectHandle(clientID, "Baxter_rightArm_joint1", &Baxter_rightArm_joint1, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint2", &Baxter_rightArm_joint2, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint3", &Baxter_rightArm_joint3, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint4", &Baxter_rightArm_joint4, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint5", &Baxter_rightArm_joint5, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint6", &Baxter_rightArm_joint6, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID, "Baxter_rightArm_joint7", &Baxter_rightArm_joint7, simx_opmode_oneshot_wait);

		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint1", &Baxter_leftArm_joint1, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint2", &Baxter_leftArm_joint2, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint3", &Baxter_leftArm_joint3, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint4", &Baxter_leftArm_joint4, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint5", &Baxter_leftArm_joint5, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint6", &Baxter_leftArm_joint6, simx_opmode_oneshot_wait);
		simxGetObjectHandle(clientID1, "Baxter_leftArm_joint7", &Baxter_leftArm_joint7, simx_opmode_oneshot_wait);

		std::ifstream fin("angle.txt", std::ios::in);
		char line[1024] = { 0 };
		float x1;
		float x2;
		float x3;
		float x4;
		float x5;
		float x6;
		float x7;
	
		
			while (simxGetConnectionId(clientID) != -1 || simxGetConnectionId(clientID1) != -1)
			{
				while (fin.getline(line, sizeof(line)))
				{
					std::stringstream word(line);
					word >> x1;
					word >> x2;
					word >> x3;
					word >> x4;
					word >> x5;
					word >> x6;
					word >> x7;
				//printf("chuanshu");
				// default settings for baxter robot.

				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint1, x1, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint2, x2, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint3, x3, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint4, x4, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint5, x5, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint6, x6, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID, Baxter_rightArm_joint7, x7, simx_opmode_oneshot);

				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint1, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint2, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint3, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint4, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint5, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint6, 0, simx_opmode_oneshot);
				simxSetJointTargetPosition(clientID1, Baxter_leftArm_joint7, 0, simx_opmode_oneshot);
				std::cout << "x1: " << x1;
				Sleep(200);
			}
		}
		fin.clear();
		fin.close();

		
			
   }
	return(0);
}

