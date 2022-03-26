#include "Drive.h"
#include <fmt/core.h>
#include <iostream>
#include <string>

//define the xbox controller.
const frc::XboxController m_controller{CONTROLLER};
bool sol1tog = 1;
bool sol2tog = 1;
bool apressed = false;
bool bpressed = false;
bool xpressed = false;

Drive::Drive() {
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
        if(!bpressed){
            m_intake.Set(0.75);
            bpressed = true;
        }
    }
    else if (bpressed){
        m_intake.Set(0);
        bpressed = false;
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
            apressed = true;
        }
    } else if(apressed){
        apressed = false;
    }
}

//toggle solenoid group 2 if button X is pressed.
void Drive::DSolenoid2Toggle() {
    if(m_controller.GetXButton()) {
        if(!xpressed){
            sol2tog = !sol2tog;
            if(sol1tog) {
                DoublePCM2.Set(frc::DoubleSolenoid::Value::kForward);
            } else {
                DoublePCM2.Set(frc::DoubleSolenoid::Value::kReverse);
            }
            xpressed = true;
        }
    } else if(xpressed){
        xpressed = false;
    }
}

void Drive::Autonomous() {
    
}