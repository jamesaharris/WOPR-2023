#include "Drivetrain.h"
#include <fmt/core.h>

//define the xbox controller.
const frc::XboxController m_controller{CONTROLLER};
bool sol1tog = 0;
bool apressed = false;

Drivetrain::Drivetrain() {
    //inverse one side of the drivetrain.
    m_left.SetInverted(true);
    pcmCompressor.EnableDigital();
    pcmCompressor.Disable();
    pcmCompressor.EnableDigital();
    DoublePCM1.Set(frc::DoubleSolenoid::Value::kOff);
}

//arcade drive, left stick forward/backward right stick left/right.
void Drivetrain::TuxDrive() {
    m_drivetrain.ArcadeDrive(-m_controller.GetLeftY(), -m_controller.GetRightX());
    //checks to see if the a button has been pressed and toggles Solenoid group 1.
    if(m_controller.GetAButton()) {
        if(!apressed){
            DSolenoid1Toggle();
        }
        apressed = true;
    } else {
        apressed = false;
    }
}

void Drivetrain::Intake() {
    m_intake.Set(0.75);
}

//toggle solenoid group 1.
void Drivetrain::DSolenoid1Toggle() {
    sol1tog = !sol1tog;
    if(sol1tog) {
        DoublePCM1.Set(frc::DoubleSolenoid::Value::kForward);
    } else {
        DoublePCM1.Set(frc::DoubleSolenoid::Value::kReverse);
    }
}