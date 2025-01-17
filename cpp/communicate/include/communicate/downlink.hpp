#ifndef DOWNLINK_HPP_
#define DOWNLINK_HPP_

#include "communicate/uplink.hpp"
#include <cmath>
#include <string>
#include <vector>

class Downlink {
public:
  Downlink(Uplink *uplink);

  /**
   * @brief 订阅小云台控制话题回调函数
   */
  void PTZCB(const std::vector<float> &msg);

  /**
   * @brief 订阅大云台控制话题回调函数
   */
  void MainPTZCB(const std::vector<float> &msg);

  /**
   * @brief 订阅底盘速度控制话题回调函数
   */
  void ChassisVelCB(const std::vector<float> &msg);

  /**
   * @brief 订阅比赛交互控制话题回调函数
   */
  void InteractionCB(const std::vector<int> &msg);

  /**
   * @brief 订阅车体模块控制话题回调函数
   */
  void MoudleCB(const std::vector<int> &msg);

  /**
   * @brief 订阅发射状态量话题回调函数
   */
  void ShootStautsCB(const std::vector<int> &msg);

private:
  Uplink *uplink_;
  bool debug; // 是否开启调试模式

  std::string PTZSubTopic;         // 小云台控制订阅话题
  std::string MainPTZSubTopic;     // 大云台控制订阅话题
  std::string ChassisVelSubTopic;  // 底盘控制订阅话题
  std::string InteractionSubTopic; // 比赛交互控制订阅话题
  std::string MoudleSubTopic;      // 车体模块控制订阅话题
  std::string ShootStautsSubTopic; // 发射状态量订阅话题
};
#endif
