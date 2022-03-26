#include "Drive.h"
#include <fmt/core.h>
#include <iostream>
#include <string>

//define the xbox controller.
const frc::XboxController m_controller{CONTROLLER};
bool sol1tog;
bool apressed;
units::second_t startTime;

Drive::Drive() {
    startTime = m_timer.GetFPGATimestamp();

    sol1tog = 1;
    apressed  = false;
    //inverse one side of the drivetrain.
    m_left.SetInverted(true);
    //enable compressor.
    pcmCompressor.Disable();
    pcmCompressor.EnableDigital();
    //set solenoid to false.
    DoublePCM1.Set(frc::DoubleSolenoid::Value::kOff);
    DoublePCM1.Set(frc::DoubleSolenoid::Value::kForward);

    //left motors ramp up
    m_frontLeft.ConfigOpenloopRamp(.5);
    m_rearLeft.ConfigOpenloopRamp(.5);

    //left motors ramp down
    m_frontLeft.ConfigClosedloopRamp(0);
    m_rearLeft.ConfigClosedloopRamp(0);

    //right motors ramp up
    m_frontRight.ConfigOpenloopRamp(.5);
    m_rearRight.ConfigOpenloopRamp(.5);

    //right motors ramp down
    m_frontRight.ConfigClosedloopRamp(0);
    m_rearRight.ConfigClosedloopRamp(0);
}

//arcade drive, left stick forward/backward right stick left/right.
void Drive::TuxDrive() {
    m_drivetrain.ArcadeDrive(-m_controller.GetLeftY(), -m_controller.GetRightX());
    DSolenoid1Toggle();
    Intake();
}

//the intake.
void Drive::Intake() { 
    if(m_controller.GetBButton()){
        m_intake.Set(0.75);
    }
    else{
        m_intake.Set(0);
    }
}

//toggle solenoid group 1 if button A is pressed.
void Drive::DSolenoid1Toggle() {
    if(m_controller.GetAButton()) {
        if(!apressed){
            sol1tog = !sol1tog;
            if(sol1tog) {
                DoublePCM1.Set(frc::DoubleSolenoid::Value::kForward);
            } else {
                DoublePCM1.Set(frc::DoubleSolenoid::Value::kReverse);
            }
        }
        apressed = true;
    } else {
        apressed = false;
    }
}

void Drive::Autonomous() {
    if(m_timer.GetFPGATimestamp() - startTime < (units::second_t)2) {
        m_drivetrain.ArcadeDrive(-1.0, 0.0);
    } else {
        m_drivetrain.ArcadeDrive(0.0, 0.0);
    }
}