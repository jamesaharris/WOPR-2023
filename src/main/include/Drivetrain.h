#include "Constants.h"
#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/Spark.h>

class Drivetrain {
    public:
        Drivetrain();
        void TuxDrive();

    private:
        frc::Spark m_frontLeft{FRONT_LEFT_MOTOR};
        frc::Spark m_rearLeft{BACK_LEFT_MOTOR};
        frc::MotorControllerGroup m_left{m_frontLeft, m_rearLeft};

        frc::Spark m_frontRight{FRONT_RIGHT_MOTOR};
        frc::Spark m_rearRight{BACK_RIGHT_MOTOR};
        frc::MotorControllerGroup m_right{m_frontRight, m_rearRight};

        frc::DifferentialDrive m_drivetrain{m_left, m_right};
};