#include "Drivetrain.h"
#include <fmt/core.h>

frc::XboxController m_controller{CONTROLLER};

Drivetrain::Drivetrain() {
    m_left.SetInverted(true);
}

void Drivetrain::TuxDrive() {
    m_drivetrain.ArcadeDrive(-m_controller.GetLeftY(), -m_controller.GetRightX());
}