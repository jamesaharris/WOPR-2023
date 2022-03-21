#include "Drivetrain.h"
#include <fmt/core.h>

//define the xbox controller.
const frc::XboxController m_controller{CONTROLLER};

Drivetrain::Drivetrain() {
    //inverse one side of the drivetrain.
    m_left.SetInverted(true);
}

//arcade drive, left stick forward/backward right stick left/right.
void Drivetrain::TuxDrive() {
    m_drivetrain.ArcadeDrive(-m_controller.GetLeftY(), -m_controller.GetRightX());
}

void Drivetrain::Intake(){
    m_drivetrain.m_intake.Set(0.75);
}