#include "Constants.h"
#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
//#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include "ctre/Phoenix.h"
//#include <frc/SpeedControllerGroup.h>

class Drive {
    public:
        Drive();
        void TuxDrive();
        void Intake();
        void DSolenoid1Toggle();
        void DSolenoid2Toggle();
        void Autonomous();

    private:
        //define intake motor
        WPI_TalonSRX m_intake{ROLLER_MOTOR};
        //define left motors and group them.
        WPI_TalonSRX m_frontLeft{FRONT_LEFT_MOTOR};
        WPI_TalonSRX m_rearLeft{BACK_LEFT_MOTOR};
        frc::MotorControllerGroup m_left{m_frontLeft, m_rearLeft};

        //define right motors and group them.
        WPI_TalonSRX m_frontRight{FRONT_RIGHT_MOTOR};
        WPI_TalonSRX m_rearRight{BACK_RIGHT_MOTOR};
        frc::MotorControllerGroup m_right{m_frontRight, m_rearRight};

        //create a differential drive using the two previously defined groups.
        frc::DifferentialDrive m_drivetrain{m_left, m_right};

        //define compressor and solenoid groups.
        frc::Compressor pcmCompressor{PNEUMATICS, frc::PneumaticsModuleType::CTREPCM};
        frc::DoubleSolenoid DoublePCM1{frc::PneumaticsModuleType::CTREPCM, 1, 2};
        frc::DoubleSolenoid DoublePCM2{frc::PneumaticsModuleType::CTREPCM, 0, 3};

        //define timer
        

};