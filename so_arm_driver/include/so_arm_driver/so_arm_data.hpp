#ifndef SO_ARM_CONSTS_HPP
#define SO_ARM_CONSTS_HPP

#include "rclcpp/rclcpp.hpp"

namespace SOArm {

static constexpr size_t JOINT_NUMBER = 6;
using JointArray = std::array<double, JOINT_NUMBER>;
using JointIntArray = std::array<double, JOINT_NUMBER>;

struct Target {
    JointArray pos;
    JointArray vel;
    JointArray acc;
};

struct State {
    JointArray pos;
    JointArray vel;
    JointArray acc;
    JointIntArray encoder;
    JointIntArray load;
    JointIntArray voltage;
    JointIntArray temperature;
};

struct JointLimit {
    double min;
    double max;
};


struct Limits {
    JointLimit angle;
    JointLimit encoder;
};
using JointLimitArray = std::array<Limits, JOINT_NUMBER>;

// Convert consts in the format y = a*x + b
struct ConvertConst {
    double slope; //  constant
    double intercept; // intercep
};
using JointConsts = std::array<ConvertConst, JOINT_NUMBER>;

}  // namespace SOArm
#endif  // SO_ARM_CONSTS_HPP
