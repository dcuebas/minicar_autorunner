#include <ros/ros.h>
#include <ros_autorunner/ros_autorunner.h>

// Include subscribe message type
#include <autoware_msgs/LaneArray.h>
#include <autoware_msgs/Lane.h>
#include <visualization_msgs/MarkerArray.h>

#define TOTAL_STEP_NUM 5 // Need to change when total step number is changed

class WfSimAutorunner : public AutorunnerBase{
private:    
    ros::NodeHandle     nh_;
    ROSAutorunner        ros_autorunner_;
private:
    virtual void register_subscribers();
private:
    // CALLBACKS FOR CHECK
    void lane_waypoints_array_cb(const autoware_msgs::LaneArray& msg);
    void local_trajectories_cb(const autoware_msgs::LaneArray& msg);
    void behavior_state_cb(const visualization_msgs::MarkerArray& msg);
public:
    Sub_v               sub_v_;
public:
    WfSimAutorunner() {}
    WfSimAutorunner(ros::NodeHandle nh) : nh_(nh){}
    virtual void Run();
};