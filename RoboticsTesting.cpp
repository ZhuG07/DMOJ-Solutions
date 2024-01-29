#include <bits/stdc++.h>
#include <thread>
using namespace std;

// Set motor variables
double motorFL;
double motorBL;
double motorFR;
double motorBR;

// Initializing encoder positions
int leftPos1;
int leftPos2;
int rightPos1;
int rightPos2;

double integralSum = 0;
double Kp = 0.05;
double Ki = 0;
double Kd = 0.01;
double Kf = 0.2;

double PIDControl(double setPosition, double currentPosition);
void Drive(int TargetPositionMotorFL, int TargetPositionMotorBL, int TargetPositionMotorFR,
           int TargetPositionMotorBR);

double lastError = 0;
int main()
{

    // Reverse left side motors
    // motorFL.setDirection(DcMotorSimple.Direction.REVERSE);
    // motorBL.setDirection(DcMotorSimple.Direction.REVERSE);

    // Initialize the positions to zero, since the motor has not moved yet
    leftPos1 = 0;
    leftPos2 = 0;
    rightPos1 = 0;
    rightPos2 = 0;

    // can now set drive distance because of the function below; now we just need to
    // input the distance
    // can also control the direction using the mecanum drivetrain directions here:
    // https://gm0.org/en/latest/docs/software/tutorials/mecanum-drive.html

    // Starting position with robot right side
    while (motorFL <= 2380)
    {
       // std::this_thread::sleep_for(500ms);
        Drive(50, 50, 50, 50);
    }

    // PIDDrive(250, 250, 250, 250);
}

// these parameters are distance in CM

void Drive(int TargetPositionMotorFL, int TargetPositionMotorBL, int TargetPositionMotorFR,
           int TargetPositionMotorBR)
{

    // this is in terms of cm
    TargetPositionMotorFL = (int)(47.63 * TargetPositionMotorFL);
    TargetPositionMotorBL = (int)(47.63 * TargetPositionMotorBL);
    TargetPositionMotorFR = (int)(47.63 * TargetPositionMotorFR);
    TargetPositionMotorBR = (int)(47.63 * TargetPositionMotorBR);
    cout << "Target Position: " << TargetPositionMotorFL << "\n";

     cout<<"Motor Position: "<<motorFL<<"\n";
    double temp = (PIDControl(TargetPositionMotorFL, motorFL) / 5);
    motorFL += temp;
   
    motorBL += (PIDControl(TargetPositionMotorBL, motorBL) / 5);
    motorFR += (PIDControl(TargetPositionMotorFR, motorFR) / 5);
    motorBR += (PIDControl(TargetPositionMotorBR, motorBR) / 5);

    cout << "Associated Increment: " << temp << "\n";
    cout<<"\n";
    // Wait until all motors reach the target position
    /*while (opModeIsActive() && motorFL.isBusy() && motorFR.isBusy() && motorBL.isBusy() && motorBR.isBusy()) {
    }
    motorFL.setPower(0);
    motorFR.setPower(0);
    motorBL.setPower(0);
    motorBR.setPower(0);*/
}

// calculates the power which the motor should be set at.
double PIDControl(double setPosition, double currentPosition)
{
    double error = setPosition - currentPosition;
    integralSum += error * 0.1;
    double derivative = (error - lastError) / 0.1;

    lastError = error;

    return (error * Kp) + (derivative * Kd) + (integralSum * Ki);
}
