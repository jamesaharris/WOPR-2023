#include "Drivetrain.h"
#include <fmt/core.h>

//define the xbox controller.
const frc::XboxController m_controller{CONTROLLER};

Drivetrain::Drivetrain() {
    //inverse one side of the drivetrain.
    m_left.SetInverted(true);
    pcmCompressor.EnableDigital();
    pcmCompressor.Disable();
}

//arcade drive, left stick forward/backward right stick left/right.
void Drivetrain::TuxDrive() {
    m_drivetrain.ArcadeDrive(-m_controller.GetLeftY(), -m_controller.GetRightX());
    if(m_controller.GetAButton()) {
        pcmCompressor.EnableDigital();
    } else {
        pcmCompressor.Disable();
    }
}

void Drivetrain::Intake(){
    m_intake.Set(0.75);
}