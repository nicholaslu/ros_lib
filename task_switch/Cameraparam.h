#ifndef _ROS_task_switch_Cameraparam_h
#define _ROS_task_switch_Cameraparam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace task_switch
{

  class Cameraparam : public ros::Msg
  {
    public:
      typedef float _radius_type;
      _radius_type radius;
      typedef float _lam_type;
      _lam_type lam;
      typedef float _phi_type;
      _phi_type phi;

    Cameraparam():
      radius(0),
      lam(0),
      phi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->lam);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lam));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi));
     return offset;
    }

    const char * getType(){ return "task_switch/Cameraparam"; };
    const char * getMD5(){ return "ce7e66b2d98c1ed321281e9496a59d9f"; };

  };

}
#endif