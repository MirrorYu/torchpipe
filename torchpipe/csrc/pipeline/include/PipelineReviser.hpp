// Copyright 2021-2024 NetEase.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <unordered_map>
#include "Backend.hpp"
#include "dict.hpp"

namespace ipipe {
/**
 * @brief 获取当前解释器，并将任务转发到解释器执行。
 *
 */
class PipelineReviser : public Backend {
 public:
  /**
   * @brief
   *
   * @param PipelineReviser::backend 节点名。将任务转发到此节点执行。
   */
  bool init(const std::unordered_map<std::string, std::string>& config, dict dict_config) override;
  /**
   * @brief 等同在python端更新节点名
   * `input.update({"node_name":PipelineReviser::backend }`
   * 后执行前向。
   *
   */
  void forward(const std::vector<dict>& inputs);
  /**
   *
   * @return UINT32_MAX
   */
  virtual uint32_t max() const { return UINT32_MAX; };

 private:
  Backend* pInterpreter;
  std::string node_name_;
};
}  // namespace ipipe