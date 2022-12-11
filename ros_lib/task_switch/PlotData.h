#ifndef _ROS_task_switch_PlotData_h
#define _ROS_task_switch_PlotData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"

namespace task_switch
{

  class PlotData : public ros::Msg
  {
    public:
      uint32_t robot_num_length;
      typedef int64_t _robot_num_type;
      _robot_num_type st_robot_num;
      _robot_num_type * robot_num;
      typedef float _agent_radius_type;
      _agent_radius_type agent_radius;
      typedef geometry_msgs::PoseArray _obstacle_positions_type;
      _obstacle_positions_type obstacle_positions;
      typedef geometry_msgs::Pose _reference_position_type;
      _reference_position_type reference_position;
      uint32_t obstacle_xwidth_length;
      typedef float _obstacle_xwidth_type;
      _obstacle_xwidth_type st_obstacle_xwidth;
      _obstacle_xwidth_type * obstacle_xwidth;
      uint32_t obstacle_ywidth_length;
      typedef float _obstacle_ywidth_type;
      _obstacle_ywidth_type st_obstacle_ywidth;
      _obstacle_ywidth_type * obstacle_ywidth;

    PlotData():
      robot_num_length(0), robot_num(NULL),
      agent_radius(0),
      obstacle_positions(),
      reference_position(),
      obstacle_xwidth_length(0), obstacle_xwidth(NULL),
      obstacle_ywidth_length(0), obstacle_ywidth(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->robot_num_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robot_num_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robot_num_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robot_num_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_num_length);
      for( uint32_t i = 0; i < robot_num_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_robot_numi;
      u_robot_numi.real = this->robot_num[i];
      *(outbuffer + offset + 0) = (u_robot_numi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_robot_numi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_robot_numi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_robot_numi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_robot_numi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_robot_numi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_robot_numi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_robot_numi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->robot_num[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->agent_radius);
      offset += this->obstacle_positions.serialize(outbuffer + offset);
      offset += this->reference_position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->obstacle_xwidth_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacle_xwidth_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacle_xwidth_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacle_xwidth_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacle_xwidth_length);
      for( uint32_t i = 0; i < obstacle_xwidth_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->obstacle_xwidth[i]);
      }
      *(outbuffer + offset + 0) = (this->obstacle_ywidth_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacle_ywidth_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacle_ywidth_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacle_ywidth_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacle_ywidth_length);
      for( uint32_t i = 0; i < obstacle_ywidth_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->obstacle_ywidth[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t robot_num_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robot_num_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robot_num_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robot_num_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robot_num_length);
      if(robot_num_lengthT > robot_num_length)
        this->robot_num = (int64_t*)realloc(this->robot_num, robot_num_lengthT * sizeof(int64_t));
      robot_num_length = robot_num_lengthT;
      for( uint32_t i = 0; i < robot_num_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_robot_num;
      u_st_robot_num.base = 0;
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_robot_num.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_robot_num = u_st_robot_num.real;
      offset += sizeof(this->st_robot_num);
        memcpy( &(this->robot_num[i]), &(this->st_robot_num), sizeof(int64_t));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->agent_radius));
      offset += this->obstacle_positions.deserialize(inbuffer + offset);
      offset += this->reference_position.deserialize(inbuffer + offset);
      uint32_t obstacle_xwidth_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacle_xwidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacle_xwidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacle_xwidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacle_xwidth_length);
      if(obstacle_xwidth_lengthT > obstacle_xwidth_length)
        this->obstacle_xwidth = (float*)realloc(this->obstacle_xwidth, obstacle_xwidth_lengthT * sizeof(float));
      obstacle_xwidth_length = obstacle_xwidth_lengthT;
      for( uint32_t i = 0; i < obstacle_xwidth_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_obstacle_xwidth));
        memcpy( &(this->obstacle_xwidth[i]), &(this->st_obstacle_xwidth), sizeof(float));
      }
      uint32_t obstacle_ywidth_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacle_ywidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacle_ywidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacle_ywidth_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacle_ywidth_length);
      if(obstacle_ywidth_lengthT > obstacle_ywidth_length)
        this->obstacle_ywidth = (float*)realloc(this->obstacle_ywidth, obstacle_ywidth_lengthT * sizeof(float));
      obstacle_ywidth_length = obstacle_ywidth_lengthT;
      for( uint32_t i = 0; i < obstacle_ywidth_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_obstacle_ywidth));
        memcpy( &(this->obstacle_ywidth[i]), &(this->st_obstacle_ywidth), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "task_switch/PlotData"; };
    const char * getMD5(){ return "1b72a881854cbf8df2bebb624465074d"; };

  };

}
#endif